#include <stdio.h>

int main()
{
    int a[10][10];
    int n, i, j;
    int celebrity = -1;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        int knownByEveryone = 1;
        int knowsNobody = 1;

        for(j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
                knowsNobody = 0;

            if(i != j && a[j][i] == 0)
                knownByEveryone = 0;
        }

        if(knowsNobody == 1 && knownByEveryone == 1)
        {
            celebrity = i;
            break;
        }
    }

    if(celebrity == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person %d\n", celebrity);

    return 0;
}