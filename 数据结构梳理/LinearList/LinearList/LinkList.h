//
//  LinkList.h
//  LinearList
//
//  Created by Brooks on 2017/10/29.
//  Copyright © 2017年 https://github.com/BrooksWon All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <malloc/malloc.h>

/**
 首先声明一个单链表的结构
 */

typedef int ElemType;      //数据元素的类型，假设是int型的

typedef struct{
    ElemType data;//数据域
    struct LNode *next;//指针域
    
}LNode;

typedef LNode LinkList;

/**
 
 1.1创建链表(头插法) 时间复杂度O(n)
 
 */
LinkList * CreateListHead(int n);

/**
 
 1.2创建链表(尾插法) 时间复杂度O(n)
 
 */
LinkList * CreateListTail(int n);

/**
 
 2.查找元素(取第i个元素)
 
 */

int GetElemFromLinkList(LinkList *L, int i, ElemType *e);

/**
 
 3.插入元素 时间复杂度为O(n)，但是频繁插入时，为O(1)
    在第i个节点位置，插入数据e
 
 */

int LinkListInsert(LinkList *L, int i, ElemType e);

/**
 
 4.插入元素 时间复杂度为O(n)，但是频繁删除时，为O(1)
    删除第i个节点
 
 */
int LinkListDelete(LNode *L, int i, ElemType *e);


#endif /* LinkList_h */
