//Write a C program to find the second-largest distinct element in an array without sorting it.

#include <stdio.h>

int main() {
    int a[100], n;
    int max, second;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    second = -999999;

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            second = max;
            max = a[i];
        }
        else if (a[i] > second && a[i] != max) {
            second = a[i];
        }
    }

    printf("Second largest = %d", second);

    return 0;
}
