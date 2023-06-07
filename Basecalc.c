#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD

typedef enum
{
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    CONSTANT, // Multiply a list of numbers by a given value
} function_t;

function_t arg_to_function(char *arg);

int main(int argc, char *argv[], char *arg)
{
    unsigned int i; // for loop
    int p;
    char g; // Function type reference
    char b;
    double MULTIPLIER = 0; // For multiplying a list
    double sum = 0;
    double sumM = 1;
    double DIV1 = 0;
    double sumS = 0;
    int debounce = 0;
    double results;
    double storage[100];
    char my_string[10];

    // printf("Input: %s\n", argv[1]);

    function_t function = arg_to_function(argv[1]);

    g = *argv[1];
    b = *argv[2];

    // printf("%s\n\n", argv[1]);
=======
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
>>>>>>> broken

    /*

        FUNCTIONS BELOW


    */

    if (argc <= 3)
    {
<<<<<<< HEAD
        printf("A function can proceed!\n\n");

        if (function == CONSTANT)
        {
            debounce == 1;
            char *z = argv[2];
            MULTIPLIER = strtod(z, &z);
            printf("MULTIPLING BY CONSTANT\n");
            for (i = 3; i < argc; i++)
            {
                char *y = argv[i];
                results = strtod(y, &y);
                results = results * MULTIPLIER;
                printf("Result: %lf\n", results);
            }
            exit(1);
        }

        if (function == ADDITION)
        {
            for (i = 2; i < argc; i++)
            {

                // -------------------------------ADD
                char *y = argv[i];

                results = strtod(y, &y);

                sum = sum + results;
            }
        }

        else if (function == SUBTRACTION)
        {
            char *t = argv[2];
            sumS = strtod(t, &t);

            for (i = 3; i < argc; i++)
            {
                //---------------------------SUBTRACT
                char *y = argv[i];

                results = strtod(y, &y);
                // sumS represents the first number, so that subtractions can be performed. It is updated to the result for multi number divisions
                sum = sumS - results;
                sumS = sum;
            }
        }

        else if (function == MULTIPLICATION)
        {
            for (i = 2; i < argc; i++)
            {
                //--------------------------------MULTIPLY
                char *y = argv[i];

                results = strtod(y, &y);

                // In order to avoid yielding a 0, sumM represents the first # to be multiplied, it is then updated to equal the result for multi number divisions.
                sum = sumM * results;
                sumM = sum;
            }
        }
        else if (function == DIVISION)
        {

            char *z = argv[2];
            DIV1 = strtod(z, &z);

            for (i = 3; i < argc; i++)
            {
                // ----------------------------------DIVIDE
                char *y = argv[i];

                results = strtod(y, &y);

                // DIV1 represents base number, it will then be updated by to equal the result for multi number divisions.
                sum = DIV1 / results;
                DIV1 = sum;
            }
=======
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
>>>>>>> broken
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

function_t arg_to_function(char *arg)
{
    function_t function = 0;

    if (strncmp(arg, "-H", 1) == 0)
    {
        printf("THIS IS A HELP STATEMENT\n\n");
        printf("Welcome to E-Calc! A completely unnecessary and simple caluclator\nThe following 4 commands are currently available:\n\n A - Adding\n S - Subtraction\n M - Multiplication\n D - Division\n C - Multiply a list by a constant\n\n\n In order to run the program, use the following format: (Function - See list) #1, #2, #3, etc. \n\n Currently, the calculations will run off the first input number, so keep that in mind for everything other than addition!\n\n");
        exit(-1);
    }

    if (strncmp(arg, "M", 1) == 0) // Choosing type of function
    {
        printf("You're multiplying\n");
        function = MULTIPLICATION;
    }

    else if (strncmp(arg, "D", 1) == 0)
    {
        printf("You're dividing\n");
        function = DIVISION;
    }

    else if (strncmp(arg, "S", 1) == 0)
    {
        printf("You're subtracting\n");
        function = SUBTRACTION;
    }
    else if (strncmp(arg, "A", 1) == 0)
    {
        printf("You're adding\n");
        function = ADDITION;
    }
    else if (strncmp(arg, "-H", 1) == 0)
    {

        printf("THIS IS A HELP MESSAGE!\n\n");
        exit(1);
    }
    else if (strncmp(arg, "C", 1) == 0)
    {

        printf("Multiplying a list");
        function = CONSTANT;
    }

    else
    {
        printf("Please enter a valid function type. For a list of accepted functions use --H.\n");
        exit(1);
    }
    return function;
}
