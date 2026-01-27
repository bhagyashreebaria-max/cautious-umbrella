#include <stdio.h>
#include <stdlib.h> 

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    int n;
    
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1) return 1; 

    struct Employee *emp = (struct Employee*) malloc(n * sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d ID: ", i + 1);
        scanf("%d", &emp[i].id);
        
        printf("Employee %d Name: ", i + 1);
        scanf(" %s", emp[i].name); 
        
        printf("Employee %d Salary: ", i + 1);
        scanf("%f", &emp[i].salary);
    }

    printf("\n Employee Details \n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
    free(emp); 
    return 0;
}
