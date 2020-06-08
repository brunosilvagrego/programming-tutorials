#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

typedef struct
{
    int data;
    int key;

} DataItem_t;

DataItem_t* hashArray[SIZE];


int hashCode (int key)
{
    return (key % SIZE);
}

DataItem_t *search (int key)
{
    bool search = true;

    DataItem_t* item = NULL;

    // Get the hash code
    int hashIndex = hashCode(key);

    // Move in array until find an empty position
    while ((hashArray[hashIndex] != NULL) && (search == true))
    {
        if(hashArray[hashIndex]->key == key)
        {
            item = hashArray[hashIndex];

            search = false;
        }

        // Go to next cell
        ++hashIndex;

        // Wrap around the table
        hashIndex %= SIZE;
    }

    return item;
}

void insert (int key, int data)
{
    DataItem_t *item = (DataItem_t*) malloc(sizeof(DataItem_t));
    item->data = data;
    item->key = key;

    // Get the hash code
    int hashIndex = hashCode(key);

    // Move in array until an empty or deleted cell
    while ((hashArray[hashIndex] != NULL) && (hashArray[hashIndex]->key != -1))
    {
        // Go to next cell
        ++hashIndex;

        // Wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

void delete (int key)
{
    bool deleted = false;

    // Get the hash code
    int hashIndex = hashCode(key);

    // Move in array until an empty
    while ((hashArray[hashIndex] != NULL) && (deleted == false))
    {
        if(hashArray[hashIndex]->key == key)
        {
            // Create dummy item
            DataItem_t* dummyItem;
            dummyItem = (DataItem_t*) malloc(sizeof(DataItem_t));
            dummyItem->data = -1;
            dummyItem->key = -1;

            // Assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;

            deleted = true;
        }

        // Go to next cell
        ++hashIndex;

        // Wrap around the table
        hashIndex %= SIZE;
    }

    if (deleted == true)
    {
        printf("\nElement with key '%d' deleted\n", key);
    }
    else
    {
        printf("\nElement not found!\n");
    }
}

void display ()
{
    int i = 0;

    for(i = 0; i<SIZE; i++)
    {
        if(hashArray[i] != NULL)
        {
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        }
        else
        {
            printf(" ~~ ");
        }
    }

    printf("\n");
}

int main()
{
    DataItem_t* item;

    // insert()
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    // display()
    display();

    // search()
    item = search(37);

    if(item != NULL)
    {
        printf("\nElement found: (%d,%d)\n", item->key, item->data);
    }
    else
    {
        printf("\nElement not found!\n");
    }

    // delete()
    delete (37);

    // search()
    item = search(37);

    if(item != NULL)
    {
        printf("\nElement found: (%d,%d)\n", item->key, item->data);
    }
    else
    {
        printf("\nElement not found!\n");
    }

    // search()
    item = search(14);

    if(item != NULL)
    {
        printf("\nElement found: (%d,%d)\n", item->key, item->data);
    }
    else
    {
        printf("\nElement not found!\n");
    }

    // insert()
    insert(5, 50);
    insert(7, 70);
    insert(9, 90);
    insert(15, 150);

    // display()
    display();
}
