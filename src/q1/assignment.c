// Name: Irish Senthilkumar
// ID: 16342613
// Details: CT331 Programming Paradigms Assignment 1 Q1

#include <stdio.h>

int main(int arg, char* argc[]) {
	// instantiate our instance variables
	int intType;
	int* intPointerType;
	long longType;
	double* doublePointerType;
	char** characterPointerPointerType;

	printf("\n"); // Line break
	printf("The size of type int is %d bytes\n", sizeof(intType));  // Get the size of an int
	printf("The size of type int pointer is %d bytes\n", sizeof(intPointerType));  // Get the size of an int pointer
	printf("The size of type long is %d bytes\n", sizeof(longType));  // Get the size of a long
	printf("The size of type double pointer is %d bytes\n", sizeof(doublePointerType));  // Get the size of a double pointer
	printf("The size of type character pointer pointer is %d bytes\n", sizeof(characterPointerPointerType));  // Get the size of a character pointer pointer
	printf("\n"); // Line break
}
