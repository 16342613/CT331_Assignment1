#ifndef CT331_ASSIGNMENT_LINKED_LIST_2
#define CT331_ASSIGNMENT_LINKED_LIST_2

typedef void(*printFuncPointer)(void* data);

typedef struct listElementStruct listElement;

listElement* createEl(char* data, size_t size, void* (funcPointer)(void* data));

void traverse(listElement* start);

listElement* insertAfter(listElement* el, char* data, size_t size, void* funcPointer);

void deleteAfter(listElement* after);

int length(listElement* head);

void push(listElement** head, char* data, size_t size, void* funcPointer);

listElement* pop(listElement** head);

void enqueue(listElement** head, char* data, size_t size, void* funcPointer);

listElement* dequeue(listElement* queueHead);

void printChar(void* data);

void printStr(char* data);

void printInt(int* data);

void printDouble(double* data);


#endif