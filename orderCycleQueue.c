//
// 顺环队列的实现(数组实现)
// 这种方案要注意的是
// 1、队列满空的判断条件是什么
// 2、以及为什么会出现空、满无法区分?根本原因?
//  判别队列的状态,是根据front和rear的相对距离,这种相对距离,对于大小为N的数组,从0至(N-1),一共有N种情况
//  而队列装载的元素却可以有N+1种(从0到N)情况, 用N中相对距离,去区分N+1中情况,显然是做不到的
//  有两种解决方式:
// 1、使用额外的标记, size(队列中元素个数,若个数达到MaxSize则满,若个数为0为空,对应了增加和删除操作时候对size的修改)
//    或者tag(tag=1,最有一次操作为添加,tag=0,最后一次操作为删除)
// 2、仅使用n-1个数组空间(本例中就是这么做的)
// Created by 侯金鑫 on 16/5/23.
//

#include <stdlib.h>
#include <stdio.h>

#define MaxSize 3
typedef int ElementType;
//typedef struct {
//    int key;
//} ElementType;

typedef struct {
    ElementType data[MaxSize];
    int front; //记录队头元素位置
    int rear; //记录队尾元素位置
} Queue;

/**
 * 创建队列
 */
Queue *CreateQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

/**
 * 判断队列已满,
 * 顺坏队列不能仅根据front和rear的值是否相等来判断,因为不管是队列空和满时,都会有 front == rear,有两种方法可以用来判断队列是否已满
 * 1、采用其他的标志位来标识队列是否为空,例如queue中增加一个tag标识队列上一个操作。若上一个操作为入栈,tag=1,否则tag=0。若tag==1且
 * front==rear则队列满,若tag=0,且front==rear则队列空
 * 2、保留队列中的一个位置始终为空,若队头与队尾相差一个单元 ,即(rear + 1) % MaxSize == front,这时认为队列满。
 * 这列采用第二种方式
 */
int IsFullQ(Queue *q) {
    if ((q->rear + 1) % MaxSize == q->front % MaxSize)
        return 1;
    else
        return 0;
}

/**
 * 添加元素
 * 1、判断队列是否已满
 * 2、在队尾处添加元素
 * 3. rear++
 */
void AddQ(Queue *q, ElementType e) {
    if (IsFullQ(q)) {
        printf("队列已满\r\n");
        return;
    } else {
        q->data[q->rear % MaxSize] = e;
        q->rear++;
    }
}

/**
 * 判断队列是否为空,由于队列满的定义是队尾与队首元素相差一个单元,故当队列满时,rear != front 故当front==rear时,认为队列空
 */
int IsEmptyQ(Queue *q) {
    if (q->front == q->rear) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 删除元素并返回
 */
ElementType DeleteQ(Queue *q) {
    ElementType e;
    if (IsEmptyQ(q)) {
        printf("队列已空\r\n");
        e = -1;
    }
    else{
        e = q->data[q->front % MaxSize];
        q->front++;
    }
    return e;
}

/**
 * 调试时参考这几个参数
 * q->rear
 * q->front
 * IsFull(q)
 * q->front%MaxSize
 * (q->rear + 1) % MaxSize
 * isEmpty(q)
 */
int main() {
    Queue *q = CreateQueue();
    AddQ(q, 1);
    DeleteQ(q);
    AddQ(q, 2);
    DeleteQ(q);
    AddQ(q, 3);
    DeleteQ(q);
    AddQ(q, 4);
    DeleteQ(q);
    AddQ(q, 5);
    DeleteQ(q);
    AddQ(q, 6);
    DeleteQ(q);
    AddQ(q, 7);
    AddQ(q, 8);
//    printf("队列%s\r\n", IsFullQ(q) ? "满" : "未满");
}