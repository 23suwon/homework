#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al;
    al = (arrayList*)malloc(sizeof(arrayList));
    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    al->size = 0;
    al->capacity = size;
    return al;
}

void destroyArrayList(arrayList* al) {
    free(al->data);
    free(al);
}

int isEmptyArrayList(arrayList* al) {
    return (al->size == 0) ? 1 : 0;
}

int isFullArrayList(arrayList* al) {
    return (al->size == al->capacity) ? 1 : 0;
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size) {
        printf("error (0 ~ %d 사이 입력)\n", al->size);
        return 0;
    }
    if (isFullArrayList(al)) {
        printf("error List is full \n");
        return 0;
    }

    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }
    al->data[pos] = item;
    al->size++;
    return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos > al->size - 1) {
        printf("error (0 ~ %d 사이 입력)\n", al->size - 1);
        return -1;  
    }
    elementArrayList item = al->data[pos];
    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }
    al->size--;
    return item;
}


void initArrayList(arrayList* al) {
    al->size = 0;  
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size - 1) {
        printf("error (0 ~ %d 사이 입력)\n", al->size - 1);
        return 0;
    }
    al->data[pos] = item;
    return 1;
}

void printArrayList(arrayList* al) {
    if (isEmptyArrayList(al)) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    printf("┌─────────────────────────────\n");
    printf("│ 위치\t│ 값\n");
    printf("├─────────────────────────────\n");
    for (int i = 0; i < al->size; i++) {
        printf("│  [%d]\t│ %d\n", i, al->data[i]);
    }
    printf("└─────────────────────────────\n");
    printf("총 %d개의 항목\n", al->size);
}