#include <stdio.h>
#include <stdlib.h>

/*!
 * 用链表实现的栈,叫做链栈
 * 链栈有一个头结点Head,要么为空 要么指向链表的第一个节点, head中不存储任何数据
 */
typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} LinkedStack;

/**
 * 初始化堆栈,返回头节点
 */
LinkedStack *CreateStack() {
    LinkedStack *s = malloc(sizeof(LinkedStack));
    s->next = NULL;
    return s;
}


/**
 * 判断栈S是否为空
 */
int IsEmpty(LinkedStack *s) {
    return s->next == NULL;
}

/**
 * 压栈
 * 1、为入栈元素分配内存
 * 2、元素放入节点
 * 2、新结点指向原头结点指向的节点
 * 3、头结点指向新结点
 */
void Push(LinkedStack *s, ElementType e)  {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = e;
    newNode->next = s->next;
    s->next = newNode;
}

/**
 * 出栈
 * 1.判断栈是否为空
 * 2.若栈不为空,取得栈顶节点(head指向的节点)
 * 3.取出节点数据
 * 4.头结点指向栈顶节点的下一个节点
 * 5.释放内存
 */
ElementType Pop(LinkedStack *s) {
    if (IsEmpty(s)) {
        printf("栈已空\r\n");
        return 0;
    } else {
        struct Node *popNode = s->next;
        ElementType e = popNode->data;
        s->next = popNode->next;
        free(popNode);
        return e;
    }
}

int main() {
    LinkedStack *s = CreateStack();
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 1);
    Push(s, 2);
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    return 0;
}