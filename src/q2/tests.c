#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

// Testing insertAfter(), deleterAfter(), traverse(), and length()
void testOne() {
	// Add elements
	printf("\n----------------Test 1---------------\n\n");
	listElement* head = createEl("Head", 30);
	listElement* element2 = insertAfter(head, "element2", 30);
	listElement* element3 = insertAfter(element2, "element3", 30);
	listElement* element4 = insertAfter(element3, "element4", 30);
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
}

// Testing stack implementation methods
void testTwo() {
	printf("\n----------------Test 2---------------\n\n");
	// Add elements
	listElement* stackHead = createEl("Initial stack node", 30);
	push(&stackHead, "1st push", 30);
	push(&stackHead, "2nd push", 30);
	push(&stackHead, "3rd push", 30);
	printf("Here are the pushed elements:\n");
	traverse(stackHead);  // Traverse from the head node
	int lengthOfList = length(stackHead);
	printf("\nWe have %d elements in the stack\n", lengthOfList);
	printf("\nNow I'm going to pop the 3rd push:\n");
	listElement* popped = pop(&stackHead);
	printf("\nHere is whats left in the stack:\n");
	traverse(stackHead);
	lengthOfList = length(stackHead);
	printf("\nWe have %d elements in the stack\n", lengthOfList);
}

void testThree() {
	printf("\n----------------Test 3---------------\n\n");
	// Add elements
	listElement* queueHead = createEl("Initial queue node", 30);
	enqueue(&queueHead, "1st queued", 30);
	enqueue(&queueHead, "2nd queued", 30);
	enqueue(&queueHead, "3rd queued", 30);
	printf("Here are the queued elements:\n");
	traverse(queueHead);  // Traverse from the head node
	int lengthOfList = length(queueHead);
	printf("\nWe have %d elements in the queue\n", lengthOfList);
	printf("\nNow I'm going to dequeue 2 elements:\n");
	listElement* dequeuedElement = dequeue(queueHead);
	listElement* dequeuedElement2 = dequeue(queueHead);
	printf("\nHere is whats left in the queue:\n");
	traverse(queueHead);
	lengthOfList = length(queueHead);
	printf("\nWe have %d elements in the queue\n", lengthOfList);
}

void runTests(){
	// Run the unit tests
	testOne();
	testTwo();
	testThree();
}
