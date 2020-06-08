#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A linked list (LL) node to store a queue entry
struct QNode
{
    int data;
    struct QNode* next;
};

typedef struct QNode QNode_t;

// The queue front stores the front node of LL and rear stores the last node of LL
typedef struct
{
    int size;
	unsigned capacity;

    QNode_t* front;
    QNode_t* rear;

} Queue_t;

// A utility function to create a new linked list node.
QNode_t* newNode(int data)
{
    QNode_t* node = (QNode_t*) malloc(sizeof(QNode_t));

    node->data = data;
    node->next = NULL;

    return node;
}

// A utility function to create an empty queue
Queue_t* createQueue (unsigned capacity)
{
    Queue_t* queue = (Queue_t*) malloc(sizeof(Queue_t));

    // Define queue elements
    queue->size = 0;
    queue->capacity = capacity;
    queue->front = NULL;
    queue->rear = NULL;

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
        // Create a new LL node
        QNode_t* node = newNode(item);

        // If queue is empty, then new node is front and rear both
        if (isEmpty(queue))
        {
            queue->front = node;
            queue->rear = node;
        }
        else
        {
            // Add the new node at the end of queue and change rear
            queue->rear->next = node;
            queue->rear = node;
        }

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
        ret = queue->front->data;

        // Store previous front and move front one node ahead
        QNode_t* temp = queue->front;

        queue->front = queue->front->next;

        // If front becomes NULL, then change rear to NULL as well
        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }

        free(temp);

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
        ret = queue->front->data;
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
        ret = queue->rear->data;
    }
    else
    {
        printf("\nQueue is empty.\n");
    }

	return ret;
}


int main ()
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
