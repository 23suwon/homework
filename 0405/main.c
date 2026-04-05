#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n;
    printf("N: ");
    scanf_s("%d", &n);


    int* arr = (int*)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int* p = arr; p < arr + n; p++) {
        *p = rand() % (n + 1);  
    }

    printf("\n처음부터 끝까지: ");
    for (int* p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }

    printf("\n뒤에서부터 처음: ");
    for (int* p = arr + n - 1; p >= arr; p--) {
        printf("%d ", *p);
    }

    int sum = 0;
    int max = *arr;
    int min = *arr;

    for (int* p = arr; p < arr + n; p++) {
        sum += *p;
        if (*p > max) max = *p;
        if (*p < min) min = *p;
    }

    printf("\nsum: %d", sum);
    printf("\nMax: %d", max);
    printf("\nMin: %d\n", min);

   

    return 0;
}