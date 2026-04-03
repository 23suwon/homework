#include <stdio.h>

#define N 5  

int main() {
    int arr[N][N] = { 0 };

    int row = 0;
    int col = N / 2;

    for (int num = 1; num <= N * N; num++) {
        arr[row][col] = num;

        int nextRow = (row - 1 + N) % N;  
        int nextCol = (col + 1) % N;      

        if (arr[nextRow][nextCol] != 0) {
            row = (row + 1) % N;          
        }
        else {
            row = nextRow;
            col = nextCol;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

   
    int sum = N * (N * N + 1) / 2;  

    
    printf("\n[가로]\n");
    for (int i = 0; i < N; i++) {
        int sum = 0;
        printf("행 %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
            sum += arr[i][j];
        }
        printf(" → 합: %d\n", sum);
    }

    printf("\n[세로]\n");
    for (int j = 0; j < N; j++) {
        int sum = 0;
        printf("열 %d: ", j + 1);
        for (int i = 0; i < N; i++) {
            printf("%4d", arr[i][j]);
            sum += arr[i][j];
        }
        printf(" → 합: %d\n", sum);
    }

    printf("\n[대각선]\n");

    int sum1 = 0;
    printf("대각선(↘): ");
    for (int i = 0; i < N; i++) {
        printf("%4d", arr[i][i]);
        sum1 += arr[i][i];
    }
    printf(" → 합: %d\n", sum1);

    int sum2 = 0;
    printf("대각선(↙): ");
    for (int i = 0; i < N; i++) {
        printf("%4d", arr[i][N - 1 - i]);
        sum2 += arr[i][N - 1 - i];
    }
    printf(" → 합: %d\n", sum2);

    return 0;
}