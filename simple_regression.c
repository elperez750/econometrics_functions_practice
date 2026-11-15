//
// Created by elper on 11/14/2026.
//

#include "simple_regression.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "required_structures.h"
#include "vector_summaries.h"

/*
*typedef struct {
    int n;
    double b0, b1;
    double sst, sse, ssr, r2, sigma;
    double se_b0, se_b1, t_b0, t_b1, p_b0, p_b1;
    double ci_b1_lo, ci_bb1_hi;
} SimpleOLS;

 *
 */

SimpleOLS simple_ols(const double *x, const double*y, int n) {
    double variance_x = variance(x, n);
    double variance_y = variance(y, n);
    double mean_x = mean(x, n);
    double mean_y = mean(y, n);
    double covariance_x_y = covariance(x, y, n);

    printf("Mean x: %f\n", mean_x);
    printf("Mean y: %f\n", mean_y);

    SimpleOLS ols_model = {0};
    ols_model.b1 = covariance_x_y / variance_x;

    ols_model.b0 = mean_y - (ols_model.b1 * mean_x);

    double *y_hat = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        y_hat[i] = ols_model.b0 + ols_model.b1 * x[i];
    }

    ols_model.ssr = sum_sq_residuals(y, y_hat, n);
    free(y_hat);
    ols_model.sst = variance_y * (n - 1);
    ols_model.sse = ols_model.sst - ols_model.ssr;
    ols_model.r2 = r_squared(ols_model.sse, ols_model.sst);
    ols_model.sigma = sqrt(ols_model.ssr / (n - 2));
    ols_model.se_b0 = ols_model.sigma * sqrt((1.0 / n) + ((mean_x * mean_x) / (variance_x * (n-1))));
    ols_model.se_b1 = ols_model.sigma / sqrt((variance_x * (n-1)));

    return ols_model;

}

double sum_sq_residuals(const double *y, const double *y_hat, int n) {
    double ssr = 0;
    for (int i = 0; i < n; i++) {
        ssr += (y[i] - y_hat[i]) * (y[i] - y_hat[i]);
    }
    return ssr;
}

double r_squared(double sse, double sst) {
    return sse / sst;
}
