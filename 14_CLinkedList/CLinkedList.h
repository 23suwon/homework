#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int data;
	struct pointType* prev;
	struct pointType* next;
} PointType;

typedef struct cLinkedList {
	PointType* tail;
	int size;
} CLinkedList;

extern CLinkedList* createCLinkedList();
extern void destoryCLinkedList(CLinkedList* cl);

extern int insertFirstCLinkedList(CLinkedList* cl, PointType item);
extern int insertLastCLinkedList(CLinkedList* cl, PointType item);

extern void printCLinkedList(CLinkedList* cl);

extern int isEmptyDCLinkedList(CLinkedList* dl);
extern int sizeDCLinkedList(CLinkedList* dl);

extern void insertAtDCLinkedList(CLinkedList* dl, int index , PointType item);
extern void insertItemDCLinkedList(CLinkedList* cl, PointType* pre, PointType item);

extern int deleteFirstDCLinkedList(CLinkedList* dl);
extern int deleteLastDCLinkedList(CLinkedList* dl);
extern int deleteAtDCLinkedList(CLinkedList* dl, int index);
extern int deleteItemDCLinkedList(CLinkedList* cl, PointType* pos);

extern PointType getItemDCLinkedList(CLinkedList* cl, int pos);
extern void      replaceItemDCLinkedList(CLinkedList* cl, int pos, PointType item);
extern PointType nextItemDCLinkedList(CLinkedList* cl, PointType* pre);
