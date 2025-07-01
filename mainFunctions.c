#define _CRT_SECURE_NO_WARNINGS
#include "mainFunctions.h"



void shellSort(int* arr, int cntEl) {
    for (int step = cntEl / 2; step > 0; step /= 2)
        for (int i = step; i < cntEl; i++) {
            int temp = arr[i];
            int k;
            for (k = i; k >= step && arr[k - step] > temp; k -= step) {
                arr[k] = arr[k - step];
            }
            arr[k] = temp;
        }
}


int createFile(int sizeArray) {
    FILE* file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("\nERROR: file creation error\n");
        fclose(file);
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < sizeArray; i++) fprintf(file, "%d\n", rand());

    fclose(file); 

    return 0;
}


int* readFile(int *sizeArr) {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("\nERROR: file reading error\n");
        fclose(file);
        return NULL;
    }

    int currentCount = 0;
    int sizeArray = 10;
    int* numbers = malloc(sizeArray * sizeof(int));
    int num;


    while (fscanf(file, "%d", &num) == 1) {
        if (++currentCount == sizeArray) {
            sizeArray *= 2;
            numbers = realloc(numbers, sizeArray * sizeof(int));
        }
        numbers[currentCount - 1] = num;
    }
    numbers = realloc(numbers, currentCount * sizeof(int));

    *sizeArr = currentCount;

    fclose(file);

    return numbers;
}


int outputFile(int* arrayNum, int sizeArray) {
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        fclose(file);
        return 1;
    }

    for (int i = 0; i < sizeArray; i++) fprintf(file, "%d\n", arrayNum[i]);

    fclose(file);

    return 0;
}