#include <stdio.h>

#define MAX 100

int convertToTriplet(int rows, int cols, int matrix[10][10], int triplet[MAX][3]) {
    int k = 1;
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    triplet[0][2] = k - 1;
    return k - 1;
}

int main() {
    int r1, c1, r2, c2;
    int mat1[10][10], mat2[10][10];
    int s1[MAX][3], s2[MAX][3], res[MAX][3];

    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements for Matrix 1:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);

    printf("\nEnter rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements for Matrix 2:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);

    if (r1 != r2 || c1 != c2) {
        printf("\nAddition not possible!\n");
        return 0;
    }

    convertToTriplet(r1, c1, mat1, s1);
    convertToTriplet(r2, c2, mat2, s2);

    int i = 1, j = 1, k = 1;
    res[0][0] = s1[0][0];
    res[0][1] = s1[0][1];

    while (i <= s1[0][2] && j <= s2[0][2]) {
        if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            res[k][0] = s1[i][0]; res[k][1] = s1[i][1]; res[k][2] = s1[i][2];
            i++; k++;
        } else if (s2[j][0] < s1[i][0] || (s2[j][0] == s1[i][0] && s2[j][1] < s1[i][1])) {
            res[k][0] = s2[j][0]; res[k][1] = s2[j][1]; res[k][2] = s2[j][2];
            j++; k++;
        } else {
            res[k][0] = s1[i][0]; res[k][1] = s1[i][1];
            res[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        }
    }

    while (i <= s1[0][2]) {
        res[k][0] = s1[i][0]; res[k][1] = s1[i][1]; res[k][2] = s1[i][2];
        i++; k++;
    }
    while (j <= s2[0][2]) {
        res[k][0] = s2[j][0]; res[k][1] = s2[j][1]; res[k][2] = s2[j][2];
        j++; k++;
    }
    res[0][2] = k - 1;

    printf("\nConsolidated Sparsh Dataset\n");
    printf("Row\tCol\tValue\n");
    for (int x = 0; x <= res[0][2]; x++) {
        printf("%d\t%d\t%d\n", res[x][0], res[x][1], res[x][2]);
    }

    return 0;
}
