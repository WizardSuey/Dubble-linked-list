#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    // Структура узла
    char *value;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _DblLinkedList {
    // Структура списка
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

DblLinkedList* createDblLinkedList() {
    // Создание списка
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushFront(DblLinkedList *list, char *data) {
    // Вставка в начало списка
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void* popFront(DblLinkedList *list) {
    //Удаление с начала
    Node *prev;
    void *tmp;
    if (list->head == NULL) {
        exit(2);
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);

    list->size--;
    return tmp;
}

void pushBack(DblLinkedList *list, char *value) {
    //Вставка в конец
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}
 
void* popBack(DblLinkedList *list) {
    //Удаление с конца
    Node *next;
    void *tmp;
    if (list->tail == NULL) {
        exit(4);
    }
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
 
    list->size--;
    return tmp;
}


Node* getNth(DblLinkedList *list, size_t index) {
    // Получение n-го элемента
    Node *tmp = list->head;
    size_t i = 0;
 
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
 
    return tmp;
}

void insert(DblLinkedList *list, size_t index, char *value) {
    // Вставка узла в список
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNth(list, index);
    if (elm = NULL) {
        exit(5);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
}

void* deleteNth(DblLinkedList *list, size_t index) {
    // Удаление узла
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;
 
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
 
    free(elm);
 
    list->size--;
 
    return tmp;
}

void printDblLinkedList(DblLinkedList *list) {
    // Печать списка
    Node *tmp = list->head;
    while (tmp) {
        printf("%s\n", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}