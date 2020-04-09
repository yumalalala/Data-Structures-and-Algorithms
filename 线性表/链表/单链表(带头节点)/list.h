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

typedef int Status;

typedef int ElemType;
typedef struct node node, *listLink;

struct node
{
    ElemType data;
    listLink link;
};

Status initList(listLink *L);

#endif /* list_h */
