#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shellSort(int* arr, int cntEl);
int createFile(int sizeArray);
int* readFile(int *sizeArr);
int outputFile(int* arrayNum, int sizeArray);