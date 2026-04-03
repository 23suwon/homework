#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int arr[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (N + 1);  
    }

    
    printf("처음부터 끝까지: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("뒤에서부터 처음: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    return 0;
} 