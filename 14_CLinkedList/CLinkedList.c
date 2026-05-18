#include "CLinkedList.h"


CLinkedList* createCLinkedList() {
	CLinkedList* temp;
	temp = (CLinkedList*)malloc(sizeof(CLinkedList));
	temp->tail = NULL;
	temp->size = 0;

	return temp;
}

void destoryCLinkedList(CLinkedList* cl) {
	PointType* temp;
	temp = cl->tail->next;

	while (cl->size != 0) {
		PointType* nPtr = temp->next;
		free(temp);
		temp = nPtr;
		cl->size--;
	}

	free(cl);
}

int insertFirstCLinkedList(CLinkedList* cl, PointType item) {
	PointType* nPtr;
	nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	if (cl->size == 0) {
		nPtr->prev = nPtr;
		nPtr->next = nPtr;
		cl->tail = nPtr;
	}
	else {
		nPtr->next = cl->tail->next;
		nPtr->prev = cl->tail;
		cl->tail->next->prev = nPtr;
		cl->tail->next = nPtr;
	}

	cl->size++;
}

int insertLastCLinkedList(CLinkedList* cl, PointType item) {
	insertFirstCLinkedList(cl, item);
	cl->tail = cl->tail->next;
}

void printCLinkedList(CLinkedList* cl) {
	
	if (cl->size == 0) {
		return;
	}

	PointType* start = cl->tail->next;

	for (int i = 0; i < cl->size; i++) {
		printf("[%d]%d\n", i, start->data);

		start = start->next;
	}
}

int isEmptyDCLinkedList(CLinkedList* cl) {
	return cl->size == 0;
}
int sizeDCLinkedList(CLinkedList* cl) {
	return cl->size;
}

void insertAtDCLinkedList(CLinkedList* cl, int index, PointType item) {
	PointType* nPtr;
	PointType* cur;
	int i;
	
	if (index < 0 || index> cl->size) {
		return;
	}
	if (index == 0) {
		insertFirstCLinkedList(cl, item);
		return;
	}
	if (index == cl->size) {
		insertLastCLinkedList(cl, item);
		return;
	}
	cur = cl->tail->next;
	for (i = 0; i < index; i++) {
		cur = cur->next;
	}
	nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->prev = cur->prev;
	nPtr->next = cur;
	cur->prev->next = nPtr;
	cur->prev = nPtr;
	cl->size++;
}

int deleteFirstDCLinkedList(CLinkedList* cl) {
	PointType* head;
	int data;
	if (cl->size == 0) {
		return -1;
	}
	head = cl->tail->next;
	data = head->data;
	if (cl->size == 1) {
		free(head);
		cl->tail = NULL;
	}
	else {
		cl->tail->next = head->next;
		head->next->prev = cl->tail;
		free(head);
	}
	cl->size--;
	return data;
}

int deleteLastDCLinkedList(CLinkedList* cl) {
	PointType* dTail;
	int data;
	if (cl->size == 0) {
		return -1;
	}
	if (cl->size == 1)
		return deleteFirstDCLinkedList(cl);
	dTail = cl->tail;
	data = dTail->data;

	cl->tail = dTail->prev;
	cl->tail->next = dTail->next;
	dTail->next->prev = cl->tail;
	free(dTail);
	cl->size--;
	return data;
}

int deleteAtDCLinkedList(CLinkedList* cl, int index) {
	PointType* cur;
	int data;

	if (index < 0 || index >= cl->size) {
		return -1;
	}
	if (index == 0)
		return deleteFirstDCLinkedList(cl);
	if (index == cl->size - 1)
		return deleteLastDCLinkedList(cl);

	cur = cl->tail->next;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	data = cur->data;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	cl->size--;
	return data;
}

void insertItemDCLinkedList(CLinkedList* cl, PointType* pre, PointType item) {
	PointType* nPtr;

	if (pre == NULL) {
		insertFirstCLinkedList(cl, item);
		return;
	}

	nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->prev = pre;		
	nPtr->next = pre->next;	
	pre->next->prev = nPtr;
	pre->next = nPtr;

	if (pre == cl->tail)
		cl->tail = nPtr;

	cl->size++;
}

int deleteItemDCLinkedList(CLinkedList* cl, PointType* pos) {
	PointType* cur;
	int data;
	int i;

	if (cl->size == 0 || pos == NULL) {
		return -1;
	}

	cur = cl->tail->next;
	for (i = 0; i < cl->size; i++) {
		if (cur == pos) break;
		cur = cur->next;
	}
	if (i == cl->size) {
		return -1;
	}

	data = pos->data;

	if (pos == cl->tail)
		cl->tail = pos->prev;

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	cl->size--;

	if (cl->size == 0) cl->tail = NULL;
	return data;
}

PointType getItemDCLinkedList(CLinkedList* cl, int pos) {
	PointType* cur;
	PointType  empty = { -1, NULL, NULL };
	int i;

	if (pos < 0 || pos >= cl->size) {
		return empty;
	}

	cur = cl->tail->next;
	for (i = 0; i < pos; i++)
		cur = cur->next;

	return *cur;
}

void replaceItemDCLinkedList(CLinkedList* cl, int pos, PointType item) {
	PointType* cur;
	int i;

	if (pos < 0 || pos >= cl->size) {
		return;
	}

	cur = cl->tail->next;
	for (i = 0; i < pos; i++)
		cur = cur->next;

	cur->data = item.data;
}

PointType nextItemDCLinkedList(CLinkedList* cl, PointType* pre) {
	PointType empty = { -1, NULL, NULL };

	if (pre == NULL || cl->size == 0) {
		return empty;
	}
	return *(pre->next);
}