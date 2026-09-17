//Write a program to check whether a given string is a palindrome.
//Ignore spaces and differences between uppercase and lowercase letters.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        if (str[i] == ' ') {
            i++;
            continue;
        }

        if (str[j] == ' ' || str[j] == '\n') {
            j--;
            continue;
        }

        if (tolower(str[i]) != tolower(str[j])) {
            flag = 0;
            break;
        }

        i++;
        j--;
    }

    if (flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
