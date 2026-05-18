#define _CRT_SECURE_NO_WARNINGS
#include "CLinkedList.h"

void printMenu() {
	printf("  이중 원형 연결 리스트 메뉴\n");
	printf("  1. 맨 앞에 추가\n");
	printf("  2. 맨 뒤에 추가\n");
	printf("  3. 특정 위치에 추가\n");
	printf("  4. 특정 위치 삭제\n");
	printf("  5. 전체 목록 출력\n");
	printf("  6. 리스트 크기 확인\n");
	printf("  0. 종료\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("선택: ");
}

int main() {
	CLinkedList* cl = createCLinkedList();
	int choice, index, deleted;
	PointType item;

	while (1) {
		printMenu();
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			printf("삽입할 정수: ");
			scanf("%d", &item.data);
			insertFirstCLinkedList(cl, item);
			break;

		case 2:
			printf("삽입할 정수: ");
			scanf("%d", &item.data);
			insertLastCLinkedList(cl, item);
			break;

		case 3:
			printf("삽입할 위치(0~%d): ", cl->size);
			scanf("%d", &index);
			printf("삽입할 정수: ");
			scanf("%d", &item.data);
			insertAtDCLinkedList(cl, index, item);
			break;

		case 4:
			if (isEmptyDCLinkedList(cl)) {
				printf(">> 리스트가 비어 있습니다.\n");
				break;
			}
			printf("삭제할 위치(0~%d): ", cl->size - 1);
			scanf("%d", &index);
			deleted = deleteAtDCLinkedList(cl, index);
			break;

		case 5:
			printCLinkedList(cl);
			break;

		case 6:
			printf(">> 현재 리스트 크기: %d\n", sizeDCLinkedList(cl));
			break;

		case 0:
			destoryCLinkedList(cl);
			printf(">> 메모리를 해제하고 종료합니다.\n");
			return 0;

		default:
			printf(">> 올바른 메뉴 번호를 입력하세요.\n");
			break;
		}
	}
}