#include <stdio.h>
#include <stdlib.h>

const int MAXSIZE = 10;
typedef int ElementType;

typedef struct {
    ElementType Data[MAXSIZE];
    int Last;
} List;

//空List 函数前加*号
List *MakeEmpty() {
    List *PtrL;
    PtrL = (List *) malloc(sizeof(List));
    PtrL->Last = -1; //空list 最后一个元素位置设为-1
    return PtrL;
}

int Find(ElementType X, List *PtrL) {
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X) {
        i++;
    }
    if (i > PtrL->Last) return -1; /* 如果没找到，返回-1 */
    else return i;
}

/**
 * i表示插入位置 从1开始, MAXSIZE结束
 */
void insert(ElementType X, int i, List *PtrL) {
    //判断表满
    if (PtrL->Last == MAXSIZE - 1) {
        printf("表满");
        return;
    }
    //判断插入位置是否正确 PtrL->Last+1 表示数组的长度N, 插入元素后元素个数由N变为N+1,故插入的位置的范围在 1 <= i <= N+1
    if (i < 1 || i > PtrL->Last + 2) {
        printf("插入位置非法");
        return;
    }
    //将插入位置后面的所有元素后移1位,从数组末尾开始移动
    for (int j = PtrL->Last; j >= i - 1; j--) { //j表示移动元素的索引
        PtrL->Data[j + 1] = PtrL->Data[j];
    }
    //在下表为i-1处插入
    PtrL->Data[i - 1] = X;
    //最后一位索引加1
    PtrL->Last++;
    return;
}

/**
 * 平均移动次数为 (n-1)/2, 平均时间性能为 O(n)
 * 平均移动次数的计算:
 * 移动总次数 / 循环次数 = 平均移动次数
 * i = 1, 移动 n-1次
 * i = 2, 移动次数 n-2次
 * ...
 * i = n, 移动次数 0
 * 故移动总次数= (n-1)*n/2
 * 故平均移动次数 (n-1)/2
 */
void delete(int i, List *PtrL) {
    //判断删除位置的合法性 当前线性表的长度为N 故 1 <= i <= N
    if(i < 1 || i > PtrL->Last + 1){
        printf("删除位置非法");
        return;
    }
    //删除某一位置元素,意味着要把后面的元素全部前移一位,从下表为i(删除元素的下表为i-1)的元素开始直到最后一位结束
    for(int j = i; j <= PtrL->Last; j++) {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    //修改最后一位索引
    PtrL->Last--;
}

int main() {
    List *PtrL = MakeEmpty();
    insert(1, 1, PtrL);
    insert(2, 1, PtrL);
    insert(3, 1, PtrL);
    insert(4, 1, PtrL);
    insert(5, 1, PtrL);
    insert(6, 1, PtrL);
    insert(7, 1, PtrL);
    insert(8, 1, PtrL);
    insert(9, 1, PtrL);
    insert(10, 1, PtrL);
    insert(11, 1, PtrL);
    delete(1, PtrL);
    int length = PtrL->Last + 1;
    return 0;
}