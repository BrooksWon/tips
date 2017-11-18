//
//  main.c
//  LinearList
//
//  Created by Brooks on 2017/10/29.
//  Copyright © 2017年 https://github.com/BrooksWon All rights reserved.
//

#include <stdio.h>
#include "LinearList.h"
#include <stdlib.h>
#include "LinkList.h"

int main(int argc, const char * argv[]) {
    
#if 0 //顺序表测试代码
    SqList *l = (SqList *)malloc(sizeof(SqList));
    
    //创建顺序表
    InitList(l);
    

    //从第1个元素开始，先顺序插入10个元素
    for (int i=1; i<11; i++)
    {
        ListInsert(l, i, 11-i);
    }
    
    //输出线性表
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", l->elem[i]);
    }
    printf("\n");
    
    //在坐标为3的位置插入元素
    int status = ListInsert(l, 3, 99);
    
    //输出线性表
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ", l->elem[i]);
    }
    printf("\n");
    
        
    //在顺序表中查找元素为7的坐标
    int pos = LocateElem(l, 7);
    printf("l->elem[%d] = %d", pos, l->elem[pos]);
    
    //删除第5个元素，并且删除的元素保存在e中
    ElemType e = 0;
    ListDelete(l, 5, &e);
    printf("\n");

    
    //输出线性表
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ", l->elem[i]);
    }
    printf("\n");
    
    //查找第3个元素，并且结果保存在find_e中
    ElemType find_e = 0;
    GetElem(l, 3, &find_e);
    printf("find_e = %d ", find_e);
    printf("\n");

    
    
    if (l != NULL)
    {
        //清空顺序表
        ListClean(l);
        
        free(l->elem);
        free(l);
        l = NULL;
    }
#endif
    // 创建链表:头插法
    LinkList *l1 = CreateListHead(10);
    
    //输出链表中的数据
    while (l1->next != NULL) {
        LNode *node = l1->next;
        printf("%d ", node->data);
        l1 = node;
    }
    printf("\n");
    
    // 创建链表:尾插法
    LinkList *l2 = CreateListTail(10);
    
    //输出链表中的数据
    while (l2->next != NULL) {
        LNode *node = l2->next;
        printf("%d ", node->data);
        l2 = node;
    }
    printf("\n");
    
    // 查找第7个节点
    LinkList *l3 = CreateListTail(10);
    int xdata = 0;
    int status = GetElemFromLinkList(l3, 7, &xdata);// 返回7
    
    // 查找第7个节点位置插入777
    status = LinkListInsert(l3, 7, 777);
    
    GetElemFromLinkList(l3, 8, &xdata);// 返回777

    // 删除第i个节点
    status = LinkListDelete(l3, 4, &xdata);
    
    // 清空单链表
    status = ClearLinkList(l3);
    //输出链表中的数据
    while (l3->next != NULL) {
        LNode *node = l3->next;
        printf("%d ", node->data);
        l2 = node;
    }
    printf("\n");
    
    return 0;
}
