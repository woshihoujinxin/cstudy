//
// 两个栈实现的队列
// Created by 侯金鑫 on 16/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

Queue *createQueue(int in_size, int out_size) {
    //初始化队列
    Queue *queue = malloc(sizeof(Queue));
    //初始化队列中的两个栈一大一小
    queue->in = createStack(in_size); //in 较大的那个,用于入队
    queue->out = createStack(out_size); //out 较小的那个,用于维护未出队元素的顺序
    queue->size = 0;
    return queue;
};

void *destory(Queue *queue) {
    destroyStack(queue->in);
    destroyStack(queue->out);
    free(queue);
};

int isFull(Queue *queue) {
    return queue->size == queue->out->max_size + 1;
};

int isEmpty(Queue *queue) {
    return queue->size == 0;
};

/**
 * 入队列操作, 只需要将所有元素都压入in,若out不为空,为了保证出栈顺序要将out中弹出压入in
 */
void *add(Queue *queue, void *element) {
    if (isFull(queue)) {
        printf("队列已满\r\n");
        return NULL;
    }
    while (queue->out->top > 0) {
        push(queue->in, pop(queue->out));
    }
    queue->size++;
    return push(queue->in, element);
};

/**
 * 出队列操作, 将in栈中除栈底元素之外的所有元素都压入out栈,in中只留栈底元素,然后将栈底元素出栈则为队列的出队元素。
 * 设in的容量为m,元素个数为k(k∈[0,m]), out的容量为n。
 * 若k <= n + 1时, 除了栈底元素外的所有进入in的元素,都能成功被压入out中
 * 若k > n + 1 时, 有超过一个元素在m中,而且正常的出队顺序应该是栈底元素(FIFO)然后是上面的元素,显然用栈无法完成。
 * 故可以得知队列的最大容量(保证队列元素正常出入的容量)
 *
 */
void *delete(Queue *queue) {
    Stack *in = queue->in;
    Stack *out = queue->out;
    if (isEmpty(queue)) {
        printf("队列已空\r\n");
        return NULL;
    }
    while (queue->size <= out->max_size + 1 && in->top > 1) {//队列元素小于最大值且in中元素数大于1
        push(out, pop(in));//弹出in中的前若干项压入out只留栈底的一项
    }
    void *element = pop(in);//in中元素出栈
    queue->size--;
    if (queue->size > 0) //当队列为空的时候无需将out中元素压入
        push(in, pop(out));
    return element;
};