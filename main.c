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

    printf("�������� ��������:\n");
    printf("1: ���� ������� �������.\n");
    printf("2: ������� ������ �� ����� ����� input.txt.\n");
    printf("3: ������� ���� � �������� ��������� �����.\n");

    char operation = getchar();
    getchar();

    switch (operation)
    {
    case '1': {
        printf("������� ������ ����� ����� ������:\n");
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

        time_t startTime = clock();; // ��������� �����
        shellSort(arrayNum, currentCount); // ���������� �������
        time_t endTime = clock();; // �������� �����

        outputFile(arrayNum, currentCount);
        printf("��������������� ������ ������� � ���� output.txt");

        double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // ����� ����� ����������
        printf("\n����� ����������: %.3f\n", totalTime);

        free(arrayNum);

        break;
    }

    case '2': {
        int sizeArr = NULL;
        int* arrayNum = readFile(&sizeArr);
        if (arrayNum != NULL) {
            time_t startTime = clock();; // ��������� �����
            shellSort(arrayNum, sizeArr); // ���������� �������
            time_t endTime = clock();; // �������� �����

            outputFile(arrayNum, sizeArr);
            printf("��������������� ������ ������� � ���� output.txt");

            double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // ����� ����� ����������
            printf("\n����� ����������: %.3f\n", totalTime);
        }
        else printf("������ ������ �����.");

        break;
    }
    case '3': {
        int sizeArr;
        printf("������� ������ ��������� �������:\n");
        scanf("%d", &sizeArr);
        createFile(sizeArr);

        int* arrayNum = readFile(&sizeArr);
        if (arrayNum != NULL) {
            time_t startTime = clock();; // ��������� �����
            shellSort(arrayNum, sizeArr); // ���������� �������
            time_t endTime = clock();; // �������� �����

            outputFile(arrayNum, sizeArr);
            printf("��������������� ������ ��������� ����� ������� � ���� input.txt,\n � ��������������� ��� ������� ������� ������� � ���� output.txt");

            double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // ����� ����� ����������
            printf("\n����� ����������: %.3f\n", totalTime);
        }
        else printf("������ ������ �����.");

        break;
    }

    default:
        break;
    }
}
