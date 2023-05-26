#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CALC_FUNC_INVALID,
    CALC_FUNC_ADD,
    CALC_FUNC_SUBTRACT,
    CALC_FUNC_MULTIPLY,
    CALC_FUNC_DIVIDE,
} calc_func_t;

enum argument {
    HELP = 'H',
    ADD = 'A',
    SUBTRACT = 'S',
    MULTIPLY = 'M',
    DIVIDE = 'D',
};

calc_func_t parse_args(char arg)
{
    calc_func_t fn;

    switch (arg) {
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

int main(int argc, char* argv[])
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
    double storage[100];
    int function = 0;

    char arg = HELP; // Default to help
    char* parg;
    if (argv[1] && (strncmp(argv[1], "-", 1) == 0)) {
        parg = strrchr(argv[1], '-');
        arg = (char)*(parg + 1);
    } else if (argv[1]) {
        arg = (char)*(argv[1]);
    }

    function = parse_args(arg);

    if (debounce == 0) {
        printf("A function can proceed!\n\n");
        if (function == 1) {
            for (i = 2; i < argc; i++) {
                //  printf("----ADDING----\n\n");
                //   printf("Number logged\n"); // -------------------------------ADD
                char* y = argv[i];
                //  printf("%s\n", y);
                results = strtod(y, &y);
                //  printf("%f\n\n\n", results);
                sum = sum + results;
                // printf("RESULT -------- %lf\n\n", sum);
            }
        }

        else if (function == 2) {
            char* t = argv[2];
            sumS = strtod(t, &t);

            for (i = 3; i < argc; i++) {
                //  printf("Number logged\n"); //---------------------------SUBTRACT
                char* y = argv[i];
                //  printf("%s\n", y);
                results = strtod(y, &y);
                //  printf("%f\n\n\n", results);
                sum = sumS - results;
                sumS = sum;
                // printf("RESULT -------- %lf\n\n", sum);
            }
        }

        else if (function == 3) {
            for (i = 2; i < argc; i++) {
                // printf("Number logged\n"); //--------------------------------MULTIPLY
                char* y = argv[i];
                // printf("%s\n", y);
                results = strtod(y, &y);
                //   printf("%f\n\n\n", results);

                sum = sumM * results;
                sumM = sum;
                // printf("RESULT -------- %lf\n\n", sum);
            }
        } else if (function == 4) {
            // printf("You're dividing\n");
            char* z = argv[2];
            DIV1 = strtod(z, &z);
            // printf("First - %lf\n\n", DIV1);
            for (i = 3; i < argc; i++) {
                // printf("Number logged\n"); // ----------------------------------DIVIDE
                char* y = argv[i];
                // printf("%s\n", y);
                results = strtod(y, &y);
                // printf("%f\n\n\n", results);

                sum = DIV1 / results;
                DIV1 = sum;

                // printf("RESULT -------- %lf\n\n", sum);
            }
        }
    }
    if (debounce == 0) {
        printf("The Answer is: %lf\n\n", sum);
        return 0;
    }
}
