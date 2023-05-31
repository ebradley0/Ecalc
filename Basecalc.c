#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    if (debounce == 0)
    {
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
        }
    }
    if (debounce == 0)
    {
        printf("The Answer is: %lf\n\n", sum);
        return 0;
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
