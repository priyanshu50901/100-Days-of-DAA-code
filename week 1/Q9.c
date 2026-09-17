#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main()
{
    struct Book b[50];
    int n = 0, choice, id, i;

    do
    {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Book ID: ");
            scanf("%d", &b[n].id);

            printf("Enter Title: ");
            scanf(" %[^\n]", b[n].title);

            printf("Enter Author: ");
            scanf(" %[^\n]", b[n].author);

            printf("Enter Total Copies: ");
            scanf("%d", &b[n].total);

            b[n].available = b[n].total;
            n++;

            printf("Book added.\n");
        }

        else if (choice == 2)
        {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++)
            {
                if (b[i].id == id)
                {
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);
                    printf("Available: %d\n", b[i].available);
                }
            }
        }

        else if (choice == 3)
        {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++)
            {
                if (b[i].id == id)
                {
                    if (b[i].available > 0)
                    {
                        b[i].available--;
                        printf("Book issued.\n");
                    }
                    else
                        printf("Book unavailable.\n");
                }
            }
        }

        else if (choice == 4)
        {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++)
            {
                if (b[i].id == id)
                {
                    if (b[i].available < b[i].total)
                    {
                        b[i].available++;
                        printf("Book returned.\n");
                    }
                }
            }
        }

        else if (choice == 5)
        {
            printf("\nUnavailable Books:\n");

            for (i = 0; i < n; i++)
            {
                if (b[i].available == 0)
                    printf("%d - %s\n", b[i].id, b[i].title);
            }
        }
    } while (choice != 6);
    return 0;
}
