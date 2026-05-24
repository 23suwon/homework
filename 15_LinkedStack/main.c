#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "LinkedStack.h"

void printMenu() {
    printf("1. URL 추가\n");
    printf("2. URL 제거\n");
    printf("3. 스택 확인\n");
    printf("메뉴 선택: ");
}

int main() {
    LinkedStack* stack = createLinkedStack();
    int choice;
    char url[1024];

    while (1) {
        printMenu();

        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
        case 1:
            printf("URL 입력: ");
            if (fgets(url, 1024, stdin) == NULL) break;

            if (url[0] == '\0') {
                printf("URL을 입력해 주세요.\n");
                break;
            }

            if (pushLinkedStack(stack, url)) {
                printf("현재 창: %s\n", peekLinkedStack(stack));
            }
            
            break;

        case 2:
            if (emptyLinkedStack(stack)) {
                printf("스택이 비어있습니다.\n");
                break;
            }

            stackElement removed = popLinkedStack(stack);
            printf("이탈: %s\n", removed);
            free(removed);

            if (emptyLinkedStack(stack)) {
                destroyLinkedStack(stack);
                printf("브라우저가 종료되었습니다.\n");
                return 0;
            }
            else {
                printf("현재 창: %s\n", peekLinkedStack(stack));
            }
            break;

        case 3:
            if (emptyLinkedStack(stack)) {
                printf("현재 열려있는 창이 없습니다.\n");
            }
            else {
                printf("현재 창: %s\n", peekLinkedStack(stack));
            }
            break;

        default:
            printf("1~3 사이의 메뉴를 선택해 주세요.\n");
            break;
        }
    }

}