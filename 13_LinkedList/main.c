#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

void printMenu() {
    printf("정수 연결 리스트 메뉴\n");
    printf("1. 맨 앞에 추가\n");
    printf("2. 맨 뒤에 추가\n");
    printf("3. 특정 위치에 추가\n");
    printf("4. 특정 위치 삭제\n");
    printf("5. 전체 목록 출력\n");
    printf("6. 리스트 크기 확인\n");
    printf("0. 종료\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("선택 >> ");
}

int main() {
    LinkedList* li = createLinkedList();
    int choice, value, index;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("  추가할 정수 입력: ");
            scanf("%d", &value);
            insertFirstLinkedList(li, value);
            printf("  %d  맨 앞에 추가했습니다.\n", value);
            printLinkedList(li);
            break;

        case 2:
            printf("  추가할 정수 입력: ");
            scanf("%d", &value);
            insertLastLinkedList(li, value);
            printf("  %d 을(를) 맨 뒤에 추가했습니다.\n", value);
            printLinkedList(li);
            break;

        case 3:
            printf("  삽입할 위치(0 ~ %d) 입력: ", li->size);
            scanf("%d", &index);
            printf("  추가할 정수 입력: ");
            scanf("%d", &value);
            insertAtLinkedList(li, index, value);
            printf("  %d번 위치에 %d 을(를) 추가했습니다.\n", index, value);
            printLinkedList(li);
            break;

        case 4:
            if (isEmptyLinkedList(li)) {
                printf("  [오류] 리스트가 비어 있습니다.\n");
                break;
            }
            printf("  삭제할 위치(0 ~ %d) 입력: ", li->size - 1);
            scanf("%d", &index);
            value = deleteAtLinkedList(li, index);
            if (li->size >= 0)  
                printf("  %d번 위치의 값 %d 을(를) 삭제했습니다.\n", index, value);
            printLinkedList(li);
            break;

        case 5:
            printf("  현재 리스트:\n");
            printLinkedList(li);
            break;

        case 6:
            printf("  현재 리스트 크기: %d\n", sizeLinkedList(li));
            break;

        case 0:
            destroyLinkedList(li);
            return 0;

        default:
            printf("0 ~ 6 사이의 번호를 입력하세요.\n");
            break;
        }
    }
}