#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
double *cholesky(double *A, int n) {
    double *L = (double*)calloc(n * n, sizeof(double));
    if (L == NULL)
        exit(EXIT_FAILURE);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (i+1); j++) {
            double s = 0;
            for (int k = 0; k < j; k++)
                s += L[i * n + k] * L[j * n + k];
            if (i==j) L[i * n + j] =  sqrt(A[i * n + i] - s);
            else L[i * n + j] = (1.0 / L[j * n + j] * (A[i * n + j] - s));
        }
 
    return L;
}
 
void affichage(double *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2.5f ", A[i * n + j]);
        printf("\n");
    }
}
 
int main() {
    int n = 3;
    double M[] = {25, 15, -5,
                   15, 18,  0,
                   -5,  0, 11};
    double *C = cholesky(M, n);
    affichage(C, n);
    printf("\n");
    free(C);
 
    n = 4;
    double N[] = {18, 22,  54,  42,
                   22, 70,  86,  62,
                   54, 86, 174, 134,
                   42, 62, 134, 106};
    double *D = cholesky(N, n);
    affichage(D, n);
    free(D);
 
    return 0;
}