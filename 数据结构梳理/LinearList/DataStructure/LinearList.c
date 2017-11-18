//
//  LinearList.c
//  LinearList
//
//  Created by Brooks on 2017/10/29.
//  Copyright © 2017年 https://github.com/BrooksWon All rights reserved.
//

#include "LinearList.h"

/**
 
 创建线性表
 
 */
int InitList(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//开辟一个存储空间，并把这块存储空间的基地址赋值给elem
    if (L->elem == NULL)
    {
        return -1;//空间分配失败
    }
    
    L->length = 0;//线性表的当前长度
    L->listsize = LIST_INIT_SIZE;//当前分配量
    
    return 0;
}

/**
 
 查找元素（按值查找），时间复杂度为O(n)
 返回元素的坐标
 
 */
int LocateElem(SqList *L, ElemType x)
{
    int pos = -1;
    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i] == x)
        {
            pos = i;
        }
    }
    
    return pos;
}

/**
 
 查找元素（按位置 or 地址查找），时间复杂度为O(1)
 查找第i个元素，存储在e中
 成功为0，失败为-1
 
 */
int GetElem(SqList *L, int i, ElemType *e)
{
    
#if 0  //按位置查找
    //判断查找的合法性
    if (i<1 || i>L->length)
    {
        return -1;
    }
    
    *e = L->elem[i-1];
    
    return 0;
#endif
    
    //按地址查找
    
    //判断查找的合法性
    if (i<1 || i>L->length)
    {
        return -1;
    }
    
    *e = *(L->elem+(i-1));
    return 0;
}


/**
 
 插入元素，时间复杂度为O(n)
 返回该坐标的元素
 
 */

int ListInsert(SqList *L, int i, ElemType e)
{
    //判断插入位置的合法性
    if (i<1 || i>L->length+1) return -1;
    //判断存储空间是否够用
    if (L->length >= L->listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) return -1;//存储空间分配失败
        L->elem = newbase;//新基址
        L->listsize += LISTINCREMENT;//增加存储容量
    }
    //插入操作
    ElemType *q, *p; //定义2个指针变量
    q = &(L->elem[i-1]); //q为插入位置(注意形参i是序号，序号是从从1开始的，而下标是从0开始的，因此这里转成下标后是i-1)
    for (p = &(L->elem[L->length - 1]); p >= q; --p) //从ai到an-1依次后移，注意后移操作要从后往前进行
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L->length;//表长加1
    return 0;
}

/**
 
 删除元素，时间复杂度为O(n)
 删除第i个元素，并将删除的元素保存在e中
 */
int ListDelete(SqList *L, int i, ElemType *e)
{
    //判断删除位置是否越界
    if (i<1 || i>L->length)
    {
        return -1;
    }
    
    ElemType *p = &(L->elem[i]);//将p指向i位置的元素
    *e = *p;//将p指向i位置的元素保存在e中
    ElemType *q = &(L->elem[L->length-1]);//将q指向最后的元素
    for (; p <= q; p++)
    {
        *p = *(p+1);//将顺序表中的元素依次平移一个位置
    }
    
    --L->length;
    
    return 0;
}

/**
 
 清空顺序表
 */
int ListClean(SqList *L)
{
    L->length = 0;//把当前线性表的长度设置为0，表示清空
    return 0;
}


