#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
struct Queue
{
	int size;
	unsigned capacity;
	int* array;
    int front;
	int rear;
};

typedef struct Queue Queue_t;

// Function to create a queue of given capacity. It initializes the size of queue as 0.
Queue_t* createQueue (unsigned capacity)
{
    Queue_t* queue = (Queue_t*) malloc(sizeof(Queue_t));

    // Define queue elements
	queue->size = 0;
    queue->capacity = capacity;
	queue->front = 0;
	queue->rear = capacity - 1;
	queue->array = (int*) malloc(queue->capacity * sizeof(int));

    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull (Queue_t* queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty (Queue_t* queue)
{
    return (queue->size == 0);
}

// Queue size
int sizeQueue (Queue_t* queue)
{
	return queue->size;
}

// Function to add an item to the queue. It changes rear and size.
void enqueue (Queue_t* queue, int item)
{
	if (!isFull(queue))
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size = queue->size + 1;
        printf("\nEnqueue: %d\n", item);
    }
    else
    {
        printf("\nQueue is full. Couldn't enqueue element.\n");
    }
}

// Function to remove an item from queue. It changes front and size.
int dequeue (Queue_t* queue)
{
    int ret = INT_MIN;

	if (!isEmpty(queue))
    {
        ret = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
    }
    else
    {
        printf("\nQueue is empty. Couldn't dequeue any element.\n");
    }

	return ret;
}

// Function to get the front element of the queue
int front (Queue_t* queue)
{
    int ret = INT_MIN;

	if (!isEmpty(queue))
    {
        ret = queue->array[queue->front];
    }
    else
    {
        printf("\nQueue is empty.\n");
    }

	return ret;
}

// Function to get rear of queue
int rear (Queue_t* queue)
{
    int ret = INT_MIN;

	if (!isEmpty(queue))
    {
        ret = queue->array[queue->rear];
    }
    else
    {
        printf("\nQueue is empty.\n");
    }

	return ret;
}


int main()
{
	Queue_t* queue = createQueue(10);

	// isEmpty()
	if (isEmpty(queue))
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue is not empty.\n");
    }

	// isFull()
	if (isFull(queue))
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nQueue is not full.\n");
    }

	// sizeQueue()
	printf("\nQueue size: %d\n", sizeQueue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// front()
	printf("\nFront: %d\n", front(queue));

	// rear()
	printf("\nRear: %d\n", rear(queue));

	// enqueue()
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	enqueue(queue, 50);

	// isEmpty()
	if (isEmpty(queue))
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue is not empty.\n");
    }

	// isFull()
	if (isFull(queue))
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nQueue is not full.\n");
    }

	// sizeQueue()
	printf("\nQueue size: %d\n", sizeQueue(queue));

	// front()
	printf("\nFront: %d\n", front(queue));

	// rear()
	printf("\nRear: %d\n", rear(queue));

	// enqueue()
	enqueue(queue, 60);
	enqueue(queue, 70);
	enqueue(queue, 80);
	enqueue(queue, 90);
	enqueue(queue, 100);
	enqueue(queue, 110);
	enqueue(queue, 120);

	// isEmpty()
	if (isEmpty(queue))
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue is not empty.\n");
    }

	// isFull()
	if (isFull(queue))
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nQueue is not full.\n");
    }

    // sizeQueue()
	printf("\nQueue size: %d\n", sizeQueue(queue));

	// front()
	printf("\nFront: %d\n", front(queue));

	// rear()
	printf("\nRear: %d\n", rear(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// isEmpty()
	if (isEmpty(queue))
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue is not empty.\n");
    }

	// isFull()
	if (isFull(queue))
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nQueue is not full.\n");
    }

    // sizeQueue()
	printf("\nQueue size: %d\n", sizeQueue(queue));

	// front()
	printf("\nFront: %d\n", front(queue));

	// rear()
	printf("\nRear: %d\n", rear(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// dequeue()
	printf("\nDequeue: %d\n", dequeue(queue));

	// isEmpty()
	if (isEmpty(queue))
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue is not empty.\n");
    }

	// isFull()
	if (isFull(queue))
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        printf("\nQueue is not full.\n");
    }

    // sizeQueue()
	printf("\nQueue size: %d\n", sizeQueue(queue));

	// front()
	printf("\nFront: %d\n", front(queue));

	// rear()
	printf("\nRear: %d\n", rear(queue));

	return 0;
}
