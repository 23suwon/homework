#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int data;
	struct pointType* next;
} PointType;

typedef struct linkedList {
	struct pointType* head;
	int size;
} LinkedList;

extern LinkedList* createLinkedList();
extern int destroyLinkedList(LinkedList* li);
extern int isEmptyLinkedList(LinkedList* li);
extern int sizeLinkedList(LinkedList* li);
extern LinkedList* insertFirstLinkedList(LinkedList* li, int item);
extern int printLinkedList(LinkedList* li);
extern LinkedList* insertLastLinkedList(LinkedList* li, int item);
extern LinkedList* insertAtLinkedList(LinkedList* li, int at, int item);
extern LinkedList* deleteAtLinkedList(LinkedList* li, int at);
extern LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, int item);
extern int deleteFirstLinkedList(LinkedList* li);
extern int deleteLastLinkedList(LinkedList* li);
extern int deleteItemLinkedList(LinkedList* li, int pos);
extern int getItemLinkedList(LinkedList* li, int pos);
extern LinkedList* replaceItemLinkedList(LinkedList* li, int pos, int item);
extern int nextItemLinkedList(LinkedList* li, PointType* pre);