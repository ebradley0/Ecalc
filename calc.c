#include "calc.h"
#include <stdio.h>

static int add(calc_t *calc, double arg_1, double arg_2)
{
    static int counter = 0;
    counter++;
    printf("Counter: %i\n", counter);
    calc->result = arg_1 + arg_2;
    return 0;
}

int calc_init(calc_t *calc)
{
    calc->add = add;

    return 0;
}