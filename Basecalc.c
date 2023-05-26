#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i; // for loop
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
    int function = 0;
    printf("Input: %s\n", argv[1]);
    g = *argv[1];
    b = *argv[2];
    //  printf("%c\n\n\n", g);
    //  printf("%c\n\n", b);
    printf("%s\n\n", argv[1]);

    if (g == 'H')
    {
        printf("THIS IS A HELP STATEMENT\n\n");
        return -1;
    }

    if (g == 'M') // Choosing type of function
    {
        printf("You're multiplying\n");
        function = 3;
    }
    else if (g == 'D')
    {

        function = 4;
    }
    else if (g == 'S')
    {
        printf("You're subtracting\n");
        function = 2;
    }
    else if (g == 'A')
    {
        printf("You're adding\n");
        function = 1;
    }
    else if (g == 'H')
    {

        printf("THIS IS A HELP MESSAGE!");
        debounce = 1;
    }
    else
    {
        printf("Please enter a valid function type. For a list of accepted functions use --H.\n");
        debounce = 1;
        return 1;
    }

    if (debounce == 0)
    {
        printf("A function can proceed!\n\n");
        if (function == 1)
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

        else if (function == 2)
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

        else if (function == 3)
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
        else if (function == 4)
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
