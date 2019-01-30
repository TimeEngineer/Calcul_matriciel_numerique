#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parameters
#define N 3

// Code
typedef struct Matrix {
   int n;
   double **ptr;
} Matrix;

Matrix* init_matrix(int n);
void free_matrix(Matrix *m);
void print_matrix(Matrix *m);
// Initialize a Lower Matrix with value between 0 and 1
void init_lower(Matrix *m);
// Initialize a Upper Matrix with value between 0 and 1
void init_upper(Matrix *m);
// Multiplication with Lower Matrix * Upper Matrix in this order
Matrix* produit_inf_sup(Matrix *L, Matrix *U);

#endif