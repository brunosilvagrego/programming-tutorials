#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct node_t
{
    int val;

    struct node_t *next;
    struct node_t *prev;
};

typedef struct node_t Node_t;

// Doubly Linked List structure
typedef struct
{
    Node_t *head;
    Node_t *tail;

} DoublyLinkedList_t;

// Create Node
Node_t* createNode (int val)
{
    Node_t *node = (Node_t*) malloc(sizeof(Node_t));

    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

// Initialize list
void listInit (DoublyLinkedList_t *dll)
{
    dll->head = NULL;
    dll->tail = NULL;
}

// Is list empty
bool listEmpty (DoublyLinkedList_t *dll)
{
   return (dll->head == NULL);
}

// List length
int listLength (DoublyLinkedList_t *dll)
{
    int length = 0;
    Node_t *current;

    for (current = dll->head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}

// Display the list forward
void displayForward (DoublyLinkedList_t *dll)
{
    printf("[ ");

    Node_t *current;

    for (current = dll->head; current != NULL; current = current->next)
    {
        printf("%d ", current->val);
    }

    printf("]\n");
}

// Display the list backward
void displayBackward (DoublyLinkedList_t *dll)
{
    printf("[ ");

    Node_t *current;

    for (current = dll->tail; current != NULL; current = current->prev)
    {
        printf("%d ", current->val);
    }

    printf("]\n");
}

// Find a link with given value
Node_t* findNode (DoublyLinkedList_t *dll, int searchVal)
{
    bool search = true;

    // Found node pointer
    Node_t *found = NULL;

    // Start from the first node
    Node_t *current = dll->head;

    // Navigate through the list
    while ((search == true) && (current != NULL))
    {
        if (current->val == searchVal)
        {
            found = current;
            search = false;
        }

        // Move to next link
        current = current->next;
    }

    return found;
}

// Insert a new node at the first location
void insertFirst (DoublyLinkedList_t *dll, int val)
{
    // Create new node
    Node_t *link = createNode(val);

    if (listEmpty(dll))
    {
        // Point the tail to the new first node
        dll->tail = link;
    }
    else
    {
        // Update head previous link
        dll->head->prev = link;

        // Point the new node next to the old first node
        link->next = dll->head;
    }

    // Point the head to the new first node
    dll->head = link;
}

// Insert a new node at the last location
void insertLast (DoublyLinkedList_t *dll, int val)
{
    // Create new node
    Node_t *link = createNode(val);

    if (listEmpty(dll))
    {
        // Point the head to the new last node
        dll->head = link;
    }
    else
    {
        // Update tail next link
        dll->tail->next = link;

        // Point the new node previous to the old last node
        link->prev = dll->tail;
    }

    // Point the tail to the new last node
    dll->tail = link;
}

// Insert a new node after a node with a given value
bool insertAfter (DoublyLinkedList_t *dll, int searchVal, int val)
{
    bool ret = true;

    // Find node
    Node_t *current = findNode(dll, searchVal);

    // If node exists, insert new node
    if (current == NULL)
    {
        ret = false;
    }
    else if (current == dll->tail)
    {
        insertLast(dll, val);
    }
    else
    {
        // Create new node
        Node_t *link = createNode(val);

        // Insert the link
        current->next->prev = link;
        link->next = current->next;
        link->prev = current;
        current->next = link;
    }

    return ret;
}

// Delete first node
void deleteFirst (DoublyLinkedList_t *dll)
{
    Node_t *tempLink = dll->head;

    if (dll->head->next == NULL)    // If it is the only Link
    {
        dll->head = NULL;
        dll->tail = NULL;
    }
    else
    {
        // Update second node previous pointer
        dll->head->next->prev = NULL;

        // Update head pointer
        dll->head = dll->head->next;
    }

    // Free memory
    free(tempLink);
}

// Delete last node
void deleteLast (DoublyLinkedList_t *dll)
{
    Node_t *tempLink = dll->tail;

    if (dll->tail->prev == NULL)    // If it is the only Link
    {
        dll->head = NULL;
        dll->tail = NULL;
    }
    else
    {
        // Update penultimate node next pointer
        dll->tail->prev->next = NULL;

        // Update head pointer
        dll->tail = dll->tail->prev;
    }

    // Free memory
    free(tempLink);
}

// Delete a link with given value
bool deleteByVal (DoublyLinkedList_t *dll, int searchVal)
{
    bool ret = true;

    // Find node
    Node_t *current = findNode(dll, searchVal);

    // If node exists, delete node
    if (current == NULL)
    {
        ret = false;
    }
    else if (current == dll->head)
    {
        deleteFirst(dll);
    }
    else if (current == dll->tail)
    {
        deleteLast(dll);
    }
    else
    {
        // Temp node
        Node_t *tempLink = current;

        // Bypass the current link
        current->next->prev = current->prev;
        current->prev->next = current->next;

        // Free memory
        free(tempLink);
    }

    return ret;
}

// List sort
void listSort (DoublyLinkedList_t *dll)
{
    int i, j, k, tempVal;
    Node_t *current;
    Node_t *next;

    int size = listLength(dll);
    k = size;

    for (i = 0 ; i < size - 1 ; i++, k--)
    {
        current = dll->head;
        next = dll->head->next;

        for (j = 1; j < k; j++)
        {
            // Sort nodes
            if (current->val > next->val)
            {
                tempVal = current->val;
                current->val = next->val;
                next->val = tempVal;
            }

            // Increment pointers
            current = current->next;
            next = next->next;
        }
    }
}

// List reverse
void listReverse (DoublyLinkedList_t *dll)
{
    Node_t *tempHead = dll->head;
    Node_t *tempTail = dll->tail;

    Node_t *current = dll->head;
    Node_t *temp = NULL;

    while (current != NULL)
    {
        // Store previous node
        temp = current->prev;
        
        // Reverse Links
        current->prev = current->next;
        current->next = temp;
        
        // Increment current
        current = current->prev;
    }

    dll->head = tempTail;
    dll->tail = tempHead;
}


int main()
{
    /** Create list **/
    DoublyLinkedList_t dll;

    listInit(&dll);

    if (listEmpty(&dll))
    {
        printf("\nThe List is empty.\n");
    }
    else
    {
        printf("\nThe List is not empty.\n");
    }

    /** Insertion **/
    printf("\nOriginal List:\n");
    insertFirst(&dll, 0);
    displayForward(&dll);

    if (listEmpty(&dll))
    {
        printf("\nThe List is empty.\n");
    }
    else
    {
        printf("\nThe List is not empty.\n");
    }

    // insertFirst() and insertLast()
    printf("\nList after inserting more nodes:\n");
    insertLast(&dll, 1);
    insertFirst(&dll, 2);
    insertLast(&dll, 3);
    insertFirst(&dll, 4);
    insertLast(&dll, 5);
    insertFirst(&dll, 6);
    insertLast(&dll, 7);
    insertFirst(&dll, 8);
    insertLast(&dll, 9);
    insertFirst(&dll, 10);
    insertLast(&dll, 11);
    insertFirst(&dll, 12);
    insertLast(&dll, 13);
    insertFirst(&dll, 14);
    displayForward(&dll);

    // displayBackward()
    printf("\nList displayed backwards:\n");
    displayBackward(&dll);

    // listLength()
    printf("\nList length: %d\n", listLength(&dll));

    // insertAfter()
    if (insertAfter(&dll, 4, 16))
    {
        printf("\nList after inserting '16' after value '4':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }


    if (insertAfter(&dll, 13, 15))
    {
        printf("\nList after inserting '15' after value '13':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }

    if (insertAfter(&dll, 20, 12))
    {
        printf("\nList after inserting '12' after value '20':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }

    // listLength()
    printf("\nList length: %d\n", listLength(&dll));

    /** Deletion **/
    // deleteFirst()
    printf("\nList after deleting first element:\n");
    deleteFirst(&dll);
    displayForward(&dll);

    // deleteLast()
    printf("\nList after deleting last element:\n");
    deleteLast(&dll);
    displayForward(&dll);

    // deleteByVal() - middle node
    if (deleteByVal(&dll, 7))
    {
        printf("\nList after deleting element '7':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }

    // deleteByVal() - first node
    if (deleteByVal(&dll, 12))
    {
        printf("\nList after deleting element '12':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }

    // deleteByVal() - last node
    if (deleteByVal(&dll, 13))
    {
        printf("\nList after deleting element '13':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }

    // deleteByVal() - non-existent element
    if (deleteByVal(&dll, 20))
    {
        printf("\nList after deleting element '20':\n");
        displayForward(&dll);
    }
    else
    {
        printf("\nNode not found!\n");
    }

    // listLength()
    printf("\nList length: %d\n", listLength(&dll));

    // listReverse()
    printf("\nList after reverse:\n");
    listReverse(&dll);
    displayForward(&dll);

    // listSort()
    printf("\nList after sort:\n");
    listSort(&dll);
    displayForward(&dll);

    // listReverse()
    printf("\nList after reverse:\n");
    listReverse(&dll);
    displayForward(&dll);
}
