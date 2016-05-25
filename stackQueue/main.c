//
// 参考地址: http://www.muzixing.com/pages/2014/04/15/cyu-yan-liang-ge-zhan-shi-xian-dui-lie.html
// Created by 侯金鑫 on 16/5/24.
//
#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main() {
//    Stack *stack = createStack(10);
//    push(stack, (void *) 1);
//    push(stack, (void *) 2);
//    printf("出栈元素%d\r\n", (int) pop(stack));

    Queue *queue = createQueue(5, 2);
    printf("%s\r\n", isEmpty(queue) ? "栈空" : "栈不空");
    int i = 10;
    for (; !isFull(queue);) {
        add(queue, i);
        i += 10;
    }
    printf("%s\r\n", isFull(queue) ? "栈满" : "栈不满");
    printf("%d\r\n", (int) delete(queue));
    printf("%d\r\n", (int) delete(queue));
    printf("%d\r\n", (int) delete(queue));
    printf("%d\r\n", (int) delete(queue));

}