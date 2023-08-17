
// this is the header file of matrix.c containing all the
// headers.


#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

struct Matrix {
    int size;
    float matrix[11][11];
};
struct Matrix getSubMatrix(struct Matrix Mat, int row, int col);
double GetDeterminant(struct Matrix Mat);
struct Matrix ReadFile(char path[]);

#endif