//
//  LinearList.h
//  LinearList
//
//  Created by Brooks on 2017/10/29.
//  Copyright © 2017年 https://github.com/BrooksWon All rights reserved.
//

#ifndef LinearList_h
#define LinearList_h

#include <stdio.h>
#include <malloc/malloc.h>


/**
 首先声明一个顺序表的结构
 */
#define LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define LISTINCREMENT 5   //线性表存储空间的分配增量(当存储空间不够时要用到)
typedef int ElemType;      //数据元素的类型，假设是int型的
typedef struct{
    ElemType *elem;       //存储空间的基地址
    int length;      //当前线性表的长度
    int listsize;    //当前分配的存储容量
}SqList;


/**
 
 创建线性表
 
 */
int InitList(SqList *L);


/**
 
 查找元素（按值查找），时间复杂度为O(n)
 查找元素x
 返回元素的坐标
 
 */
int LocateElem(SqList *L, ElemType x);

/**
 
 查找元素（按位置 or 地址查找），时间复杂度为O(1)
 查找第i个元素，存储在e中
 成功为0，失败为-1
 
 */
int GetElem(SqList *L, int i, ElemType *e);

/**
 
 插入元素，时间复杂度为O(n)
 在第i个元素处，插入元素e
 返回该坐标的元素
 
 */

int ListInsert(SqList *L, int i, ElemType e);


/**
 
 删除元素，时间复杂度为O(n)
 删除第i个元素，并将删除的元素保存在e中
 */
int ListDelete(SqList *L, int i, ElemType *e);

/**
 
 清空顺序表
 */
int ListClean(SqList *L);




#endif /* LinearList_h */
