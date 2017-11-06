//
//  LinkList.c
//  LinearList
//
//  Created by Brooks on 2017/10/29.
//  Copyright © 2017年 https://github.com/BrooksWon All rights reserved.
//

#include "LinkList.h"

/**
 
 1.1创建链表(头插法) 时间复杂度O(n)
 
 */
LinkList * CreateListHead(int n)
{
    LNode *L = NULL;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    
    LNode *p = NULL;//p为新结点，指向最后一个元素
    
    for (int i=1 ; i<=n; ++i)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = i;
        p->next = L->next;//将p的next指向L的next
        L->next = p;//将L的next指向p
    }
    
    return L;
}

/**
 
 1.2创建链表(尾插法) 时间复杂度O(n)
 
 */
LinkList * CreateListTail(int n)
{
    LNode *L = NULL;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    
    LNode *r = L;
    
    LNode *p = NULL;
    
    for (int i=1 ; i<=n; ++i)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = i;
        p->next = NULL;
        
        r->next = p;//将r的next指向p
        r = p;//将r指向p的指向
    }
        
    return L;
}

/**
 
 2.查找元素(取第i个元素) 时间复杂度O(n)
 
 */

int GetElemFromLinkList(LinkList *L, int i, ElemType *e)
{
    LNode *node = L;//设node为第i-1个结点

    while (i!=0 && node!=NULL) {
        --i;
        node = node->next;
    }
    
    if (i==0 && node != NULL) {

        *e = node->data;
        return 0;
        
    } else {
        
        return -1;//第i个元素不存在
    }
}

/**
 
 3.插入元素 时间复杂度为O(n)，但是频繁插入时，为O(1)
    在第i个元素位置，插入数据e
 
 */

int LinkListInsert(LinkList *L, int i, ElemType e)
{
    LNode *p = L;//设p为第i-1个结点

    while(i!=0 && p!=NULL) {
        --i;
        p = p->next;
    }
    
    if (i==0 && p!=NULL) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        
        s->next = p->next;//s的直接后继指向p原来的直接后继
        p->next = s;//p的直接后继指向s
        
        return 0;
    } else {
        return -1;
    }
}

/**
 
 4.插入元素 时间复杂度为O(n)，但是频繁删除时，为O(1)
    删除第i个节点
 
 */
int LinkListDelete(LinkList *L, int i, ElemType *e)
{
    LNode *p = L;//设p为第i-1个结点
    
    while(i!=0 && p!=NULL) {
        --i;
        p = p->next;
    }
    
    if (i==0 && p!=NULL) {
        LNode *q = p->next;
        p->next = q->next;
        *e = q->data;
        
        return 0;
    } else {
        return -1;
    }
}



/**
 
 5.清空单链表 时间复杂度为O(n)
 
 */
int ClearLinkList(LinkList *L)
{
    LNode *p, *q;
    p = L->next;
    
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    
    L->next = NULL;
    
    return 0;
}








