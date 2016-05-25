#include <stdio.h>
#include <stdlib.h>

/*!
 * 一个栈的实现
 */
#define ERROR -2
#define MAXSIZE 10
typedef int ElementType;

typedef struct {
    ElementType data[MAXSIZE]; //数组实现栈
    int Top; //栈顶元素的索引,-1表示空栈
} Stack;

/**
 * 生成空堆栈,其最大长度为MaxSize
 */
Stack *CreateStack(int MaxSize) {
    Stack *s = malloc(sizeof(Stack));
    s->Top = -1;
    return s;
}

/**
 * 判断堆栈S是否已满
 */
int IsFull(Stack *s) {
    if (s->Top == MAXSIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 判断堆栈S是否为空
 */
int IsEmpty(Stack *s) {
    if (s->Top == -1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 压栈
 */
void Push(Stack *s, ElementType e) {
    //判断站是否已满
    if (IsFull(s)) {
        printf("栈已满");
        return;
    } else {
        s->data[++(s->Top)] = e;
        return;
    }
}

/**
 * 出栈
 */
ElementType Pop(Stack *s) {
    if (IsEmpty(s)) {
        printf("栈已空");
        return ERROR;
    } else {
        return s->data[(s->Top)--];
    }
}

int main() {
    Stack *s = CreateStack(1);
    printf("栈是否已满:%s\r\n", IsFull(s) ? "是" : "否");
    printf("栈是否为空:%s\r\n", IsEmpty(s) ? "是" : "否");
    Push(s, 1);
    Push(s, 2);
    printf("出栈元素为%d\r\n", Pop(s));
    printf("出栈元素为%d\r\n", Pop(s));
    Pop(s);
    return 0;
}