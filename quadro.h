///\file
///\brief This (header) file can test a square equation;

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

//! Constant value as a precision
const double precision      = 0.001;

//! value that means that equation has infinity roots
const int    infinity_roots = -1;

//! Ded's meme
const int    solve_quadro_i_dunno_what_to_write_here_undefinite_value_of_number_of_ROOTS_ROOTS___ROOTS___YES___SCOTLAND_SCOTLAND = -2;


//! number of unittests
const int    num_of_unittests = 15;

//!struct for unit tests
//! @param a - coefficient
//! @param b - coefficient
//! @param c - coefficient
//! @param num_of_solutions - number of solutions
//! @param x1 - the first solution
//! @param x2 - the second solution
typedef struct _UnitTest{
    double a;
    double b;
    double c;
    char num_of_solutions;
    double x1;
    double x2;
} UnitTest;

//! This function compares two numbers
//! @param [in] a a - the first number
//! @param [in] b b - the second number
//! return 1 if they are equals and 0 if no
char cmp(double a, double b);

//! This functions check if number is NaN
//! @param [in] a a - number for checking
//!  returns 1 if the number is NaN and 0 if the number is not NaN
char Is_NaN(double a);


//! This function can call unit tests and what the program can do and some other interesting things
//! @param [in] argc the amount of arguments in terminal
//! @param [in] argv arguments in terminal
//! @param [out] val a value that calls unit tests if it is true
int ParsArgs(int argc, char* argv[]);


//! This function is a user's scanf
//! @param [in] a - pointer to coefficient a
//! @param [in] b - pointer to coefficient b
//! @param [in] c - pointer to coefficient c
void ScanCoeff(double* a, double* b, double* c);

//! This function cleans boofer
void FreeBoofer();

//! This function prints answers to linear equation
//! @param [in] n_roots number of roots
//! @param [in] x1 a pointer to the solution of linear equation
void printAnswersLinear(int n_roots, double* x1);

//! This function prints answers to quadratic equation
//! @param [in] n_roots number of roots
//! @param [in] x1 a pointer to the first solution of quadratic equation
//! @param [in] x2 a pointer to the second solution of quadratic equation
void printAnswersQuadro(int n_roots, double* x1, double* x2);




//! This function counts a discriminant
//! @param [in] a a - coefficient of quadratic equation
//! @param [in] b b - coefficient of quadratic equation
//! @param [in] c c - coefficient of quadratic equation
//! @param [out] D D - discriminant
double discriminant(double a, double b, double c);

//! This function solves a quadratic equation
//! @param [in] a a - coefficient of quadratic equation
//! @param [in] b b - coefficient of quadratic equation
//! @param [in] c c - coefficient of quadratic equation
//! @param [out] x1 pointer to the 1st root of quadratic equation
//! @param [out] x2 pointer to the the 1st root of quadratic equation
//! returns the number of roots

double SolveQuadro(double a, double b, double c, double* x1, double* x2);

//! This function solves a linear equation
//! @param [in] b b - coefficient of quadratic equation
//! @param [in] c c - coefficient of quadratic equation
//! @param [out] x1 pointer to the root of linear equation

//! returns the number of roots
//! @note  In case of infinity number of roots,
//!        returns infinity_roots.
double SolveLinear(double b, double c, double* x1);


//! This function makes unittests
void CheckAndDefineUnitTest(); 