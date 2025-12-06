// Write a C program to dynamically allocate memory for a structure
// Book containing book_id (int), title (char array of size 50) and price
// (float). Read the values from the user and display them.

#include <stdio.h>
#include <stdlib.h>

typedef struct Books
{
    int book_id;
    char title[50];
    float price;

} Book;
int main()
{
    Book *B1;
    B1 = (Book *)malloc(sizeof(Book));
    if (B1 == NULL)
    {
        printf("Error allocating memory.\n");
        return 1;
    }
    printf("\nEnter the following data for a book: \n");
    printf("Book ID: ");
    scanf("%d", &B1->book_id);
    printf("Title : ");
    scanf("%49s", B1->title);
    printf("Price (RS.): ");
    scanf("%f", &B1->price);
    printf("\nDisplaying the stored data:\n");
    printf(" Book ID: %d\n Title : %s\n Price : RS.%.2f", B1->book_id, B1->title, B1->price);
    free(B1);
    return 0;
}