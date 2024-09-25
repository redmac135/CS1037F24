#include "functions.h"
#include <math.h>

double feet_to_acres(int square_feet)
{
    // divide square_feet by 43560 to convert to acres
    return square_feet / (double)43560;
}

int mow_lawn(double length, double width, double mowing_speed)
{
    // get area by multiplying length and width
    // then divide by mowing_speed to calculate mowing time
    return length * width / mowing_speed;
}

int date_convert(int date)
{
    // incoming format is DDMMYYYY

    // get the day by dividing by integer 1000000
    int day = date / 1000000;
    // get the month by dividing by 10000 and removing the first two numbers with mod 100
    int month = (date / 10000) % 100;
    // get the year by removing the first 4 numbers using mod 10000
    int year = date % 10000;

    // return the date in the format YYYYMMDD by multiplying by respective powers of 10
    return year * 10000 + month * 100 + day;
}

int falling_time(double distance)
{
    // gravitational acceleration constant
    const int g = 9.8;

    // calculate how long it takes to fall a distance d using formula
    // sqrt{2 * d / g}
    return sqrt(2 * distance / g);
}

double hypotenuse(double side1, double side2)
{
    // calculate the hypotenuse of a right triangle using pythagorean's theorm 
    return sqrt(side1 * side1 + side2 * side2);
}

int sum_even(int n)
{
    // initalize a sum variable to store the sum
    int sum = 0;

    // loop over all even numbers starting with 2 until n
    for (int i = 2; i <= n; i++)
    {
        // test if number is even
        if (i % 2 == 0)
        {
            // if it is, add it to the running sum
            sum += i;
        }
    }

    // return the now total sum of even numbers
    return sum;
}

double sum_partial_harmonic(int n)
{
    // initalize a sum variable to store running sum of harmonics
    double sum = 0.0;

    // iterate from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // add 1 / i to the running sum
        sum += 1 / (double)i;
    }

    // return the partial sum of harmonic series
    return sum;
}