#include <stdio.h>

int main()
{
    float balance = 5000, amount;
    int choice, i, count = 0;
    char transactions[5][50];

    do
    {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Show Last 5 Transactions\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Balance = %.2f\n", balance);
        }

        else if (choice == 2)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            balance = balance + amount;

            printf("Money deposited.\n");

            if (count < 5)
            {
                sprintf(transactions[count], "Deposited %.2f", amount);
                count++;
            }
        }

        else if (choice == 3)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (amount <= balance)
            {
                balance = balance - amount;
                printf("Money withdrawn.\n");

                if (count < 5)
                {
                    sprintf(transactions[count], "Withdrawn %.2f", amount);
                    count++;
                }
            }
            else
            {
                printf("Insufficient balance.\n");
            }
        }

        else if (choice == 4)
        {
            printf("\nLast Transactions:\n");

            for (i = 0; i < count; i++)
            {
                printf("%s\n", transactions[i]);
            }
        }

        else if (choice == 5)
        {
            printf("Thank you!\n");
        }

        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
