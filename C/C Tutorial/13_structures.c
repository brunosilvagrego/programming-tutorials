#include <stdio.h>
#include <string.h>

struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};

/* Function declaration */
void printBook (struct Books *book);

int main ()
{
    struct Books Book1;
    struct Books Book2;

    /* Book 1 specification */
    strcpy(Book1.title, "The C Programming Language");
    strcpy(Book1.author, "Dennis Ritchie");
    strcpy(Book1.subject, "Programming");
    Book1.book_id = 6495407;

    printBook(&Book1);
    printf("\n");

    /* book 2 specification */
    strcpy(Book2.title, "The C++ Programming Language");
    strcpy(Book2.author, "Bjarne Stroustrup");
    strcpy(Book2.subject, "Programming");
    Book2.book_id = 6495700;

    printBook( &Book2 );
    printf("\n");

    return 0;
}

// NOTE: Structures can be passed to functions by value or by pointer.
//       Passing a structure by value implies copying the whole structure.
//       Passing a structure by pointer implies just copying  its address,
//       which is much more efficient

void printBook (struct Books *book)
{
    printf("Book title   : %s\n", book->title);
    printf("Book author  : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}
