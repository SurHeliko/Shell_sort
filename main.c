#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include "mainFunctions.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Выберите действие:\n");
    printf("1: Ввод массива вручную.\n");
    printf("2: Считать массив из файла ввода input.txt.\n");
    printf("3: Создать файл с массивом случайных чисел.\n");

    char operation = getchar();
    getchar();

    switch (operation)
    {
    case '1': {
        printf("Введите массив чисел через пробел:\n");
        int currentCount = 0, sizeArray = 10;
        int *arrayNum = malloc(sizeArray * sizeof(int));
        char c;

        while (scanf("%d%c", &arrayNum[currentCount++], &c) == 2) {
            if (currentCount >= sizeArray) {
                sizeArray *= 2;
                arrayNum = realloc(arrayNum, sizeArray * sizeof(int));
            }
            if (c == '\n') break;
        }
        arrayNum = realloc(arrayNum, --currentCount * sizeof(int));

        time_t startTime = clock();; // начальное время
        shellSort(arrayNum, currentCount); // сортировка массива
        time_t endTime = clock();; // конечное время

        outputFile(arrayNum, currentCount);
        printf("Отсортированный массив сохранён в файл output.txt");

        double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // общее время сортировки
        printf("\nВремя сортировки: %.3f\n", totalTime);

        free(arrayNum);

        break;
    }

    case '2': {
        int sizeArr = NULL;
        int* arrayNum = readFile(&sizeArr);
        if (arrayNum != NULL) {
            time_t startTime = clock();; // начальное время
            shellSort(arrayNum, sizeArr); // сортировка массива
            time_t endTime = clock();; // конечное время

            outputFile(arrayNum, sizeArr);
            printf("Отсортированный массив сохранён в файл output.txt");

            double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // общее время сортировки
            printf("\nВремя сортировки: %.3f\n", totalTime);
        }
        else printf("Ошибка чтения файла.");

        break;
    }
    case '3': {
        int sizeArr;
        printf("Введите размер желаемого массива:\n");
        scanf("%d", &sizeArr);
        createFile(sizeArr);

        int* arrayNum = readFile(&sizeArr);
        if (arrayNum != NULL) {
            time_t startTime = clock();; // начальное время
            shellSort(arrayNum, sizeArr); // сортировка массива
            time_t endTime = clock();; // конечное время

            outputFile(arrayNum, sizeArr);
            printf("Сгенерированный массив случайных чисел сохранён в файл input.txt,\n а отсортированный вид данного массива сохранён в файл output.txt");

            double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // общее время сортировки
            printf("\nВремя сортировки: %.3f\n", totalTime);
        }
        else printf("Ошибка чтения файла.");

        break;
    }

    default:
        break;
    }
}
