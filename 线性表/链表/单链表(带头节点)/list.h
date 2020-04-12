//
//  list.h
//  单链表(带头节点)
//
//  Created by yu ma on 2020/4/9.
//  Copyright © 2020 yu ma. All rights reserved.
//

#ifndef list_h
#define list_h

#define OK 1
#define OVERFLOW -1
#define ERROR -2

typedef int Status;

typedef int ElemType;
typedef struct node node, *listLink;

struct node
{
    ElemType data;
    listLink next;
};

// 初始化链表
Status initList(listLink *L);

// 判断链表是否为空
int listEmpty(listLink L);

// 单链表的销毁
Status destroyList(listLink L);

// 清空单链表
Status clearList(listLink L);

// 链表表长
int listCount(listLink L);

// 打印链表的每一个结点
void printList(listLink L);

// 获取链表第i个元素的内容
Status getElementByIndex(listLink L, int i, ElemType *e);

// 按值查找元素所在位置（只寻找第一个相等元素）
node* findLinkByElement(listLink L, ElemType e);

// 按值查找元素所在序号（只寻找第一个相等元素）
int findIndexByElement(listLink L, ElemType e);

// 在第i个结点前插入值为e的新结点
Status listInsert(listLink L, int i, ElemType e);

// 删除第i个结点，并保存该结点数据域的值
Status listDeleteByIndex(listLink L, int i, ElemType *e);

// 建立单链表（头插法）
void createListH(listLink *L, int n);

// 建立单链表（尾插法）
void createListR(listLink* L, int n);

#endif /* list_h */
