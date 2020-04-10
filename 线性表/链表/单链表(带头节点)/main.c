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
    int s = 0;
    
    s = listInsert(L, 1, 5);
    printList(L);
    
    s = listInsert(L, 3, 15);
    printList(L);
    
    return 0;
}
