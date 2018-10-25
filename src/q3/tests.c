#include <stdio.h>
#include "genericLinkedList.h"

void runTests() {
	// Make a char print function pointer
	void(*printCharPointer)(void* data);
	printCharPointer = printChar;

	// Make a string print function pointer
	void(*printStrPointer)(void* data);
	printStrPointer = printStr;

	// Make an int print function pointer
	void(*printIntPointer)(void* data);
	printIntPointer = printInt;

	// Make a double print function pointer
	void(*printDoublePointer)(void* data);
	printDoublePointer = printDouble;

	double f = 25.0;
	double *p = &f;

	double k = 45.0;
	int *kp = &k;

	double m = 55.0;
	double *mp = &m;
	int i = 1;
	int l = 5;
	int u = 2;
	printIntPointer(10);
	printCharPointer("C");
	printDoublePointer(p);
	printf("%f", *p);

	printf("\n----------------Test 1---------------\n\n");
	listElement* head = createEl("This is CT331", 30, printStrPointer);
	listElement* element2 = insertAfter(head, p, 30, printDoublePointer);
	listElement* element3 = insertAfter(element2, "C", 30, printCharPointer);
	listElement* element4 = insertAfter(element3, &i, 30, printIntPointer);
	printf("Here are the added elements:\n");
	traverse(head);  // Traverse from the head node
	int lengthOfList = length(head);
	printf("\nWe have %d elements in the list\n", lengthOfList);
	printf("\nNow I'm going to remove all elements except the head\n");
	// Deleting some elements
	deleteAfter(head);
	deleteAfter(head);
	deleteAfter(head);
	lengthOfList = length(head);
	printf("\nHere is whats left in the linked list:\n");
	traverse(head);  // Traverse from the head node
	printf("\nWe have %d elements in the list\n", lengthOfList);

	printf("\n----------------Test 2---------------\n\n");
	// Add elements
	listElement* stackHead = createEl(&l, 30, printIntPointer);
	push(&stackHead, "Programming", 30, printStrPointer);
	push(&stackHead, kp, 30, printDoublePointer);
	push(&stackHead, "K", 30, printCharPointer);
	printf("Here are the pushed elements:\n");
	traverse(stackHead);  // Traverse from the head node
	int lengthOfStack = length(stackHead);
	printf("\nWe have %d elements in the stack\n", lengthOfStack);
	printf("\nNow I'm going to pop the 3rd push:\n");
	listElement* popped = pop(&stackHead);
	printf("\nHere is whats left in the stack:\n");
	traverse(stackHead);
	lengthOfStack = length(stackHead);
	printf("\nWe have %d elements in the stack\n", lengthOfStack);

	printf("\n----------------Test 3---------------\n\n");
	// Add elements
	listElement* queueHead = createEl("I", 30, printCharPointer);
	enqueue(&queueHead, "Paradigms", 30, printStrPointer);
	enqueue(&queueHead, mp, 30, printDoublePointer);
	enqueue(&queueHead, &u, 30, printIntPointer);
	printf("Here are the queued elements:\n");
	traverse(queueHead);  // Traverse from the head node
	int lengthOfQueue = length(queueHead);
	printf("\nWe have %d elements in the queue\n", lengthOfQueue);
	printf("\nNow I'm going to dequeue 2 elements:\n");
	listElement* dequeuedElement = dequeue(queueHead);
	listElement* dequeuedElement2 = dequeue(queueHead);
	printf("\nHere is whats left in the queue:\n");
	traverse(queueHead);
	lengthOfQueue = length(queueHead);
	printf("\nWe have %d elements in the queue\n", lengthOfQueue);

}
