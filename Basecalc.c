#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
int fn;
typedef enum
{
    CALC_FUNC_INVALID,
    CALC_FUNC_ADD,
    CALC_FUNC_SUBTRACT,
    CALC_FUNC_MULTIPLY,
    CALC_FUNC_DIVIDE,
    CALC_FUNC_LIST,
} calc_func_t;

enum argument
{
    HELP = 'H',
    ADD = 'A',
    SUBTRACT = 'S',
    MULTIPLY = 'M',
    DIVIDE = 'D',
    CONSTANT = 'C',
};

enum temp
{
    placeholder = 'Y',
};

calc_func_t
parse_args(char arg)
{
    calc_func_t fn;

    switch (arg)
    {
    case HELP:
        printf("Welcome to E-Calc! A completely unnecessary and simple caluclator\nThe following 4 commands are currently available:\n\n A - Adding\n S - Subtraction\n M - Multiplication\n D - Division\n C - Multiply a list by a constant\n\n\n In order to run the program, use the following format: (Function - See list) #1, #2, #3, etc. \n\n Currently, the calculations will run off the first input number, so keep that in mind for everything other than addition!\n\n");
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
    case CONSTANT:
        printf("Multiplying a list!\n");
        fn = CALC_FUNC_LIST;
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
    unsigned int i;
    double results;
    double inputs;
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
    calc_t mycalc;                // Creates a adress (in this case object) for our calculator
    int err = calc_init(&mycalc); // Creates a variable at previous adress
    if (err)
    {
        printf("Calculator failed!\n");
    }
    if (err)
    {
        printf("Addition failed!\n");
    }

    /*

        FUNCTIONS BELOW


    */

    if (argc <= 3)
    {
        printf("Whoops! Looks like you forgot to include enough numbers to do some math! For further assistance use -H\n");
        exit(1);
    }
    if (function == CALC_FUNC_ADD)

    {
        // For loop starting at 2 to ignore function and command declaration
        for (i = 2; i < argc; i++)
        {
            char *placeholder = argv[i];
            char *end;
            inputs = strtod(argv[i], &end); // Converting command line argument to double for use in caluclation
            printf("INPUT ======== %lf\n", inputs);

            err = mycalc.add(&mycalc, mycalc.result, inputs);
        }
        printf("Result: %f\n", mycalc.result);
    }

    else if (function == CALC_FUNC_SUBTRACT)
    {
        mycalc.result = atof(argv[2]);
        for (i = 3; i < argc; i++)
        {
            inputs = atof(argv[i]);
            err = mycalc.substract(&mycalc, mycalc.result, inputs);
        }
        printf("Results: %f\n", mycalc.result);
    }

    else if (function == CALC_FUNC_MULTIPLY)
    {
        mycalc.result = atof(argv[2]);
        for (i = 3; i < argc; i++)
        {
            inputs = atof(argv[i]);
            err = mycalc.multiply(&mycalc, mycalc.result, inputs);
        }
        printf("Results: %f\n", mycalc.result);
    }
    else if (function == CALC_FUNC_DIVIDE)
    {
        mycalc.result = atof(argv[2]);
        for (i = 3; i < argc; i++)
        {
            inputs = atof(argv[i]);
            err = mycalc.divide(&mycalc, mycalc.result, inputs);
        }
        printf("Results: %f\n", mycalc.result);
    }
    else if (function == CALC_FUNC_LIST)
    {
        mycalc.constant = atof(argv[2]);
        for (i = 3; i < argc; i++)
        {
            inputs = atof(argv[i]);
            mycalc.list(&mycalc, inputs, mycalc.constant);
            printf("Result: %lf\n", mycalc.result);
        }
    }
}
