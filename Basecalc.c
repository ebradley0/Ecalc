#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

typedef enum
{
    CALC_FUNC_INVALID,
    CALC_FUNC_ADD,
    CALC_FUNC_SUBTRACT,
    CALC_FUNC_MULTIPLY,
    CALC_FUNC_DIVIDE,
} calc_func_t;

enum argument
{
    HELP = 'H',
    ADD = 'A',
    SUBTRACT = 'S',
    MULTIPLY = 'M',
    DIVIDE = 'D',
};

calc_func_t parse_args(char arg)
{
    calc_func_t fn;

    switch (arg)
    {
    case HELP:
        printf("THIS IS A HELP STATEMENT\n\n");
        break;
    case ADD:
        printf("You're adding\n");
        fn = CALC_FUNC_ADD;
        break;
    case SUBTRACT:
        printf("You're subtracting\n");
        fn = CALC_FUNC_SUBTRACT;
        break;
    case MULTIPLY:
        printf("You're multiplying\n");
        fn = CALC_FUNC_MULTIPLY;
        break;
    case DIVIDE:
        printf("You're dividing\n");
        fn = CALC_FUNC_DIVIDE;
        break;
    default:
        printf("Please enter a valid function type. For a list of accepted functions use --H.\n");
        fn = CALC_FUNC_INVALID;
        break;
    }

    return fn;
}

int main(int argc, char *argv[])
{
    int i;
    int p;
    char g;
    char b;
    double sum = 0;
    double sumM = 1;
    double DIV1 = 0;
    double sumS = 0;
    int debounce = 0;
    double results;
    int function = 0;

    char arg = HELP; // Default to help
    char *parg;
    if (argv[1] && (strncmp(argv[1], "-", 1) == 0))
    {
        parg = strrchr(argv[1], '-');
        arg = (char)*(parg + 1);
    }
    else if (argv[1])
    {
        arg = (char)*(argv[1]);
    }

    function = parse_args(arg);

    calc_t mycalc;
    int err = calc_init(&mycalc);
    if (err)
    {
        printf("Calculator failed!\n");
    }
    err = mycalc.add(&mycalc, 4.0, 60);
    err = mycalc.add(&mycalc, mycalc.result, 40);
    if (err)
    {
        printf("Addition failed!\n");
    }

    printf("Addition Result: %f\n", mycalc.result);

    if (debounce == 0)
    {
        printf("A function can proceed!\n\n");
        if (function == 1)
        {
            for (i = 2; i < argc; i++)
            {
                char *y = argv[i];

                results = strtod(y, &y);

                sum = sum + results;
            }
        }

        else if (function == 2)
        {
            char *t = argv[2];
            sumS = strtod(t, &t);

            for (i = 3; i < argc; i++)
            {
                char *y = argv[i];

                results = strtod(y, &y);

                sum = sumS - results;
                sumS = sum;
            }
        }

        else if (function == 3)
        {
            for (i = 2; i < argc; i++)
            {
                char *y = argv[i];

                results = strtod(y, &y);

                sum = sumM * results;
                sumM = sum;
            }
        }
        else if (function == 4)
        {

            char *z = argv[2];
            DIV1 = strtod(z, &z);

            for (i = 3; i < argc; i++)
            {
                char *y = argv[i];

                results = strtod(y, &y);

                sum = DIV1 / results;
                DIV1 = sum;
            }
        }
    }
    if (debounce == 0)
    {
        printf("The Answer is: %lf\n\n", sum);
        return 0;
    }
}
