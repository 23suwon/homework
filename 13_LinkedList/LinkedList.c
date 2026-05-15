#include "LinkedList.h"

LinkedList* createLinkedList() {
	struct linkedList* r;
	r = (struct linkedList*)malloc(sizeof(struct linkedList));

	r->head = (struct pointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(LinkedList* li) {
	struct pointType* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li, int item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	ptr->data = item;

	ptr->next = li->head;
	li->head = ptr;
	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	if (li->size == 0) {
		printf("리스트가 비어있습니다\n");
		return;
	}

	PointType* current = li->head;
	
	for (int i = 0; i < li->size; i++) {
		printf("[%d] \n", current->data);

		current = current->next;
	}
}

LinkedList* insertLastLinkedList(LinkedList* li, int item) {
	PointType* ptr = li->head;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->data = item;
	nPtr->next = NULL;

	ptr->next = nPtr;

	li->size++;

	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;

		for (int i = 0; i < at - 1; i++) {
			nPtr = nPtr->next;
		}

		if (at == 0) {
			PointType* fPtr = li->head;
			li->head = fPtr->next;
			free(fPtr);
		}
		else {
			PointType* fPtr = nPtr->next;
			nPtr->next = fPtr->next;
			free(fPtr);
		}

		li->size--;
	}
}

LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre,
	int item) {

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->data = item;

	if (pre != NULL) {
		nPtr->next = pre->next;
		pre->next = nPtr;
	}
	else {
		nPtr->next = li->head;
		li->head = nPtr;
	}

	li->size++;
}

int deleteFirstLinkedList(LinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head;
		li->head = tPtr->next;

		int temp = tPtr->data;
		free(tPtr);

		li->size--;
		return temp;
	}
	else {
		return 0;
	}
}

int deleteLastLinkedList(LinkedList* li) {
	PointType* pre;
	PointType* iPtr;

	pre = li->head;

	if (pre == NULL) {
		return 0;
	}

	iPtr = pre->next;

	if (iPtr == NULL) {
		li->head = NULL;

		int temp;
		temp = pre->data;

		free(pre);
		li->size--;

		return temp;
	}
	else {
		while (iPtr->next != NULL) {
			pre = iPtr;
			iPtr = iPtr->next;
		}

		int temp;
		temp = iPtr->data;

		pre->next = NULL;
		free(iPtr);
		li->size--;

		return temp;
	}
}

LinkedList* insertAtLinkedList(LinkedList* li, int at, int item) {
	if (at < 0 || at > li->size)
		return li;

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	nPtr->data = item;

	if (at == 0) {
		nPtr->next = li->head;
		li->head = nPtr;
	}
	else {
		PointType* ptr = li->head;
		for (int i = 0; i < at - 1; i++)
			ptr = ptr->next;
		nPtr->next = ptr->next;
		ptr->next = nPtr;
	}
	li->size++;
	return li;
}

int deleteItemLinkedList(LinkedList* li, int pos) {
	return deleteAtLinkedList(li, pos);
}

int getItemLinkedList(LinkedList* li, int pos) {
	if (pos < 0 || pos >= li->size) {
		return 0;
	}
	PointType* current = li->head;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}
	return current->data;
}

LinkedList* replaceItemLinkedList(LinkedList* li, int pos, int item) {
	if (pos < 0 || pos >= li->size) {
		return li;
	}
	PointType* current = li->head;
	for (int i = 0; i < pos; i++)
		current = current->next;
	current->data = item;
	return li;
}

int nextItemLinkedList(LinkedList* li, PointType* pre) {
	if (pre == NULL) {
		if (li->head != NULL) {
			return li->head->data;
		}
		return 0;
	}
	if (pre->next != NULL) {
		return pre->next->data;
	}
	return 0;
}