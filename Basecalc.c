#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
} function_t;

function_t arg_to_function(char *arg);

int main(int argc, char *argv[])
{
    unsigned int i; // for loop
    int p;
    char g; // Function type reference
    char b;
    double sum = 0;
    double sumM = 1;
    double DIV1 = 0;
    double sumS = 0;
    int debounce = 0;
    double results;
    double storage[100];
    char my_string[10];

    printf("Input: %s\n", argv[1]);

    function_t function = arg_to_function(argv[1]);

    g = *argv[1];
    b = *argv[2];
    //  printf("%c\n\n\n", g);
    //  printf("%c\n\n", b);

    printf("%s\n\n", argv[1]);

    if (debounce == 0)
    {
        printf("A function can proceed!\n\n");
        if (function == ADDITION)
        {
            for (i = 2; i < argc; i++)
            {
                //  printf("----ADDING----\n\n");
                //   printf("Number logged\n"); // -------------------------------ADD
                char *y = argv[i];
                //  printf("%s\n", y);
                results = strtod(y, &y);
                //  printf("%f\n\n\n", results);
                sum = sum + results;
                // printf("RESULT -------- %lf\n\n", sum);
            }
        }

        else if (function == SUBTRACTION)
        {
            char *t = argv[2];
            sumS = strtod(t, &t);

            for (i = 3; i < argc; i++)
            {
                //  printf("Number logged\n"); //---------------------------SUBTRACT
                char *y = argv[i];
                //  printf("%s\n", y);
                results = strtod(y, &y);
                //  printf("%f\n\n\n", results);
                sum = sumS - results;
                sumS = sum;
                // printf("RESULT -------- %lf\n\n", sum);
            }
        }

        else if (function == MULTIPLICATION)
        {
            for (i = 2; i < argc; i++)
            {
                // printf("Number logged\n"); //--------------------------------MULTIPLY
                char *y = argv[i];
                // printf("%s\n", y);
                results = strtod(y, &y);
                //   printf("%f\n\n\n", results);

                sum = sumM * results;
                sumM = sum;
                // printf("RESULT -------- %lf\n\n", sum);
            }
        }
        else if (function == DIVISION)
        {
            // printf("You're dividing\n");
            char *z = argv[2];
            DIV1 = strtod(z, &z);
            // printf("First - %lf\n\n", DIV1);
            for (i = 3; i < argc; i++)
            {
                // printf("Number logged\n"); // ----------------------------------DIVIDE
                char *y = argv[i];
                // printf("%s\n", y);
                results = strtod(y, &y);
                // printf("%f\n\n\n", results);

                sum = DIV1 / results;
                DIV1 = sum;

                // printf("RESULT -------- %lf\n\n", sum);
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

    if (strncmp(arg, "H", 1) == 0)
    {
        printf("THIS IS A HELP STATEMENT\n\n");
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

    else
    {
        printf("Please enter a valid function type. For a list of accepted functions use --H.\n");
        exit(1);
    }
    return function;
}
