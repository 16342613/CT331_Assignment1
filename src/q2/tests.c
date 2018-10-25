#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
	printf("----------------My tests ---------------\n");
	listElement* stackHead = createEl("Initial stack node", 30);
	listElement* queueHead = createEl("Initial queue node", 30);

	push(&stackHead, "1st push", 30);
	push(&stackHead, "2nd push", 30);
	push(&stackHead, "3rd push", 30);
	int lengthOfList = length(stackHead);
	printf("\nThe length of the list is %d\n", lengthOfList);
	listElement* popped = pop(&stackHead);
	traverse(stackHead);

	printf("\nQueue tests:\n");

	enqueue(&queueHead, "1st queued", 30);
	enqueue(&queueHead, "2nd queued", 30);
	enqueue(&queueHead, "3rd queued", 30);
	listElement* dequeuedElement = dequeue(queueHead);
	listElement* dequeuedElement2 = dequeue(queueHead);

	traverse(queueHead);
}
