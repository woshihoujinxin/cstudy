//
// 一级指针和二级指针
// *和&可以认为是相反的两个操作符 & 按值取地址, * 按地址取值
// Created by 侯金鑫 on 16/5/25.
//

#include <stdio.h>

int main1() {

    int a = 99;
    int *pa = &a; //取a的地址赋值给pa, *pa 按照a的地址取得a值
    int **ppa = &pa; //取pa的地址赋值给ppa, *ppa取得pa的地址 **ppa取得a的地址
    printf("%08x\r\n", a);
    printf("%08x\r\n", pa);//指向a的地址的指针的地址
    printf("%08x\r\n", *pa);//取值
    printf("%08x\r\n", ppa);
    printf("%08x\r\n", *ppa);
    printf("%08x\r\n", **ppa); //取值

    int arr[] = {1, 2, 3};
    int *parr = &arr;
    printf("%08x\r\n", arr);
    printf("%08x\r\n", *parr); //取值

    int null = NULL;
    printf("NULL转int为%d", null);

}