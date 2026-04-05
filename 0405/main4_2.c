#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("홀수 N: \n");
    scanf_s("%d", &n);

    if (n % 2 == 0) {
        printf("홀수를 입력하세요.\n");
        return 1;
    }

    
    int** arr = (int**)malloc(n * sizeof(int*));
    
   
    for (int i = 0; i < n; i++) {
        *(arr + i) = (int*)calloc(n, sizeof(int));
    }

    int row = 0;
    int col = n / 2;

    for (int num = 1; num <= n * n; num++) {
        *(*(arr + row) + col) = num;         

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (*(*(arr + nextRow) + nextCol) != 0) {  
            row = (row + 1) % n;
        }
        else {
            row = nextRow;
            col = nextCol;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int* p = *(arr + i); p < *(arr + i) + n; p++) {
            printf("%4d", *p);
        }
        printf("\n");
    }
    printf("\n");
    int magic = n * (n * n + 1) / 2;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        printf("행 %d:", i + 1);
        for (int* p = *(arr + i); p < *(arr + i) + n; p++) {
            printf("%4d", *p);
            sum += *p;
        }
        printf(" → 합: %d\n", sum);
    }

    
    for (int j = 0; j < n; j++) {
        int sum = 0;
        printf("열 %d:", j + 1);
        for (int i = 0; i < n; i++) {
            printf("%4d", *(*(arr + i) + j));      
            sum += *(*(arr + i) + j);
        }
        printf(" → 합: %d\n", sum);
    }

    

    int sum1 = 0;
    printf("대각선1:");
    for (int i = 0; i < n; i++) {
        printf("%4d", *(*(arr + i) + i));           
        sum1 += *(*(arr + i) + i);
    }
    printf(" → 합: %d\n", sum1);

    int sum2 = 0;
    printf("대각선2:");
    for (int i = 0; i < n; i++) {
        printf("%4d", *(*(arr + i) + (n - 1 - i))); 
        sum2 += *(*(arr + i) + (n - 1 - i));
    }
    printf(" → 합: %d\n", sum2);

    return 0;
}