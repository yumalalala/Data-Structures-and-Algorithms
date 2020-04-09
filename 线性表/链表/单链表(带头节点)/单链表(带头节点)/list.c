//
//  list.c
//  单链表(带头节点)
//
//  Created by yu ma on 2020/4/9.
//  Copyright © 2020 yu ma. All rights reserved.
//

#include <stdlib.h>
#include "list.h"

Status initList(listLink *L)
{
    *L = (listLink)malloc(sizeof(node));
    if(*L == NULL)
    {
        exit(OVERFLOW);
    }
    (*L)->link = NULL;
    return OK;
}
