#ifndef CALC_H__
#define CALC_H__

typedef struct calc_s calc_t;

typedef int (*calc_operator_t)(calc_t *calc, double arg_1, double arg_2);

struct calc_s // This struct defines the different operators, so when we run the thing these act as sort of commands. For example calc.add would initalize an add function in calc.c
{
    double result;
    double constant;
    calc_operator_t add;
    calc_operator_t substract;
    calc_operator_t multiply;
    calc_operator_t divide;
    calc_operator_t list;
};

int calc_init(calc_t *calc);

#endif // CALC_H__