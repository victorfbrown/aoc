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
void printIntArray(int *arr, int length);
void printCharArray(char *arr, int length);
mulStruct *makeMulStruct(char *string, int length, int isValid);
char *slice(const char* str, size_t start, size_t end);
int isNumber(char *str);
char *reverse(char *str);
char *selectIndices(char **stringList, int *indicesLength);

#endif