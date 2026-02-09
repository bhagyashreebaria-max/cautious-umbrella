#include <stdio.h>
#define MAX 100
typedef struct {
    int row;
    int col;
    int val;
} Sparse;

void fastTranspose(Sparse a[], Sparse b[]) {
    int row_terms[MAX], start_pos[MAX];
    int num_cols = a[0].col;
    int num_terms = a[0].val;

    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].val = num_terms;

    if(num_terms > 0) {
        for(int i = 0; i < num_cols; i++) row_terms[i] = 0;
        for(int i = 1; i <= num_terms; i++) row_terms[a[i].col]++;

        start_pos[0] = 1;
        for(int i = 1; i < num_cols; i++) {
            start_pos[i] = start_pos[i - 1] + row_terms[i - 1];
        }for(int i = 1; i <= num_terms; i++) {
            int j = start_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }
}
int main() {
    int r, c, k = 1;
    int matrix[MAX][MAX];
    Sparse s[MAX], t[MAX];

    printf("Enter dimentions of web page matrix(rows,colu): ");
    scanf("%d %d", &r, &c);

    printf("Enter the adjacency matrix(0 for no link, 1 for link):\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].val = matrix[i][j];
                k++;
            }
        }  }
    s[0].row = r;
    s[0].col = c;
    s[0].val = k - 1;

    printf("\nGenerated Sparse Matrix Tripalet Representation ");
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= s[0].val; i++) {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
    }
fastTranspose(s, t);

    printf("\nTransposed Triplet Reresentation  ");
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= t[0].val; i++) {
        printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
    }
return 0;
}
