//
// Created by elper on 11/14/2026.
//

#ifndef ECONOMETRICS_FUNCTIONS_PRACTICE_SIMPLE_REGRESSION_H
#define ECONOMETRICS_FUNCTIONS_PRACTICE_SIMPLE_REGRESSION_H
#include "required_structures.h"


SimpleOLS simple_ols(const double *x, const double *y, int n);
double sum_sq_residuals(const double *y, const double *yhat, int n);
double r_squared(double sse, double sst);

#endif //ECONOMETRICS_FUNCTIONS_PRACTICE_SIMPLE_REGRESSION_H
