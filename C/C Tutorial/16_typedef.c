#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;

typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    BYTE book_id;

} Book;

int main ()
{
    Book book;

    strcpy(book.title, "The C Programming Language");
    strcpy(book.author, "Dennis Ritchie");
    strcpy(book.subject, "Programming");
    book.book_id = 15;

    printf("Book title : %s\n", book.title);
    printf("Book author : %s\n", book.author);
    printf("Book subject : %s\n", book.subject);
    printf("Book book_id : %d\n", book.book_id);

    return 0;
}
