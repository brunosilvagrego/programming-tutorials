#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    int key;
    struct node *next;
};

// Is list empty
bool listEmpty (struct node *head)
{
   return (head == NULL);
}

// Display the list
void printList (struct node *ptr)
{
    printf("[ ");

    while (ptr != NULL)
    {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }

    printf("]\n");
}

// Insert a new node at the first location
void insertFirst (struct node **headPtr, int key, int data)
{
    // Create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    // Point it to old first node
    link->next = *headPtr;

    // Point the head to the new first node
    *headPtr = link;
}

// Insert a new node at the last location
void insertLast (struct node *ptr, int key, int data)
{
    // Create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;
    link->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // Point the last node to the new first node
    ptr->next = link;
}

// Delete first node
void deleteFirst (struct node **headPtr)
{
    *headPtr = (*headPtr)->next;
}

// Delete a link with given key
void deleteByKey (struct node **headPtr, int key)
{
    // Start from the first link
    struct node* current = *headPtr;
    struct node* previous = NULL;

    // Navigate through list
    while ((current->key != key) && (current != NULL))
    {
        // Store reference to current link
        previous = current;

        // Move to next link
        current = current->next;
    }

    // Found a match, update the link
    if (current == *headPtr)
    {
        //change first to point to next link
        *headPtr = (*headPtr)->next;
    }
    else if (current != NULL)
    {
        // Bypass the current link
        previous->next = current->next;
    }
}

// Delete last
void deleteLast (struct node **headPtr)
{
    // Start from the first link
    struct node* current = *headPtr;
    struct node* previous = NULL;

    // Navigate through list
    while ((current->next != NULL))
    {
        // Store reference to current link
        previous = current;

        // Move to next link
        current = current->next;
    }

    if (current == *headPtr)
    {
        //change first to point to next link
        *headPtr = NULL;
    }
    else
    {
        // Bypass the current link
        previous->next = NULL;
    }
}

int listLength (struct node *head)
{
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}

// Find a link with given key
struct node* find (struct node *head, int key)
{
    // Start from the first link
    struct node* current = head;

    // If the list is empty
    if (head == NULL)
    {
        return NULL;
    }

    // Navigate through list
    while (current->key != key)
    {
        // If it is last node
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            // Go to next link
            current = current->next;
        }
    }

    // If data found, return the current Link
    return current;
}

void sort (struct node **headPtr)
{
    int i, j, k, tempKey, tempData;
    struct node *current;
    struct node *next;

    int size = listLength(*headPtr);
    k = size;

    for ( i = 0 ; i < size - 1 ; i++, k-- )
    {
        current = *headPtr;
        next = (*headPtr)->next;

        for (j = 1; j < k; j++)
        {
            if ( current->data > next->data )
            {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }

            current = current->next;
            next = next->next;
        }
    }
}

void reverse (struct node **headPtr)
{
    struct node* prev = NULL;
    struct node* current = *headPtr;
    struct node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headPtr = prev;
}


int main()
{
    // Create list head
    struct node *head = NULL;

    if (listEmpty(head))
    {
        printf("\nThe List is empty.\n");
    }
    else
    {
        printf("\nThe List is not empty.\n");
    }

    head = (struct node*) malloc(sizeof(struct node));

    head->key = 0;
    head->data = 0;
    head->next = NULL;

    printf("\nOriginal List:\n");
    printList(head);

    if (listEmpty(head))
    {
        printf("\nThe List is empty.\n");
    }
    else
    {
        printf("\nThe List is not empty.\n");
    }

    /** Insertion **/
    // Insert first
    insertFirst(&head, 1, 10);
    insertFirst(&head, 3, 30);
    insertFirst(&head, 2, 20);
    insertFirst(&head, 5, 50);
    insertFirst(&head, 4, 40);
    insertFirst(&head, 6, 60);
    printf("\nList after adding nodes:\n");
    printList(head);

    /** Deletion **/
    // Delete First
    deleteFirst(&head);
    printf("\nList after deleting first node:\n");
    printList(head);

    // Delete by keu
    deleteByKey(&head, 2);
    printf("\nList after deleting node with 'key = 2':\n");
    printList(head);

    // Delete Last
    deleteLast(&head);
    printf("\nList after deleting last node:\n");
    printList(head);

    /** Insertion **/
    // Insert Last
    insertLast(head, 7, 70);
    insertLast(head, 8, 80);
    printf("\nList after adding more nodes:\n");
    printList(head);

    // Mixed insertion
    insertFirst(&head, 9, 90);
    insertLast(head, 10, 100);
    insertFirst(&head, 11, 110);
    insertLast(head, 12, 120);
    printf("\nList after adding more nodes:\n");
    printList(head);

    /** Search **/
    struct node *foundLink = find(head, 3);

    if(foundLink != NULL)
    {
        printf("\nElement found: (%d,%d)\n", foundLink->key, foundLink->data);
    }
    else
    {
        printf("\nElement not found.\n");
    }

    /** Sort **/
    sort(&head);
    printf("\nList after sorting the data:\n");
    printList(head);

    /** Reverse **/
    reverse(&head);
    printf("\nList after reversing the data:\n");
    printList(head);
}
