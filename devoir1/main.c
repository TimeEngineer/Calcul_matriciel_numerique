#include "main.h"

Matrix* init_matrix(int n) {
	Matrix* ptr_matrix = (Matrix*) malloc(sizeof(Matrix));
	ptr_matrix->n = n;
	ptr_matrix->ptr = (double**) malloc(n * sizeof(double*));
	int i;
	for (i = 0 ; i < n ; i++) {
		ptr_matrix->ptr[i] = (double*) calloc(n,sizeof(double));
	}
	return ptr_matrix;
}

void free_matrix(Matrix *m) {
	int i;
	for (i = 0 ; i < m->n ; i++) {
		free(m->ptr[i]);
	} free(m->ptr);
	free(m);
}

void print_matrix(Matrix *m) {
	int i,j;
	for (i = 0 ; i < m->n ; i++) {
		for (j = 0 ; j < m->n ; j++) {
			printf("%.4f \t", m->ptr[i][j]);
		} printf("\n");
	}
}

// Initialize a Lower Matrix with value between 0 and 1
void init_lower(Matrix *m) {
	int i,j;
	for (i = 0 ; i < m->n ; i++) {
		for (j = 0 ; j <= i ; j++) {
			m->ptr[i][j] = (double) (rand()%10000)/1e4;
		}
	}
}

// Initialize a Upper Matrix with value between 0 and 1
void init_upper(Matrix *m) {
	int i,j;
	for (j = 0 ; j < m->n ; j++) {
		for (i = 0 ; i <= j ; i++) {
			m->ptr[i][j] = (double) (rand()%10000)/1e4;
		}
	}
}

// Multiplication with Lower Matrix * Upper Matrix in this order
Matrix* produit_inf_sup(Matrix *L, Matrix *U) {
	Matrix *ptr_matrix = init_matrix(L->n);
	int i,j,k;
	for (i = 0 ; i < L->n ; i++) {
		for (j = 0 ; j < L->n ; j++) {
			for (k = 0 ; k <= i && k <= j ; k++) {
				ptr_matrix->ptr[i][j] += L->ptr[i][k] * U->ptr[k][j];
			}
		}
	}
	return ptr_matrix;
} 

int main() {
	srand(time(NULL));
	// Initialize the matrix
	Matrix *L = init_matrix(N);
	init_lower(L);
	Matrix *U = init_matrix(N);
	init_upper(U);

	// Show these matrix
	print_matrix(L);
	printf("\n");
	print_matrix(U);

	// Calculate the multiplication
	Matrix *m = produit_inf_sup(L,U);
	
	// Show the result
	printf("\n");
	print_matrix(m);

	// Free allocation
	free_matrix(L);
	free_matrix(U);
	free_matrix(m);
	return 0;
}