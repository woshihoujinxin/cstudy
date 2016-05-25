//
// 栈的接口文件
// Created by 侯金鑫 on 16/5/24.
//

#ifndef StackDef
#define StackDef

typedef struct StackDef{
    void **bottom; //因为指针类似于一个数组,一级指针指向的是一个具体的元素,二级指针的存储结构其实是个一级指针列表,用于表示栈中元素
    int top; //栈顶索引
    int max_size;
} Stack;

/**
 * 函数声明
 */
Stack *createStack(int max_size);
void destroyStack(Stack *stack);
//压栈返回值为任意类型
void *push(Stack *stack, void *element);
//出栈返回值为任意类型
void *pop(Stack *stack);

#endif //StackDef