
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
// This file contains main function
int main(int argc,char *argv[])
{
    struct Matrix newmat = ReadFile(argv[1]);
    printf("The determinant is %.2f\n.", GetDeterminant(newmat));
    return 0;
}