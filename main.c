#include <stdio.h>
#include <stdlib.h>

// Function to get matrix from user
int** getmat(int* row, int* col, char matrix)
{
    printf("Enter details for Matrix %c :\n",matrix);
    printf("Enter number of rows: ");
    scanf("%d", row);
    printf("Enter number of columns: ");
    scanf("%d", col);

    int **mat = (int**)malloc(*row * sizeof(int*));
    for (int i = 0; i < *row; i++) {
        mat[i] = (int*)malloc(*col * sizeof(int));
    }
    printf("Enter values of matrix:\n");
    for (int i = 0; i < *row; i++) {
        for (int ii = 0; ii < *col; ii++) {
            printf("Enter element at %c[%d,%d]: ", matrix, i+1, ii+1);
            scanf("%d", &mat[i][ii]);
        }
    }

    return mat;
}

// Function to multiply two matrices
int** multiply(int** a, int ar, int ac, int** b, int br, int bc, int* cr, int* cc)
{
    // Validating for multiplication
    if (ac != br) {
        printf("Matrices are not compatible for multiplication\n");
        exit(1);
    }

    *cr = ar;
    *cc = bc;

    int** c = (int**)malloc(*cr * sizeof(int*));
    for (int i = 0; i < *cr; i++) {
        c[i] = (int*)malloc(*cc * sizeof(int));
    }

    for (int i = 0; i < *cr; i++) {
        for (int ii = 0; ii < *cc; ii++) {
            c[i][ii] = 0;
            for (int iii = 0; iii < ac; iii++) {
                c[i][ii] += a[i][iii] * b[iii][ii];
            }
        }
    }
return c;
}

// Function to write matrix to a file
void write(int** matrix, int r, int c, const char* fname)
{
    FILE* file = fopen(fname, "w");

    //Validating for opening file
    if (file == NULL) {
        printf("ERROR WHILE OPENING FILE\n");
        exit(1);
    }
    fprintf(file, "Resultant Matrix C :\n");

    for (int i = 0; i < r; i++) {
        for (int ii = 0; ii < c; ii++) {
            fprintf(file, "%d ", matrix[i][ii]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Main function
int main()
{
    int **a, **b, **c;
    int ar, ac, br, bc, cr, cc;

    a = getmat(&ar, &ac, 'A');
    b = getmat(&br, &bc, 'B');
    c = multiply(a, ar, ac, b, br, bc, &cr, &cc);
    write(c, cr, cc, "output.txt");

    return 0;
}
