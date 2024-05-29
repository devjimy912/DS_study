#include <iostream>

typedef struct {
	int key;
	// other elements
} Element;

typedef struct {
   Element *stack;	   // for dynamically allocated array
   int max_size;	   // maximum size
   int top;		   // stack top
} Stack;

