#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


// DAY 1.1
typedef struct {
    int **inputList;
    int length;
} input1Struct;

input1Struct makeInput1() {
    FILE *file1;
    FILE *file2;
    char buffer[255];
    file1 = fopen("inputs/1.txt", "r");
    file2 = fopen("inputs/1.txt", "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int fileLength = 0;
    while (fgets(buffer, 255, file1) != NULL) { fileLength++; }
    int **list;
    list = (int **)malloc(fileLength * sizeof(int *));
    for (int i = 0; i < fileLength; i++) {
        list[i] = (int *)malloc(2 * sizeof(int));
    }
    
    char *delimiter = "   ";
    int row = 0;
    while (fgets(buffer, 255, file2) != NULL) {
        char* eachNum = strtok(buffer, delimiter);
        int col = 0;
        while (eachNum != NULL) {
            int number = atoi(eachNum);
            list[row][col] = number;
            // printf("[%d, %d]: %d\n", row, col, number);
            col ++;
            eachNum = strtok(NULL, delimiter);
        }
        row++;
    }
    // printf("%lu", sizeof(list)/sizeof(list[0]));
    input1Struct ret;
    ret.inputList = list;
    ret.length = fileLength;
    return ret;
} 

int aoc1_1(input1Struct input1) {
    int **inputList = input1.inputList;
    int length = input1.length;
    int *list1;
    int *list2;
    list1 = (int *)malloc(length * sizeof(int));
    list2 = (int *)malloc(length * sizeof(int));
    for (int i = 0; i<length; i ++) {
        list1[i] = inputList[i][0];
        list2[i] = inputList[i][1];
    }

    qsort(list1, length, sizeof(int), compare);
    qsort(list2, length, sizeof(int), compare);

    int total = 0;
    for (int i = 0; i<length; i++) {
        int leftVal = list1[i];
        int rightVal = list2[i];

        int difference = leftVal - rightVal;
        if (difference < 0) {
            difference *= -1;
        }

        total += difference;

    }

    return total;
}

//DAY 1.2

int aoc1_2(input1Struct input1) {
    int **inputList = input1.inputList;
    int length = input1.length;

    int *list1;
    int *list2;
    list1 = (int *)malloc(length * sizeof(int));
    list2 = (int *)malloc(length * sizeof(int));
    for (int i = 0; i<length; i ++) {
        list1[i] = inputList[i][0];
        list2[i] = inputList[i][1];
    }

    int max1 = max(list1, length);
    int max2 = max(list2, length);

    int *freqList;
    if (max1 > max2) {
        freqList = (int *)malloc(max1 * sizeof(int));
    } else {
        freqList = (int *)malloc(max2 * sizeof(int));
    }

    for (int i = 0; i<length; i++) {
        int currNum = list2[i];
        freqList[currNum]+=1;
    }

    int total = 0;
    for (int i = 0; i<length; i++) {
        int currNum = list1[i];
        total += currNum*freqList[currNum];
    }

    return total;
}

//DAY 2

typedef struct {
    char **inputStrings;
    int length;
} input2Struct;

input2Struct makeInput2() {
    FILE *file1;
    FILE *file2;
    char buffer[255];
    file1 = fopen("inputs/2.txt", "r");
    file2 = fopen("inputs/2.txt", "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int fileLength = 0;
    while (fgets(buffer, 255, file1) != NULL) { fileLength++; }
    char **list;
    list = (char **)malloc(fileLength * sizeof(char *));
    for (int i = 0; i < fileLength; i++) {
        list[i] = (char *)malloc(300 * sizeof(char));
    }

    char *delimiter = " ";
    int row = 0;
    while (fgets(buffer, 255, file2) != NULL) {
        strcpy(list[row], buffer);
        row++;
    }
    input2Struct ret;
    ret.inputStrings = list;
    ret.length = fileLength;
    return ret;
}

int aoc2_1(input2Struct input2) {
    char **inputStrings = input2.inputStrings;
    int length = input2.length;
    int safeReports = 0;
    char *delimiter = " ";
    for (int row = 0; row<length; row++) {
        int col = 0;
        char *fullString = copyString(inputStrings[row], 255);
        char *eachString = strtok(fullString, delimiter);
        int *eachArr;
        eachArr = (int *)malloc(100 * sizeof(int));

        while (eachString != NULL) {
            int number = atoi(eachString);
            eachArr[col] = number;
            col++;
            eachString = strtok(NULL, delimiter);
        }

        int isSafe = isSafeList(eachArr, col);
        if (isSafe) {
            safeReports++;
        }
    }
    return safeReports;
}

int aoc2_2(input2Struct input2) {
    char **inputStrings = input2.inputStrings;
    int length = input2.length;
    int safeReports = 0;
    char *delimiter = " ";
    for (int row = 0; row<length; row++) {
        int col = 0;
        char *fullString = copyString(inputStrings[row], 255);
        char *eachString = strtok(fullString, delimiter);
        int *eachArr;
        eachArr = (int *)malloc(100 * sizeof(int));

        while (eachString != NULL) {
            int number = atoi(eachString);
            eachArr[col] = number;
            col++;
            eachString = strtok(NULL, delimiter);
        }

        int isSafeDamper = isSafeDamperList(eachArr, col);
        if (isSafeDamper) {
            safeReports++;
        }
    }
    return safeReports;
}

int main()
{
    //DAY 1.1
    input1Struct input1 = makeInput1();
    int aoc1_1_output = aoc1_1(input1);
    printf("The answer to Day 1.1 is: %d\n", aoc1_1_output);

    //DAY 1.2
    int aoc1_2_output = aoc1_2(input1);
    printf("The answer to Day 1.2 is: %d\n", aoc1_2_output);

    //DAY 2.1
    input2Struct input2 = makeInput2();
    int aoc2_1_output = aoc2_1(input2);
    printf("The answer to Day 2.1 is: %d\n", aoc2_1_output);

    //DAY 2.2
    int aoc2_2_output = aoc2_2(input2);
    printf("The answer to Day 2.2 is: %d\n", aoc2_2_output);

    return 0;
}