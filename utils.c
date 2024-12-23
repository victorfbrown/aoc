#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int max(int *list, int length) {
    int maxVal = list[0];
    for (int i = 1; i < length; i ++) {
        int currVal = list[i];
        if (currVal > maxVal) {
            maxVal = currVal;
        }
    }
    return maxVal;
}

int min(int *list, int length) {
    int minVal = list[0];
    for (int i = 1; i < length; i ++) {
        int currVal = list[i];
        if (currVal > minVal) {
            minVal = currVal;
        }
    }
    return minVal;
}

int abs(int val) {
    return (val < 0) ? val*-1 : val;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

char* copyString(char *toCopy, int length) {
        char *fullString;
        fullString = (char *)malloc(length * sizeof(char));
        strcpy(fullString,toCopy);
        return fullString;
}

int **makeRemove1List(int *list, int length) {
    int **newList;
    newList = (int **)malloc(length * (sizeof(int *)));
    for (int i = 0; i<length; i++) {
        newList[i] = (int *)malloc(length * sizeof(int));
        int shiftLeft = 0;
        // printf("[");
        for (int j = 0; j<length; j++) {
            int skipThis = 0;
            if (i == j) {
                shiftLeft = -1;
                continue;
            }
            // printf("%d ", list[j]);
            newList[i][j+shiftLeft] = list[j];
        }
        // printf("]\n");
    }

    return newList;
}

int isSafeList(int *list, int length) {
    int isSafe = 1;
    int isDecreasing = 0;
    int isIncreasing = 0;
    int prevNum = -1;
    for (int col = 0; col < length; col ++) {
        int number = list[col];
        if (col != 0) {
            int difference = number - prevNum;
            if (difference > 0 && isDecreasing || difference < 0 && isIncreasing || difference == 0 || abs(difference) > 3) {
                isSafe = 0;
                break;
            }
            if (difference < 0) {
                isDecreasing = 1;
            } else {
                isIncreasing = 1;
            }
        }
        prevNum = number;
    }
    return isSafe;
}

int isSafeDamperList (int *list, int length) {
    int **damperList = makeRemove1List(list, length);
    for (int i = 0; i<length; i++) {
        int isDecreasing = 0;
        int isIncreasing = 0;
        int *eachList = damperList[i];
        int listValidity = isSafeList(eachList, length-1);
        if (listValidity) {
            return 1;
        }
    }
    return 0;
}


void printArray(int *arr, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i != length-1) {
            printf(", ");
        }
    }
    printf("]\n");
    return;
}

char *slice(const char* str, size_t start, size_t end) {
    char *string;
    string = (char *)malloc(end-start * sizeof(char));
    strncpy(string, str + start, end - start);
    return string;
}


mulStruct *makeMulStruct(char *string, int length) {
    mulStruct *structLists;
    structLists = (mulStruct *)malloc(length * sizeof(mulStruct));

    int iterator = 0;
    int mulStructIterator = 1;
    while (iterator < length-3) {
        char *slicedString = slice(string, iterator, iterator+4);
        int isMul = !strcmp("mul(", slicedString);
        // printf("%d\n", iterator);
        if (isMul) {
            // printf("%d: %s\n", iterator, slicedString);
            char *firstArg;
            char *secondArg;
            firstArg = strtok(slice(string, iterator+4, strlen(string)), ",");
            secondArg = strtok(NULL, ")");
            // printf("%s\n", firstArg);
            // printf("%s\n", secondArg);
            mulStruct m;
            m.left = firstArg;
            m.right = secondArg;
            structLists[mulStructIterator] = m;
            mulStructIterator++;
        }
        iterator++;
    }
    mulStruct m;
    int strLength = snprintf( NULL, 0, "%d", mulStructIterator);
    char* str = malloc(strLength + 1 );
    snprintf( str, strLength + 1, "%d", mulStructIterator);
    m.left = "NUMSTRUCTS";
    m.right = str;
    structLists[0] = m;
    return structLists;
}
    
    
    // for (int i = 0; i<length; i++) {
    //     char currStr[3] = "\0";
    //     currStr[0] = '1';
    //     currStr[1] = string[i];
    //     int currNum = atoi(currStr);
    //     currNum -= 10;
    //     if (currNum > 0) {
    //         printf("%d\n", currNum);
    //     }


        // printf("%s\n", currStr);
        // return structLists;