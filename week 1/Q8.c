#include <stdio.h>

#define MAX 100
#define SUBJECTS 5

struct Student {
    int rollNo;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
};

char calculateGrade(float percentage, int failed) {
    if (failed)
        return 'F';
    else if (percentage >= 90)
        return 'A';
    else if (percentage >= 75)
        return 'B';
    else if (percentage >= 60)
        return 'C';
    else if (percentage >= 50)
        return 'D';
    else
        return 'E';
}

int main() {
    struct Student s[MAX];
    int n, i, j;
    float classTotal = 0;
    int topper = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        for (j = 0; j < SUBJECTS; j++) {
            printf("Marks in Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / SUBJECTS;

        int failed = 0;
        for (j = 0; j < SUBJECTS; j++) {
            if (s[i].marks[j] < 40) {
                failed = 1;
                break;
            }
        }

        s[i].grade = calculateGrade(s[i].percentage, failed);

        classTotal += s[i].percentage;

        if (s[i].percentage > s[topper].percentage)
            topper = i;
    }

    printf("\n========== STUDENT RESULTS ==========\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll Number : %d", s[i].rollNo);
        printf("\nName        : %s", s[i].name);
        printf("\nTotal       : %.2f / 500", s[i].total);
        printf("\nPercentage  : %.2f%%", s[i].percentage);
        printf("\nGrade       : %c\n", s[i].grade);
    }

    printf("\n========== CLASS TOPPER ==========\n");
    printf("Roll Number : %d\n", s[topper].rollNo);
    printf("Name        : %s\n", s[topper].name);
    printf("Percentage  : %.2f%%\n", s[topper].percentage);

    printf("\n========== STUDENTS WHO FAILED ==========\n");

    int anyFailed = 0;

    for (i = 0; i < n; i++) {
        int failed = 0;

        for (j = 0; j < SUBJECTS; j++) {
            if (s[i].marks[j] < 40) {
                failed = 1;
                break;
            }
        }

        if (failed) {
            printf("Roll No: %d, Name: %s\n",
                   s[i].rollNo, s[i].name);
            anyFailed = 1;
        }
    }

    if (!anyFailed)
        printf("No student failed in any subject.\n");

    printf("\n========== CLASS AVERAGE ==========\n");
    printf("Class Average: %.2f%%\n", classTotal / n);

    return 0;
}
