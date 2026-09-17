//Write a C program to find all pairs of elements in an array whose sum is equal to a given target 
//value. Each pair should be displayed only once. 
///Array: 2 7 4 5 1 3 Target: 6 Output: (2, 4), (5, 1)

#include <stdio.h>

int main() {
    int a[] = {2, 7, 4, 5, 1, 3};
    int n = 6, target = 6;
    int i, j;

    printf("Pairs: ");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] + a[j] == target) {
                printf("(%d, %d) ", a[i], a[j]);
            }
        }
    }

    return 0;
}
