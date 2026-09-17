//Write a program to count the frequency of each distinct element in an array.

#include <stdio.h>

int main() {
    int a[100], n, i, j, count;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        count = 1;

        if (a[i] == -1)
            continue;

        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                a[j] = -1;
            }
        }

        printf("%d = %d times\n", a[i], count);
    }

    return 0;
}
