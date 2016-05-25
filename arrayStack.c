#include <stdio.h>
#include <stdlib.h>

/*!
 * 用一个数组实现两个堆栈,为了最大程度的利用数组空间,使数组只要有空间就可以让入栈操作成功
 *
 * 一种实现为:栈1从左开始,栈2从右开始。让两个栈分别向数组的中间生长,当两个栈的栈顶相遇,表示这两个栈都满了
 */
#define ERROR -2
#define MAXSIZE 10
typedef int ElementType;

typedef struct {
    ElementType data[MAXSIZE]; //数组实现栈
    int Top1; //栈1的栈顶元素的索引
    int Top2; //栈2栈栈顶元素的索引
} ArrayStack;

/**
 * 生成2个空堆栈,并初始化栈一和栈2的栈顶索引
 */
ArrayStack *CreateStack() {
    ArrayStack *s = malloc(sizeof(ArrayStack));
    s->Top1 = -1;
    s->Top2 = MAXSIZE;
    return s;
}

/**
 * 当两个栈的栈顶相遇,即栈顶的索引差一
 */
int IsFull(ArrayStack *s) {
    if (s->Top2 - s->Top1 == 1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 判断堆栈S是否为空
 */
int IsEmpty(ArrayStack *s, int tag) {
    if (tag == 1) {
        if (s->Top1 == -1) {
            return 1;
        } else {
            return 0;
        }
    }
    if (tag == 2) {
        if (s->Top2 == MAXSIZE) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

/**
 * 压栈, tag用来区分栈一和栈二
 */
void Push(ArrayStack *s, ElementType e, int tag) {
    //判断栈是否已满
    if (IsFull(s)) {
        printf("栈已满, 当前入栈%d元素%d\r\n", e, tag);
        return;
    } else {
        if(tag == 1) {
            //检查栈2的栈顶元素与插入元素后栈1栈顶元素索引是否差一
            if(s->Top2 - s->Top1 != 1) {
                s->data[++(s->Top1)] = e;
            }
        } else if(tag == 2){
            //检查栈1的栈顶元素与插入元素后栈2栈顶元素索引是否差一
            if(s->Top2 - s->Top1 != 1) {
                s->data[--(s->Top2)] = e;
            }
        }
        return;
    }
}

/**
 * 出栈
 */
ElementType Pop(ArrayStack *s, int tag) {
    if (IsEmpty(s, tag)) {
        printf("栈%d已空\r\n", tag);
        return ERROR;
    } else {
        ElementType e;
        if (tag ==1){
            e = s->data[s->Top1--];
        } else if (tag == 2) {
            e = s->data[s->Top2++];
        }
        return e;
    }
}

int main() {
    ArrayStack *s = CreateStack();
    printf("栈是否已满:%s\r\n", IsFull(s) ? "是" : "否");
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 1, 1);
    Push(s, 2, 2);
    printf("出栈元素为%d\r\n", Pop(s,1));
    printf("出栈元素为%d\r\n", Pop(s,2));
    return 0;
}