// 队列的接口文件
// Created by 侯金鑫 on 16/5/24.
//

#ifndef QueueDef
#define QueueDef

#include "stack.h"

typedef struct QueueDef{
    Stack *in; //用于入队
    Stack *out;
    int size;
} Queue;

Queue *createQueue(int in_size, int out_size);
void *destory(Queue *queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
void *add(Queue *queue, void *element);
void *delete(Queue *queue);

#endif //QueueDef
