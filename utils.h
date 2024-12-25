#ifndef UTILS_H // Include guard to prevent multiple inclusions
#define UTILS_H

typedef struct {
    int isValid;
    char *left;
    char *right;
} mulStruct;

int max(int *list, int length);
int min(int *list, int length);
int compare(const void* a, const void* b);
int abs(int val);
char* copyString(char *toCopy, int length);
int **makeRemove1List(int *list, int length);
int isSafeDamperList (int *list, int length);
int isSafeList(int *list, int length);
void printArray(int *arr, int length);
mulStruct *makeMulStruct(char *string, int length);
char *slice(const char* str, size_t start, size_t end);
int isNumber(char *str);

#endif