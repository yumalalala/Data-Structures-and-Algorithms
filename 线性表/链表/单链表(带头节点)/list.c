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
int listj(listLink L)
{
    int i = 0;
    listLink p = L->next;
    while(p != NULL)
    {
        i += 1;
        p = p->next;
    }
    return i;
}

// 获取链表第i个元素的内容
Status getElementByIndex(listLink L, int i, ElemType *e)
{
    listLink p = L->next;
    int j = 1;
    while((p != NULL) && (j < i))
    {
        j += 1;
        p = p->next;
    }
    if((p == NULL) || (j > i))
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

// 按值查找元素所在位置（只寻找第一个相等元素）
listLink findLinkByElement(listLink L, ElemType e)
{
    listLink p = L->next;
    while((p != NULL) && (p->data != e))
    {
        p = p->next;
    }
    return p;
}

// 按值查找元素所在序号（只寻找第一个相等元素）
int findIndexByElement(listLink L, ElemType e)
{
    listLink p = L->next;
    int i = 1;
    while((p != NULL) && (p->data != e))
    {
        i += 1;
        p = p->next;
    }
    return (p == NULL) ? 0 : i;
}

// 在第i个结点前插入值为e的新结点
Status listInsert(listLink L, int i, ElemType e)
{
    listLink p = L;
    listLink q = NULL;
    int j = 0;
    while((p != NULL) && (j < i-1))
    {
        j += 1;
        p = p->next;
    }
    if((p == NULL) || (j > i-1))
    {
        return ERROR;
    }
    q = p->next;
    p->next = (listLink)malloc(sizeof(node));
    p->next->data = e;
    p->next->next = q;
    return OK;
}

// 删除第i个结点，并保存该结点数据域的值
Status listDeleteByIndex(listLink L, int i, ElemType *e)
{
    listLink p = L;
    listLink q = NULL;
    int j = 0;
    while((p->next != NULL) && (j < i-1))
    {
        j += 1;
        p = p->next;
    }
    if((p->next == NULL) || (j > i-1))
    {
        return ERROR;
    }
    q = p->next;
    p->next = p->next->next;
    *e = q->data;
    free(q);
    return OK;
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
