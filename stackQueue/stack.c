//
// 栈的实现
// Created by 侯金鑫 on 16/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *createStack(int max_size) {
    //先为栈分配内存地址
    Stack *stackDef = malloc(sizeof(Stack));
    //根据传入的max_size为栈的大小分配足够内存
    stackDef->max_size = max_size;
    stackDef->bottom = malloc(stackDef->max_size * sizeof(void *));
    //栈顶元素索引为0
    stackDef->top = 0;
    return stackDef;
};

void destroyStack(Stack *stack) {
    //释放占中元素所占内存
    free(stack->bottom);
    //释放栈的内存
    free(stack);
};

//压栈返回值为任意类型
void *push(Stack *stack, void *element) {
    if(stack->top == stack->max_size){
        printf("栈已满\r\n");
        return NULL;
    }
    //因为指针的结构类似数组,故可以用[下标]来访问
    stack->bottom[stack->top++] = element;
    return element;
};

//出栈返回值为任意类型
void *pop(Stack *stack) {
    if (stack->top == 0) {
        printf("栈已空\r\n");
        return NULL;
    }
    //取出栈顶元素
    void *element = stack->bottom[--stack->top];
    return element;
};
