#include "calc.h"
#include <stdio.h>

static int add(calc_t *calc, double arg_1, double arg_2) // Takes in 3 arguments, first one connects the type functions in calc.h to our calculator?
{
    static int counter = 0;
    counter++;
    printf("Counter: %i\n", counter);
    calc->result = arg_1 + arg_2; // Here we use pointers to tell it what to do when it receives the result command. Basically, the command runs, and then it sets the result memory adress to the answer. We can then acess this later using the calc.result, or use it in further calculations.
    return 0;
}

static int subtract(calc_t *calc, double arg_1, double arg_2)
{
    printf("Subtraction started!\n");
    calc->result = arg_1;
    calc->result = calc->result - arg_2;
    return 0;
}

static int multiply(calc_t *calc, double arg_1, double arg_2)
{
    printf("Multiplication started!\n");
    calc->result = arg_1;
    calc->result = calc->result * arg_2;
    return 0;
}

int calc_init(calc_t *calc) // Here we sort of connect the dots between calc.h and calc.c. We tell it what to do when it receives a certain connection. For example, calc.add would initalize the add function
{
    calc->add = add;
    calc->substract = subtract;
    calc->multiply = multiply;
    return 0;
}