//
//  list.c
//  单链表(带头节点)
//
//  Created by yu ma on 2020/4/9.
//  Copyright © 2020 yu ma. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 初始化链表
Status initList(listLink *L)
{
    *L = (listLink)malloc(sizeof(node));
    if(*L == NULL)
    {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

// 判断链表是否为空
int listEmpty(listLink L)
{
    return L->next == NULL;
}

// 单链表的销毁
Status destroyList(listLink L)
{
    listLink p = L;
    listLink q = NULL;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

// 清空单链表
Status clearList(listLink L)
{
    listLink p = L->next;
    listLink q = NULL;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

// 链表表长
int listCount(listLink L)
{
    int count = 0;
    listLink p = L->next;
    while(p != NULL)
    {
        count += 1;
        p = p->next;
    }
    return count;
}

// 获取链表第i个元素的内容
Status getElementByIndex(listLink L, int i, ElemType *e)
{
    if(i < 1) return ERROR;
    
    listLink p = L->next;
    int count = 1;
    
    while(p != NULL)
    {
        if(i == count)
        {
            *e = p->data;
            return OK;
        }
        p = p->next;
        count += 1;
    }
    return ERROR;
}

// 在第i个结点前插入值为e的新结点
Status listInsert(listLink L, int i, ElemType e)
{
    if(i < 1) return ERROR;
    
    listLink p = L;
    listLink q = NULL;
    int count = 0;
    
    while(p != NULL)
    {
        if(count == (i-1))
        {
            q = p->next;
            p->next = (listLink)malloc(sizeof(node));
            p->next->data = e;
            p->next->next = q;
            return OK;
        }
        count += 1;
        p = p->next;
    }
    return ERROR;
}

// 打印链表的每一个结点
void printList(listLink L)
{
    listLink p = L->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
