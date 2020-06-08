#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a stack
struct stack
{
	int top;
	unsigned capacity;
	int* array;
};

typedef struct stack Stack_t;

// function to create a stack of given capacity. It initializes size of stack as 0
Stack_t* Stack_Create (unsigned capacity)
{
	// Declare stack
	Stack_t* stack = (Stack_t*) malloc(sizeof(Stack_t));

	// Define stack
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	return stack;
}

// Stack is full when top is equal to the last index
bool Stack_IsFull (Stack_t* stack)
{
	return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
bool Stack_IsEmpty (Stack_t* stack)
{
	return (stack->top == -1);
}

// Stack size
int Stack_Size (Stack_t* stack)
{
	return (stack->top + 1);
}

// Function to add an item to stack. It increases top by 1
void Stack_Push (Stack_t* stack, int item)
{
	if (!Stack_IsFull(stack))
	{
	    int index = stack->top + 1;

	    stack->array[index] = item;

	    printf("\nStack push: %d\n", item);

	    stack->top++;
	}
	else
    {
        printf("\nStack is full. Couldn't push element to stack.\n");
    }
}

// Function to remove an item from stack. It decreases top by 1
int Stack_Pop (Stack_t* stack)
{
    int ret = INT_MIN;

	if (!Stack_IsEmpty(stack))
    {
        ret = stack->array[stack->top];

        stack->top--;
    }

	return ret;
}

// Function to return the top from stack without removing it
int Stack_Peek (Stack_t* stack)
{
    int ret = INT_MIN;

	if (!Stack_IsEmpty(stack))
    {
        ret = stack->array[stack->top];
    }

	return ret;
}

// Driver program to test above functions
int main()
{
	Stack_t* stack = Stack_Create(10);

	// Stack_IsEmpty()
	if (Stack_IsEmpty(stack))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack is not empty.\n");
    }

	// Stack_IsFull()
	if (Stack_IsFull(stack))
    {
        printf("\nStack is full.\n");
    }
    else
    {
        printf("\nStack is not full.\n");
    }

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

    // Stack_Peek()
	printf("\nStack peek: %d\n", Stack_Peek(stack));

	// Stack_Push()
	Stack_Push(stack, 10);
	Stack_Push(stack, 20);
	Stack_Push(stack, 30);
	Stack_Push(stack, 40);
	Stack_Push(stack, 50);

	// Stack_IsEmpty()
	if (Stack_IsEmpty(stack))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack is not empty.\n");
    }

	// Stack_IsFull()
	if (Stack_IsFull(stack))
    {
        printf("\nStack is full.\n");
    }
    else
    {
        printf("\nStack is not full.\n");
    }

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Peek()
	printf("\nStack peek: %d\n", Stack_Peek(stack));

	// Stack_Push()
	Stack_Push(stack, 60);
	Stack_Push(stack, 70);
	Stack_Push(stack, 80);
	Stack_Push(stack, 90);
	Stack_Push(stack, 100);
	Stack_Push(stack, 110);
	Stack_Push(stack, 120);

	// Stack_IsEmpty()
	if (Stack_IsEmpty(stack))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack is not empty.\n");
    }

	// Stack_IsFull()
	if (Stack_IsFull(stack))
    {
        printf("\nStack is full.\n");
    }
    else
    {
        printf("\nStack is not full.\n");
    }

    // Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

    // Stack_Peek()
	printf("\nStack peek: %d\n", Stack_Peek(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_IsEmpty()
	if (Stack_IsEmpty(stack))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack is not empty.\n");
    }

	// Stack_IsFull()
	if (Stack_IsFull(stack))
    {
        printf("\nStack is full.\n");
    }
    else
    {
        printf("\nStack is not full.\n");
    }

    // Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Peek()
	printf("\nStack peek: %d\n", Stack_Peek(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_IsEmpty()
	if (Stack_IsEmpty(stack))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack is not empty.\n");
    }

	// Stack_IsFull()
	if (Stack_IsFull(stack))
    {
        printf("\nStack is full.\n");
    }
    else
    {
        printf("\nStack is not full.\n");
    }

    // Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

    // Stack_Push()
	Stack_Push(stack, 5);
	Stack_Push(stack, 15);

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Push()
	Stack_Push(stack, 25);
	Stack_Push(stack, 35);

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Push()
	Stack_Push(stack, 45);
	Stack_Push(stack, 55);

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Pop()
	printf("\nStack pop: %d\n", Stack_Pop(stack));

	// Stack_Size()
	printf("\nStack size: %d\n", Stack_Size(stack));

	return 0;
}
