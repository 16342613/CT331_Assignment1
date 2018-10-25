#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef void(*printFuncPointer)(void* data);

typedef struct listElementStruct {
	char* data;
	size_t size;
	struct listElementStruct* next;
	printFuncPointer functionPointer;
	//void* functionPointer;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size, void* (funcPointer)(void* data)) {
	listElement* e = malloc(sizeof(listElement));  // Allocate memory space for listElement type pointer
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	char* dataPointer = malloc(sizeof(char)*size);  // Allocate memory space for a char pointer with size specified in the input parameters
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory, since we can't go any further
		return NULL; //return NULL to indicate an error.
	}
	memcpy(dataPointer, data, size);  // Copy the memory pointed to by data, to dataPointer
	e->data = dataPointer;  // (*e).data = dataPointer
	e->functionPointer = funcPointer;  // (*e).fnctionPointer = funcPointer
	//(e->functionPointer)("OK");
	e->size = size;  // (*e).size = size
	e->next = NULL;  // (*e).next = NULL  no next element
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;  // Create a new listElement that points to the start listElement's address
	while (current != NULL) {  // While current is not null
		current->functionPointer(current->data);

		current = current->next;  // current's address = (*current).next's memory address, effectively pointing to the next element 
	}
}


//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size, void* funcPointer) {
	listElement* newEl = createEl(data, size, funcPointer);  // Create a new element (method above)
	listElement* next = el->next;  // Create a new element called 'next' = (*el).next, where el is the input parameter that precedes the new element
	newEl->next = next;  // (*newEl).next = next
	el->next = newEl;  // (*el).next = next
	return newEl;  // return the new element
}

//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;  // Create a new element = (*after).next
	listElement* newNext = delete->next;  // Create a new element = (*delete).next
	after->next = newNext;  // (*after).next = newNext
	//need to free the memory because we used malloc
	free(delete->data);  // Free (*delete).data
	free(delete);// Free delete pointer
}


// Returns the number of elements in the linked list
int length(listElement* head) {
	int length = 0;
	listElement* currentElement = head;
	while (currentElement != NULL) {
		currentElement = currentElement->next;
		length++;
	}

	return length;
}


// Pushes a new element onto the head of the linked list
void push(listElement** head, char* data, size_t size, void* funcPointer) {
	listElement* elementToPush = createEl(data, size, funcPointer);  // Create the element to be pushed, from th einput parameters
	elementToPush->next = *head;  // pushed element's head is the current head element
	*head = elementToPush; // The new head of the linked list is the element we just pushed
}


// Pops an element from the head of the linked list
listElement* pop(listElement** head) {
	listElement* elementToPop = *head;  // Element to pop points to the head pointer of the linked list
	*head = elementToPop->next;  // Update the head of the linked list
	elementToPop->next = NULL;  // The popped element's next node is null, since we have removed it from the linked list

	return elementToPop;  // Return the popped element
}


//Enqueue a new element onto the head of the list
void enqueue(listElement** head, char* data, size_t size, void* funcPointer) {
	listElement* elementToQueue = createEl(data, size, funcPointer);  // Create the element to be pushed, from th einput parameters
	elementToQueue->next = *head;  // pushed element's head is the current head element
	*head = elementToQueue; // The new head of the linked list is the element we just pushed
}


// Dequeue an element from tthe tail of the list
listElement* dequeue(listElement* queueHead) {
	listElement* toDequeue = queueHead;
	while (toDequeue->next->next != NULL) {
		toDequeue = toDequeue->next;
	}
	listElement* temp = toDequeue->next;
	toDequeue->next = NULL;

	return temp;
}

// Print a char
void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

// Print a string
void printStr(char* data) {
	printf("%s\n", data);
}

// Print an int
void printInt(int* data) {
	printf("%d\n", data);
}

// Print a double
void printDouble(double* data) {
	printf("%f\n", *data);
}

