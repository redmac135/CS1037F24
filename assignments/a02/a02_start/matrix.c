#include <math.h>
#include <stdio.h>
#include "matrix.h"

float norm(float *v, int n) {
    float result = 0;

    // iterate through each element and add the running sum of squares
    for(int i = 0; i < n; i++) {
        result += *(v + i) * *(v + i);
    }

    // return the squareroot of the sum
    return sqrtf(result);
}

float dot_product(float *v1, float *v2, int n) {
    float result = 0;
    
    // multiply element i of v1 with that of v2
    for(int i = 0; i < n; i++) {
        result += *(v1 + i) * *(v2 + i);
    }

    // return the sum of those products
    return result;
}

// assumes a square array
void matrix_multiply_vector(float *m, float *v, float *vout, int n) {
    // iterate through each dimension of output vector
    for(int offset = 0; offset < n; offset++) {
        float result = 0;

        // iterate through each dimension of matrix column vector
        for(int i = 0; i < n; i++) {
            result += *(v + offset) * *(m + offset + i * n);
        }

        // assign to vout
        *(vout + offset) = result;
    }
}

void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
    // each cell of m3 is the dot product between the row vector of m1 and column vector of m2
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            // construct the column vector of m2
            float v2[n];
            for(int k = 0; k < n; k++) {
                v2[k] = *(m2 + i + k*n);
            }

            // set the cell in m3 to the dot product
            // note: v1 is just the pointer pointing at the first element of the correct row
            // m3[a][b] = *(m3 + a*n + b)
            *(m3 + j*n + i) = dot_product(m1 + j*n, v2, n);
        }
    }
}