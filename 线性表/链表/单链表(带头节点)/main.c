//
//  main.c
//  单链表(带头节点)
//
//  Created by yu ma on 2020/4/9.
//  Copyright © 2020 yu ma. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, const char * argv[])
{
    listLink L = NULL;
    initList(&L);
    printList(L);
    
    listInsert(L, 1, 5);
    printList(L);
    listInsert(L, 2, 15);
    printList(L);
    listInsert(L, 3, 20);
    printList(L);
    listInsert(L, 2, 1130);
    printList(L);
    listInsert(L, 0, 7755);
    printList(L);
    listInsert(L, 6, 7755);
    printList(L);
    
    return 0;
}
