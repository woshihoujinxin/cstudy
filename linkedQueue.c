//
// 由链表实现的队列
// Created by 侯金鑫 on 16/5/23.
//

#include <stdlib.h>
#include <stdio.h>

#define Error -1
typedef int ElementType;

typedef struct Node{
    ElementType data;
    struct Node *next;
} QNode;

typedef struct {
    QNode *front; //队头节点
    QNode *rear; //队尾节点
} LinkedQueue;

/**
 * 创建队列
 */
LinkedQueue *CreateStackQueue() {
    LinkedQueue *q = malloc(sizeof(LinkedQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}


/**
 * 判断队列是否为空,队头为空,那么一定为空链表
 */
int IsEmptyQ(LinkedQueue *q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 添加元素
 * 1、创建新节点
 * 2、节点赋值
 * 3. 队尾节点指向新节点
 */
void AddQ(LinkedQueue *q, ElementType e) {
    QNode *node = malloc(sizeof(QNode));
    node->data = e;
    node->next = NULL;
    if (IsEmptyQ(q)) { //若链表为空
        q->front = node;
        q->rear = node;
    } else { //链表不空
        q->rear->next = node;
        q->rear = node;
    }
    return;
}

/**
 * 删除元素并返回
 */
ElementType DeleteQ(LinkedQueue *q) {
    ElementType e;
    QNode *frontNode;
    if (IsEmptyQ(q)) {
        printf("队列已空\r\n");
        e = Error;
    } else {
        frontNode = q->front;
        if (q->front == q->rear) { //只有一个元素
            q->front = q->rear = NULL;
        } else {
            q->front = frontNode->next; //front指向原front后继节点
        }
        e = frontNode->data; //获取数据
        free(frontNode); //释放内存
    }
    return e;
}

/**
 * 调试时参考这几个参数
 * q->rear
 * q->front
 * isEmpty(q)
 */
int main() {
    LinkedQueue *q = CreateStackQueue();
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