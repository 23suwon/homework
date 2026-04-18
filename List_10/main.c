#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

void printMenu() {
    printf("  list menu\n");
    printf("1. 삽입 (Insert)\n");
    printf("2. 삭제 (Delete)\n");
    printf("3. 변경 (Replace)\n");
    printf("4. 출력 (Print)\n");
    printf("5. 초기화 (Clear)\n");
    printf("0. 종료 (Exit)\n");
    printf("==============================\n");
    printf("선택 >> ");
}

int main() {
    arrayList* myList = createArrayList(100);
    int choice;
    int pos, value;


    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {

        case 1:  
            printf("삽입할 양의 정수를 입력하세요 >> ");
            scanf("%d", &value);
            if (value <= 0) {
                printf("error \n");
                break;
            }
            printf("삽입할 위치를 입력하세요 (0 ~ %d) >> ", sizeArrayList(myList));
            scanf("%d", &pos);
            if (insertArrayList(myList, pos, value)) {
                printf("위치 %d에 %d을(를) 삽입했습니다.\n", pos, value);
            }
            break;

        case 2:  
            if (isEmptyArrayList(myList)) {
                printf("error 리스트가 비어 있습니다.\n");
                break;
            }
            printf("삭제할 위치를 입력하세요 (0 ~ %d) >> ", sizeArrayList(myList) - 1);
            scanf("%d", &pos);
            int deleted = deleteArrayList(myList, pos);
            if (deleted != -1) {
                printf("위치 %d의 값 %d을(를) 삭제했습니다.\n", pos, deleted);
            }
            break;

        case 3:  
            if (isEmptyArrayList(myList)) {
                printf("error 리스트가 비어 있습니다.\n");
                break;
            }
            printf("change (0 ~ %d) >> ", sizeArrayList(myList) - 1);
            scanf("%d", &pos);
            printf("새로운 양의 정수를 입력하세요 >> ");
            scanf("%d", &value);
            if (value <= 0) {
                printf("error 양의 정수만 입력 가능합니다.\n");
                break;
            }
            if (replaceItemArrayList(myList, pos, value)) {
                printf(" 위치 %d의 값을 %d로 변경했습니다.\n", pos, value);
            }
            break;

        case 4:  
            printf("\n[Now List]\n");
            printArrayList(myList);
            break;

        case 5:  
            initArrayList(myList);
            printf("clear \n");
            break;

        case 0:  
            printf("exit \n");
            destroyArrayList(myList);
            return 0;

        default:
            printf("error ex) 0~5.\n");
            break;
        }
    }
}