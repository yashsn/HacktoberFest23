#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

// Structure to represent a book
struct Book {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
};

// Function prototypes
void addBook(struct Book books[], int *count);
void viewBooks(struct Book books[], int count);
void searchBook(struct Book books[], int count);

int main() {
    struct Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                viewBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to add a book
void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    struct Book newBook;
    newBook.id = *count + 1; // Assign ID
    printf("Enter book title: ");
    getchar(); // Clear newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline
    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    books[*count] = newBook; // Add to library
    (*count)++;
    printf("Book added successfully!\n");
}

// Function to view all books
void viewBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("\nBooks in the Library:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
}

// Function to search for a book
void searchBook(struct Book books[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, title) == 0) {
            printf("Book found: ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {

        printf("Book not found!!\n");


    }
}
