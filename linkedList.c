#include <stdio.h>
#include <stdlib.h>

/**
 * 线性表的链式实现
 * 1.求表长: 遍历链表
 */

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} List;

/**
 * 时间复杂度O(n) 与链表的长度有关
 */
int Length(List *PtrL) {
    int i = 0;
    List *p = PtrL;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

//空List 函数前加*号
List *MakeEmpty1() {
    return malloc(sizeof(List));
}

/**
 * 按序号查找
 */
List *findKth(int k, List *PtrL) {
    int i = 1; //序号为1
    List *p = PtrL;
    while (p != NULL && i < k) { //指针不为空,且序号小于要搜索的节点序号
        p = p->next;
        i++;
    }
    if (i == k) {//找到了
        return p;
    } else {
        return NULL;
    }
    /**
     * 下面的代码没有考虑k的合法性问题,
     * 1.若k<=0,循环不执行 直接return p,显然是不对的
     * 2.设List长度为l 若k>l,则i总是小于k,那么循环将一直执行知道遍历值最后的节点,这是返回的值也是不对的
     * 3.分支语句隐含的信息是到底找没找到第k个节点
     */
//    if (p == NULL) {
//        return NULL;
//    } else {
//        return p;
//    }
    //return p;
}


/**
 * 按值查找,若无法找到则会遍历到最后一个节点最终返回NULL,若找到则返回p的指针
 * 时间复杂度O(N)
 */
List *findByValue(int value, List *PtrL) {
    List *p = PtrL;
    while (p != NULL && p->data != value) { //指针不为空,且序号小于要搜索的节点序号
        p = p->next;
    }
    return p;
}

/**
 * 插入节点
 * 1.先创建一个新的节点s并分配内存空间
 * 2.然后找到要插入位置的前一个节点,令p指向该节点
 * 3.s.next指向p.next
 * 4.p.next指向s
 * 3,4两步不能调换顺序,否则会导致 p.next指向s s.next指向自身,从而不能完成插入
 */
List *insert(ElementType X, int i, List *PtrL) {
    List *p, *s;
    if (i == 1) { //若是在初始位置插入,则直接让s.next = p , p = s
        s = (List *) malloc(sizeof(List)); //分配空间
        s->data = X; //赋值
        s->next = PtrL;
        PtrL = s;
        return PtrL;
    }
    p = findKth(i - 1, PtrL);//查找插入位置的前一个节点
    if (p == NULL) { //未找到
        printf("参数i出错");
        return NULL;
    } else {
        s = (List *) malloc(sizeof(List)); //分配空间
        s->data = X;
        s->next = p->next;
        p->next = s;
        return PtrL;
    }
}

/**
 * 删除节点
 * 1.找到要删除节点的前一个节点p
 * 2.s指向要删除的节点p.next
 * 3.p.next指向s.next
 * 4.释放s所占空间
 * 这里的2,3仍然不能改变顺序,s初始情况并未赋值,s本身即是NULL
 *
 * 平均查找次数n/2 时间复杂度O(n)
 */
List *delete(int i, List *PtrL) {
    List *p, *s;
    if (i == 1) {
        s = PtrL;
        //头结点分为两种情况 本身List为空或者头结点不空
        if (PtrL != NULL)
            PtrL = PtrL->next;
        else
            return NULL;
        free(s);
        return PtrL;

    }
    p = findKth(i - 1, PtrL); //找前一节点
    if (p == NULL) { //未找到
        printf("参数i出错");
        return NULL;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);
        return PtrL;
    }
}


int main() {
    List *PtrL = NULL;
    PtrL = insert(1, 1, PtrL);
    PtrL = insert(2, 1, PtrL);
    PtrL = insert(3, 1, PtrL);
    PtrL = insert(4, 1, PtrL);
    PtrL = insert(5, 1, PtrL);
    PtrL = insert(6, 1, PtrL);
    PtrL = insert(7, 1, PtrL);
    PtrL = insert(8, 1, PtrL);
    PtrL = insert(9, 1, PtrL);
    PtrL = insert(10, 1, PtrL);
    PtrL = insert(11, 1, PtrL);
    PtrL = delete(1, PtrL);
    printf("长度%d",Length(PtrL));
    printf("找到值为%d的节点",findByValue(4, PtrL)->data);
    return 0;
}