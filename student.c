#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float total_Marks;
};
int main() {
    struct Student s1, s2;
    float average;

    printf("Enter Name for Student 1: ");
    scanf("%s", s1.name);
    printf("Enter Age and Marks: ");
    scanf("%d %f", &s1.age, &s1.total_Marks);

    printf("\nEnter Name for Student 2: ");
    scanf("%s", s2.name);
    printf("Enter Age and Marks: ");
    scanf("%d %f", &s2.age, &s2.total_Marks);

    average = (s1.total_Marks + s2.total_Marks) / 2;

    printf("\n   Student Details    \n");
    printf("Name: %s, Age: %d\n, Marks: %.2f\n", s1.name, s1.age, s1.total_Marks);
    printf("Name: %s, Age: %d\n, Marks: %.2f\n", s2.name, s2.age, s2.total_Marks);
    
    printf("\nAverage Marks: %.2f\n", average);

    return 0;
}
