#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Convert square footage to acres
double feet_to_acres(int square_feet);

// Calculate time to mow a rectangular lawn
int mow_lawn(double length, double width, double mowing_speed);

// Convert date from DDMMYYYY to YYYYMMDD format
int date_convert(int date);

// Calculate time for an object to fall a certain distance
int falling_time(double distance);

// Calculate hypotenuse of a right triangle
double hypotenuse(double side1, double side2);

// Sum all even numbers from 2 to n (inclusive)
int sum_even(int n);

// Sum partial harmonic series
double sum_partial_harmonic(int n);

#endif // FUNCTIONS_H
