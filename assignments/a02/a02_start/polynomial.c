#include <stdio.h>
#include <math.h>
#include "polynomial.h"

#define TOLERANCE 0.000001 
#define MAX_ITERATIONS 100

float horner(float *p, int n, float x) {
    // begin with a_{n-1} stored in result
    float result = *p;

    // for each polynomial, multiply the result by x and add the next coefficient
    for (int i = 1; i < n; i++) {
        result = result * x + *(p + i);
    }

    return result;
}

void derivative(float *p, float *d, int n) {
    // the derivative of each member is it's current coefficient multiplied by the current exponent
    // the last value is always zero so we only need to iterate to n-1
    for(int i = 0; i < n - 1; i++) {
        *(d + i) = *(p + i) * (n - 1 - i);
    }
}

float newton(float *p, int n, float x0) {
    // initalize a new array to store the coefficients of the derivative function
    float d[n-1];
    derivative(p, d, n);

    // allocate a new variable for the "better guess"
    float x1;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // compute function at x0 and derivative at x0
        float fx = horner(p, n, x0);
        float dfx = horner(d, n - 1, x0);

        // check division by zero if abs within tolerance
        if (fabsf(dfx) < TOLERANCE) {
            return x0;
        }

        // apply Newton's method
        x1 = x0 - fx/dfx;

        // check convergence if difference is within tolerance
        if (fabsf(x1 - x0) < TOLERANCE) {
            return x0;
        }

        // replace current guess with better guess
        x0 = x1;
    }

    // if max interations reached, return current guess
    return x0;
}