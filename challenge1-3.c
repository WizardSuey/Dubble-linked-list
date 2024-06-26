// Двусвязный список строк, расположенный в куче. Методы для вставки, нахождения и удаления из него.

#include <stdio.h>
#include "DbLinkedList_funcs.h"
#define MAX_STR_LENGTH 100


int main(void) {
    DblLinkedList *list = createDblLinkedList();

    char str[] = "Hello, world!";
    char str2[] = "Hello, world!2222";
    pushBack(list, str);
    pushFront(list, str2);
    printDblLinkedList(list);
    return 0;
}

