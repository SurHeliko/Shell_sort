#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shellSort(int* arr, int cntEl);
int createFile(const char* fileName, int sizeArray);
int* readFile(const char* fileName);


int main() {
    srand(time(NULL)); // привязка рандома к времени

    int sizeArray = 10;

    createFile("file.txt", sizeArray); // создание файла с рандомными числами

    int* arrayNum = readFile("file.txt"); // чтение файла и задание массива
    if (arrayNum == NULL) {
        printf("ERROR: array reading error");
        return 1;
    }

    time_t startTime = time(NULL); // начальное время
    shellSort(arrayNum, sizeArray); // сортировка массива
    time_t endTime = time(NULL); // конечное время

    time_t totalTime = startTime - endTime; // общее время сортировки
    printf("Sorted array:\n");
    for (int i = 0; i < sizeArray; i++) printf("%d ", arrayNum[i]); // вывод массива
    printf("\nSorting time: %d\n", totalTime);

    return 0;
}

void shellSort(int* arr, int cntEl) {
    for (int step = cntEl / 2; step > 0; step /= 2) // shell сортировка с шагом в половину элементов
    for (int i = step; i < cntEl; i++) {
        int temp = arr[i];
        int k;
        for (k = i; k >= step && arr[k - step] > temp; k -= step) {
            arr[k] = arr[k - step];
        }
        arr[k] = temp;
    }
}


int createFile(const char* fileName, int sizeArray) {
    FILE* file = fopen(fileName, "w"); // открытие файла
    if (file == NULL) {
        printf("\nERROR: file creation error\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < sizeArray; i++) fprintf(file, "%d\n", rand() % 100 - 50); // заполнение файла

    fclose(file); // закрытие файла

    return 0;
}


int* readFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");// открытие файла
    if (file == NULL) {
        printf("\nERROR: file reading error\n");
        fclose(file);
        return NULL;
    }

    int count = 0;
    int* numbers = malloc(count * sizeof(int));
    int num;


    while (fscanf(file, "%d", &num) == 1) {// с каждым считанным элементом размер массива перезадаётся (переделаю)
        numbers = realloc(numbers, ++count * sizeof(int));
        numbers[count - 1] = num;
    }

    fclose(file);// закрытие файла

    return numbers;
}