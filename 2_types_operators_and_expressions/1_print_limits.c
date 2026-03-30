#include <limits.h>
#include <float.h>
#include <stdio.h>

/*
    Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
    variables, both signed and unsigned, by printing appropriate values from standard headers
    and by direct computation. Harder if you compute them: determine the ranges of the various
    floating-point types.
*/
int main(){
    printf("%-10s %d\n", "CHAR BITS", CHAR_BIT);
    printf("%-10s %d\n", "CHAR MAX", CHAR_MAX);
    printf("%-10s %d\n", "CHAR MIN", CHAR_MIN);
    printf("%-10s %d\n", "INT MAX", INT_MAX);
    printf("%-10s %d\n", "INT MIN", INT_MIN);
    printf("%-10s %ld\n", "LONG MAX", LONG_MAX);
    printf("%-10s %ld\n", "LONG MIN", LONG_MIN);
    printf("%-10s %d\n", "SCHAR MAX", SCHAR_MAX);
    printf("%-10s %d\n", "SCHAR MIN", SCHAR_MIN);
    printf("%-10s %hd\n", "SHRT MAX", SHRT_MAX);
    printf("%-10s %hd\n", "SHRT MIN", SHRT_MIN);
    printf("%-10s %u\n", "UCHAR MAX", UCHAR_MAX);
    printf("%-10s %u\n", "UINT MAX", UINT_MAX);
    printf("%-10s %lu\n", "ULONG MAX", ULONG_MAX);
    printf("%-10s %hu\n", "USHRT MAX", USHRT_MAX);
    printf("%-12s %d\n", "FLT_RADIX", FLT_RADIX);
    printf("%-12s %d\n", "FLT_ROUNDS", FLT_ROUNDS);


    // E is for scientific notiation
    // FLOATS (SINGLE PRECISION)
    printf("%-12s %d\n", "FLT_DIG", FLT_DIG);
    printf("%-12s %e\n", "FLT_EPSILON", FLT_EPSILON);
    printf("%-12s %d\n", "FLT_MANT_DIG", FLT_MANT_DIG);

    printf("%-12s %e\n", "FLT_MAX", FLT_MAX);
    printf("%-12s %d\n", "FLT_MAX_EXP", FLT_MAX_EXP);

    printf("%-12s %e\n", "FLT_MIN", FLT_MIN);
    printf("%-12s %d\n", "FLT_MIN_EXP", FLT_MIN_EXP);
    
    // DOUBLES (DOUBLE PRECISION)
    printf("%-12s %d\n", "DBL_DIG", DBL_DIG);
    printf("%-12s %e\n", "DBL_EPSILON", DBL_EPSILON);
    printf("%-12s %d\n", "DBL_MANT_DIG", DBL_MANT_DIG);

    printf("%-12s %e\n", "DBL_MAX", DBL_MAX);
    printf("%-12s %d\n", "DBL_MAX_EXP", DBL_MAX_EXP);

    printf("%-12s %e\n", "DBL_MIN", DBL_MIN);
    printf("%-12s %d\n", "DBL_MIN_EXP", DBL_MIN_EXP);
}   