///\file
///\brief This (main) file can test a square equation;
#include <stdio.h>
#include "quadro.h"

//===============================================================================================================
int main(int argc, char* argv[])
{   
        
    int ret_value = 0;
            
    ret_value = ParsArgs(argc, argv);
    if (ret_value == 1) {           
        CheckAndDefineUnitTest();
    }
            
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;  

    ScanCoeff(&a, &b, &c);

    int n_roots = solve_quadro_i_dunno_what_to_write_here_undefinite_value_of_number_of_ROOTS_ROOTS___ROOTS___YES___SCOTLAND_SCOTLAND;
    
    if (cmp(a, 0) == 1)
    {   
        n_roots = SolveLinear(b, c, &x1);
        printAnswersLinear(n_roots, &x1);
        
    }
    else
    {
        n_roots = SolveQuadro(a, b, c, &x1, &x2);
        printAnswersQuadro(n_roots, &x1, &x2);
    }

    return 0;
}


//==========================================================================================================================

// IsNaN
char Is_NaN(double a)
{
    if (a != a) {
        return 1;
    }
    else {
        return 0;
    }
}


// const char* option_list[] { "--help",
//                            "--tests" } -> TEST
// switch()
//==================================================================================================

int ParsArgs(int argc, char* argv[])
{   
    int val = 0;

    for(int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--tests") == 0) {
                val = 1;
            }
        if (strcmp(argv[i], "--help") == 0) {
            printf("What this program can:\n"
                "This program can solve quadratic equation,"
                "u should just enter coefficients a,b and c,"
                "and program will return number of solutions\n"
                "Version 8.0\nMade by Ivan Novokhatskii 21.07.2022\n");
        }
        if (strcmp(argv[i], "durak") == 0) {
            printf("a mozhet sam durak?");
        }
        if (strcmp(argv[i], "cs") == 0) {
            printf("game for bastards");
        }
        if (strcmp(argv[i], "ded") == 0) {
            printf("budesh persik ili nektarin?");
        }
    }
    return val;
}


void ScanCoeff(double* a, double* b, double* c)
{
    scanf("%lf %lf %lf", a, b, c);
    
    FreeBoofer(); // buffer

    while (Is_NaN(*a) || (Is_NaN(*b)) || (Is_NaN(*c)))
    {
        printf("One of the numbers is invalid\n");
        printf("Try again, enter your numbers:\n");

        int result = scanf ("%lf %lf %lf", a, b, c);
        if (result == 3) break;

        FreeBoofer();

        //free scanf buffer function c
        printf ("ENTER THE NUMBERS MAN, I SAID!!!\n");
    }
}

//==============================================================================================================
void printAnswersLinear(int n_roots, double* x1)
{
    if (n_roots == 0) {
        printf("0: no roots\n");
    }
    if (n_roots == infinity_roots) {
        printf("infinity number of roots\n");
    }
    if (n_roots == 1) {
        printf("equation has only one solution\n%lg\n", *x1);
    }
}

//================================================================================================================

void printAnswersQuadro(int n_roots, double* x1, double* x2)
{
    switch (n_roots)
        {
        case 1:
            printf("one root\nx = %lg\n", *x1);
            break;
        case 2:
            printf("two roots\nx1 = %lg\nx2 = %lg", *x1, *x2);
            break;
        case 0:
            printf("no roots");
            break;

        case -1:
            printf("uncountable amount of roots");
        default:
            printf("%d %d", __LINE__, n_roots);
            
            break;
        }
        
}


void FreeBoofer()
{
    int x = 0;
    while ((x = getchar()) != EOF && x != '\n') 
        ;
}

//===============================================================================================================

char cmp(double a, double b)
{

    return abs(a - b) < precision;
    //return ((llabs(a-b)) < precision) ? 1 : 0;
}

//=========================================================================================================


double discriminant(double a, double b, double c)
{
    assert (!Is_NaN(a));
    assert (!Is_NaN(b));
    assert (!Is_NaN(c));

    double D = b * b - 4 * a * c;
    return D;
}


//=========================================================================================================



 double SolveQuadro(double a, double b, double c, double* x1, double* x2)
 {
    
    double D = discriminant(a, b, c);

    if (D < 0) {
        return 0;
    }
    else {   
        if (cmp(D, 0) == 1) {
            *x1 = -0.5*b / a;
            if (Is_NaN(*x1) == 1) {
                printf("Error in line %d", __LINE__);
            
            }
            else {
                return 1;

            }
        }
        else {
            int sqrtD = sqrt(D);
            *x1 = 0.5 * (-b + sqrtD) / a;
            *x2 = 0.5 * (-b - sqrtD) / a;

            if ((Is_NaN(*x1)) || (Is_NaN(*x2))) {
                printf("Error in line %d", __LINE__);
            }
            else {
                return 2;
            }
        }

    }
}

//=========================================================================================================

double SolveLinear(double b, double c, double* x1)
{
    if (cmp(b, 0) == 1) {
            if (cmp(c, 0) == 1)
            {
                return infinity_roots;
            }
            else
            {
                return 0;
            }
        }
        else
        {      
            if (cmp(c, 0) == 1) {
                return 1;
            }
            else
            {
                *x1 = -c / b;

                if (Is_NaN(*x1) == 1)
                {
                    printf("Error in line %d", __LINE__);
                }
                else {
                    return 1;
                } 
            }  
        }
}

//========================================================================================

// void AddUnitTest(int* amountofunittests, UnitTest* num)
// {
//     double a, b, c, num_of_solutions, x1, x2;
    
//     for(int number_of_unit_test = 0; number_of_unit_test < *amountofunittests; number_of_unit_test++){
//         scanf("%lg %lg %lg %lg %lg %lg", &a, &b, &c, &num_of_solutions, &x1, &x2);
//         num[number_of_unit_test].a = a;   //array[i]= *(array + i)
//         num[number_of_unit_test].b = b;
//         num[number_of_unit_test].c = c;
//         num[number_of_unit_test].num_of_solutions = num_of_solutions;
//         num[number_of_unit_test].x1 = x1;
//         num[number_of_unit_test].x2 = x2;

//     }
// }

//==============================================================================================================

void CheckAndDefineUnitTest()

{   

    UnitTest num[15] = {{0, 0, 0, -1, 0, 0},
                        {0, 0, 1, 0, 0, 0}, 
                        {0, 1, 0, 1, 0, 0}, 
                        {0, 1, 1, 1, -1, 0}, 
                        {1, 0, 0, 1, 0, 0}, 
                        {1, 0, 1, 0, 0, 0}, 
                        {1, 1, 0, 2, 0, -1},
                        {1, 1, 1, 0, 0, 0},
                        {2, 3, 4, 0, 0, 0},
                        {5, 18, 14, 2, -1.136675, -2.463324}, 
                        {43, 28, 11, 0, 0, 0},
                        {1, 256, 3, 2, -0.011719, -255.98828}, 
                        {sqrt(3), 6, sqrt(2), 2, -0.25438, -3.20972}, 
                        {sqrt(41), 28, sqrt(30), 2, -0.20525, -4.16762}, 
                        {1, 220, 70, 2, -0.318643334, -219.681356}};

    
    for(int i = 0 ; i < 15; i++) {

        if((cmp(num[i].a, 0)) == 1)
        {   
            double x1 = 0; 
            
            int num_of_solutions_by_program = SolveLinear(num[i].b, num[i].c, &x1);
            if (num_of_solutions_by_program == num[i].num_of_solutions)
            {
                if((num_of_solutions_by_program == 0) ||  (num_of_solutions_by_program == -1))
                {
                    printf("Test %d successfully completed\nwith coefficients %lg %lg %lg\n", 
                            i, num[i].a, num[i].b, num[i].c);
                }
                if(num_of_solutions_by_program == 1) {
                    if(cmp(x1, num[i].x1) == 1) {
                        printf("Test %d successfully completed\nwith coefficients %lg %lg %lg\n", 
                                i, num[i].a, num[i].b, num[i].c);
                    }
                    else{
                        printf("Test %d Failed\nwith coefficients %.2lf %.2lf %.2lf\n", 
                                i, num[i].a, num[i].b, num[i].c);
                    }
                }
            }
            else
            {
                printf("Test %d Failed\nwith coefficients %.2lf %.2lf %.2lf\n", 
                        i, num[i].a, num[i].b, num[i].c);
            }

        }
        else
        {
            double x1 = 0;
            double x2 = 0;
            int num_of_solutions_by_program = SolveQuadro(num[i].a, num[i].b, num[i].c, &x1, &x2);
            if (num_of_solutions_by_program == num[i].num_of_solutions)
            {
                if((num_of_solutions_by_program == 0) ||  (num_of_solutions_by_program == -1))
                {
                    printf("Test %d successfully completed\nwith coefficients %lg %lg %lg\n", i, num[i].a, num[i].b, num[i].c);
                }
                if(num_of_solutions_by_program == 1){
                    if(cmp(x1, num[i].x1) == 1){
                        printf("Test %d successfully completed\nwith coefficients %lg %lg %lg\n", i, num[i].a, num[i].b, num[i].c);
                    }
                    else{
                        printf("Test %d Failed\nwith coefficients%lf %lf %lf\n", i, num[i].a, num[i].b, num[i].c);
                    }
                }
                if(num_of_solutions_by_program == 2){
                    if((cmp(x1, num[i].x1) == 1) && (cmp(x2, num[i].x2) == 1))
                    {
                        printf("Test %d successfully completed\nwith coefficients %lg %lg %lg\n", i, num[i].a, num[i].b, num[i].c);
                    }
                    else{
                        printf("test %d failed\nwith coefficients %lf %lf %lf\n", i, num[i].a, num[i].b, num[i].c);
                    }
                }
            }
            else
            {
                printf("Test %d Failed\nwith coefficients%lf %lf %lf\n", i, num[i].a, num[i].b, num[i].c);
            }
        }
      }
}




//=========================================================================================================


    // scanf ("%lf %lf %lf", &a, &b, &c);

    // int x;
    // while ((x = getchar()) != EOF && x != '\n');

    // if (Is_NaN(a) || (Is_NaN(b)) || (Is_NaN(c)))
    // {
    //     printf("One of the numbers is invalid");
    // 
    // while (Is_NaN(a) || (Is_NaN(b)) || (Is_NaN(c)))
    // {
    //     printf("One of the numbers is invalid\n");
    //     printf("Try again, enter your numbers:\n");

    //     scanf ("%lf %lf %lf", &a, &b, &c);
    //     while ((x = getchar()) != EOF && x != '\n'); //quastion to ded

    //     //free scanf buffer function c
    //     printf ("\n");

    // }
    // int UnitTests()
// {
//     double coefficients[45] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 3, 4, 5, 18, 14, 43, 28, 11, 1, 256, 3, sqrt(3), 6, sqrt(2), sqrt(41), 28, sqrt(30), 1, 220, 70};
//     int number_of_solutions[15] = {-1, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2, 2, 2};
//     double solutions[30] = {infinity, infinity, infinity, infinity, 0, 0, -1, -1, 0, 0, infinity, infinity, 0, -1, infinity, infinity, infinity, infinity, -1.136675, -2.463324, infinity, infinity, -0.011719, -255.98828, -0.25438, -3.20972, -0.20525, -4.16762, -0.318643334, -219.681356};
//     double solutions_by_program[30] = {};
//     int counter_of_right_tests = 0;
//     for(int number_of_equations = 0; number_of_equations < 15; number_of_equations++)
//     {   
    
//     //printf("%d", number_of_equations);
//         if (number_of_equations < 4)
//         {
//             int number_of_solutions_by_program = SolveLinear(coefficients[3 * number_of_equations + 1], coefficients[3 * number_of_equations + 2], &solutions_by_program[2 * number_of_equations]);
//             if(number_of_solutions_by_program == number_of_solutions[number_of_equations]){
//                 if((number_of_solutions[number_of_equations] == 0) || (number_of_solutions[number_of_equations] == -1)){
//                     counter_of_right_tests += 1;
//                     //printf("%d\n", number_of_equations);
//                 }
//                 else{
//                     if(llabs(solutions_by_program[number_of_equations * 2] - solutions[number_of_equations * 2]) < precision){
//                         counter_of_right_tests += 1;
                        
//                         //printf("%d\n", number_of_equations);
//                     }
//                 }
            
//             }
//             //test1 - completed
//             //test2 - completed
//             //test3 - failed
//             //test4 - completed //
//         }

//         else
//         {
//             int number_of_solutions_by_program = SolveQuadro(coefficients[3 * number_of_equations], coefficients[3 * number_of_equations + 1], coefficients[3 * number_of_equations + 2], &solutions_by_program[2 * number_of_equations], &solutions_by_program[2 * number_of_equations + 1]);
//             if(number_of_solutions_by_program == number_of_solutions[number_of_equations]){
//                 if((number_of_solutions[number_of_equations] == 0) || (number_of_solutions[number_of_equations] == -1)){

//                     counter_of_right_tests += 1;
//                     //printf("%d\n", number_of_equations);
//                 }
//                 else{
//                     if((llabs(solutions_by_program[number_of_equations * 2] - solutions[number_of_equations * 2]) < precision) &&(llabs(solutions_by_program[number_of_equations * 2 + 1] - solutions[number_of_equations * 2 + 1]) < precision)){
//                         counter_of_right_tests += 1;
//                         //printf("%d\n", number_of_equations);
//                     }
//                 }
//             }
        
//         }
//         //printf("%d\n", counter_of_right_tests);
        
//     }
//     return counter_of_right_tests;
  

// }