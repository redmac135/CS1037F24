#include <stdio.h>
#include "functions.h"

int main() {
    printf("feet_to_acres(100000) = %.2f\n", feet_to_acres(100000));
    printf("mow_lawn(10.0, 10.0, 5.0) = %d\n", mow_lawn(10.0, 10.0, 5.0));
    printf("date_convert(25101962) = %d\n", date_convert(25101962));
    printf("falling_time(50) = %d\n", falling_time(50));
    printf("hypotenuse(3.0, 4.0) = %.1f\n", hypotenuse(3.0, 4.0));
    printf("sum_even(100) = %d\n", sum_even(100));
    printf("sum_partial_harmonic(4) = %.6f\n", sum_partial_harmonic(4));
    return 0;
}