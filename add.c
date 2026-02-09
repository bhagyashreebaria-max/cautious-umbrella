#include<stdio.h>
struct Triplet {
    int row;
    int col;
    int val;
};
int convertToTriplet(int rows, int cols, int matrix[10][10], struct Triplet triplet[]) {
    int k = 1;
    triplet[0].row = rows;
    triplet[0].col = cols;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                triplet[k].row = i;
                triplet[k].col = j;
                triplet[k].val = matrix[i][j];
                k++;
            }
        }
    }
    triplet[0].val = k - 1; // Total non-zero elements
    return k - 1;
}
int main() {
    int r1, c1, r2, c2;
    int mat1[10][10], mat2[10][10];
    struct Triplet s1[50], s2[50], res[100];

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
        printf("\nAddition not possible! Dimensions must match.\n");
        return 0;
    }
    convertToTriplet(r1, c1, mat1, s1);
    convertToTriplet(r2, c2, mat2, s2);

    int i = 1, j = 1, k = 1;
    res[0].row = s1[0].row;
    res[0].col = s1[0].col;

    while(i <= s1[0].val && j <= s2[0].val) {
        if(s1[i].row < s2[j].row || (s1[i].row == s2[j].row && s1[i].col < s2[j].col)) {
            res[k++] = s1[i++];
        } else if (s2[j].row < s1[i].row || (s2[j].row == s1[i].row && s2[j].col < s1[i].col)) {
            res[k++] = s2[j++];
        } else {
            res[k].row = s1[i].row;
            res[k].col = s1[i].col;
            res[k].val = s1[i].val + s2[j].val;
            i++; j++; k++;
        }
    }
    while(i <= s1[0].val) res[k++] = s1[i++];
    while(j <= s2[0].val) res[k++] = s2[j++];
    res[0].val = k - 1;


    printf("\nConsolidated Sparsh Dataset(Triplet form)\n");
    printf("Row\tCol\tValue\n");
    for (int x = 0; x <= res[0].val; x++) {
        printf("%d\t%d\t%d\n", res[x].row, res[x].col, res[x].val);
    }
return 0;
}

