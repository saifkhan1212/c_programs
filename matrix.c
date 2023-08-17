


#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
// This file contains impelementation of matrix.h
// This code will calculate the determinant of the 
// matrix by first getting cofactors and then in the
// end recursively taking the determinant.

// What it does? this program takes out a sub matrix from a 
// big matrix and returns it.
// Parameters? there are 3 parameters. the Mat is big matrix.
// row and col are the indexes of point from where submatrix
// is to be extracted.
// what it returns? it returns submatrix of type struct Matrix

struct Matrix getSubMatrix(struct Matrix Mat, int row, int col)
{
    struct Matrix submatrix;
    submatrix.size = Mat.size - 1;
    int x = 0, y = 0;
    for (int i = 1; i < Mat.size; i++)
    {
        y = 0;
        for (int j = 0; j < Mat.size; j++)
        {
            if (j != col)
            {
                submatrix.matrix[x][y] = Mat.matrix[i][j];
                y++;
            }
        }
        x++;
    }
    return submatrix;
}


// What it does? this funtion calcualte the determinant 
// recursively by taking cofacotrs of submatrixes and 
// calculating the determinanat using that.
// Parameters? there is only single parameter which is 
// the input matrix.
// what it returns? it returns a determinant of float type


double GetDeterminant(struct Matrix Mat)
{
    double determinant ;
    if (Mat.size == 2)
    {
        return (Mat.matrix[0][0] * Mat.matrix[1][1] - Mat.matrix[0][1] * Mat.matrix[1][0]);
    }
    else
    {
        double sum = 0;
        int sign = 1;
        for (int j = 0; j < Mat.size; j++)
        {
            struct Matrix submatrix = getSubMatrix(Mat, 0, j);
            determinant = GetDeterminant(submatrix);
            sum += Mat.matrix[0][j] * determinant * sign;
            sign = -sign;
        }
        determinant = sum;
        
    }
    return determinant;
}


// What it does? this progrm read matrix from txt file
// Parameters? there is one string parameter which is the
// filepath of file containing matrix.
// what it returns? it returns the matrix after reading it from file 
// as struct Matrix type.

struct Matrix ReadFile(char path[])
{
    struct Matrix mat;
    FILE* myfile;
    double myvariable;
    int i;
    int j;

    myfile = fopen( path, "r");
    if(!myfile)
    {
      printf("unable to open file!!\n");
    }
    else
    {
       fscanf(myfile, "%lf", &myvariable);
        fscanf(myfile, "%lf", &myvariable);
        mat.size = myvariable;
        for (i = 0; i < mat.size; i++)
        {
            for (j = 0; j < mat.size; j++)
            {
                fscanf(myfile, "%lf", &myvariable);
                mat.matrix[i][j] = myvariable;
            }
        }

        fclose(myfile);
    }
   
    return mat;
}