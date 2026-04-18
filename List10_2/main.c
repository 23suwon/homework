#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

int** createMatrix(int rows, int cols) {
    int** m = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        m[i] = (int*)calloc(cols, sizeof(int));
    }
    return m;
}

void destroyMatrix(int** m, int rows) {
    for (int i = 0; i < rows; i++) free(m[i]);
    free(m);
}

void printMatrix(int** m, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}


void getHeader(arrayList* al, int* rows, int* cols, int* count) {
    *rows = getItemArrayList(al, 0);
    *cols = getItemArrayList(al, 1);
    *count = getItemArrayList(al, 2);
}

void getElem(arrayList* al, int k, int* r, int* c, int* v) {
    int header = 3;
    int elemSz = 3;
    int base = header + k * elemSz;
    *r = getItemArrayList(al, base);
    *c = getItemArrayList(al, base + 1);
    *v = getItemArrayList(al, base + 2);
}

void matrixToSparseList(int** matrix, int rows, int cols,
    arrayList** alPtr) {
    int header = 3;
    int elemSz = 3;
    int cap = header + rows * cols * elemSz + 10;

    if (*alPtr != NULL) destroyArrayList(*alPtr);
    *alPtr = createArrayList(cap);

    arrayList* al = *alPtr;

    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) count++;

    insertArrayList(al, 0, rows);
    insertArrayList(al, 1, cols);
    insertArrayList(al, 2, count);

    int pos = header;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insertArrayList(al, pos++, i);
                insertArrayList(al, pos++, j);
                insertArrayList(al, pos++, matrix[i][j]);
            }
        }
    }
}

void sparseListToMatrix(arrayList* al, int*** mPtr,
    int* outRows, int* outCols) {
    int rows, cols, count;
    getHeader(al, &rows, &cols, &count);
    *outRows = rows;
    *outCols = cols;

    if (*mPtr != NULL) destroyMatrix(*mPtr, rows);
    *mPtr = createMatrix(rows, cols);

    for (int k = 0; k < count; k++) {
        int r, c, v;
        getElem(al, k, &r, &c, &v);
        (*mPtr)[r][c] = v;
    }
}

long long transposeSparseLists(arrayList* al, arrayList** transPtr) {
    int header = 3;
    int elemSz = 3;
    int rows, cols, count;
    getHeader(al, &rows, &cols, &count);

    int cap = header + count * elemSz + 10;
    if (*transPtr != NULL) destroyArrayList(*transPtr);
    *transPtr = createArrayList(cap);
    arrayList* trans = *transPtr;

    insertArrayList(trans, 0, cols);
    insertArrayList(trans, 1, rows);
    insertArrayList(trans, 2, count);

    long long moveCount = 0;
    int insertPos = header;

    for (int c = 0; c < cols; c++) {
        for (int k = 0; k < count; k++) {
            int r, col, v;
            getElem(al, k, &r, &col, &v);
            if (col == c) {
                moveCount += (trans->size - insertPos);
                insertArrayList(trans, insertPos, c);
                moveCount += (trans->size - insertPos);
                insertArrayList(trans, insertPos + 1, r);
                moveCount += (trans->size - insertPos);
                insertArrayList(trans, insertPos + 2, v);
                insertPos += elemSz;
            }
        }
    }
    return moveCount;
}


int main(void) {

    int rows = 10;
    int cols = 10;
    int nonzero = 20;

    int** matrix = NULL;
    matrix = createMatrix(rows, cols);

    int src[20][3] = {
        {0,1,3},  {0,4,7},
        {1,2,5},  {1,7,2},
        {2,0,8},  {2,5,4},
        {3,3,6},  {3,8,1},
        {4,1,9},  {4,6,3},
        {5,0,2},  {5,4,5},
        {6,2,7},  {6,9,4},
        {7,5,6},  {7,8,8},
        {8,3,1},  {8,7,9},
        {9,0,3},  {9,6,2}
    };
    for (int k = 0; k < nonzero; k++)
        matrix[src[k][0]][src[k][1]] = src[k][2];

    printf("10x10 matrix");
    printMatrix(matrix, rows, cols);

    arrayList* sparseList = NULL;
    matrixToSparseList(matrix, rows, cols, &sparseList);

    arrayList* transList = NULL;
    long long moves = transposeSparseLists(sparseList, &transList);

    int** transMatrix = NULL;
    int tRows, tCols;
    sparseListToMatrix(transList, &transMatrix, &tRows, &tCols);

    printf("transpose matrix");
    printMatrix(transMatrix, tRows, tCols);

    printf(">>> data moves count : %lld 회\n", moves);

    destroyMatrix(matrix, rows);
    destroyMatrix(transMatrix, tRows);
    destroyArrayList(sparseList);
    destroyArrayList(transList);

    return 0;
}