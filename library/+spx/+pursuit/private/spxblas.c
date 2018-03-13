#include "spxblas.h"
#include "blas.h"


/**

Some useful references: 

- dgemv https://gitlab.phys.ethz.ch/hpcse_fs15/lecture/blob/324a55886a689479a7e47d011d98d953588a3212/examples/matrix/cblas/dgemv.c


*/

#if !defined(_WIN32)
#define dgemm dgemm_
#define dgemv dgemv_
#endif



void mult_mat_vec(double alpha, 
    const double A[], 
    const double x[], 
    double y[], size_t m, size_t n){
    
    mwSignedIndex  incx = 1;
    mwSignedIndex  incy = 1;
    char trans = 'N';
    double beta = 0;
    mwSignedIndex  mm = m;
    mwSignedIndex  nn = n;
    dgemv(&trans, &mm, &nn, &alpha, A, &mm, x, &incx, 
        &beta, y, &incy);
}

void mult_mat_t_vec(double alpha, 
    const double A[], 
    const double x[], 
    double y[], size_t m, size_t n){
    
    mwSignedIndex  incx = 1;
    mwSignedIndex  incy = 1;
    char trans = 'T';
    double beta = 0;
    mwSignedIndex  mm = m;
    mwSignedIndex  nn = n;
    dgemv(&trans, &mm, &nn, &alpha, A, &mm, x, &incx, 
        &beta, y, &incy);
}

void mult_mat_mat(double alpha, 
    const double A[], 
    const double B[], 
    double X[], 
    size_t m, size_t n, size_t k){
    char atrans = 'N';
    char btrans = 'N';
    double beta = 0;
    mwSignedIndex  mm = m;
    mwSignedIndex  nn = n;
    mwSignedIndex  kk = k;
    dgemm(&atrans, &btrans, 
        &mm, &nn, &kk, 
        &alpha, 
        A, &mm, 
        B, &kk, 
        &beta, 
        X, &mm);
}

void mult_mat_t_mat(double alpha, 
    const double A[], 
    const double B[], 
    double X[], 
    size_t m, size_t n, size_t k){
    char atrans = 'T';
    char btrans = 'N';
    double beta = 0;
    mwSignedIndex  mm = m;
    mwSignedIndex  nn = n;
    mwSignedIndex  kk = k;
    dgemm(&atrans, &btrans, 
        &mm, &nn, &kk, 
        &alpha, 
        A, &kk, 
        B, &kk, 
        &beta, 
        X, &mm);
}


