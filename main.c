#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loading_data.h"
#include "required_structures.h"
#include "simple_regression.h"
#include "vector_summaries.h"

/*
typedef struct {
    int nrows, ncols;
    char name[MAX_COLS][MAX_NAME];
    double *col[MAX_COLS];
} Dataset;
*/

int main(void) {
    Dataset d = {0};

    if (load_csv("../sample60.csv", &d) == 1) {
        printf("Loaded %d rows and %d columns.\n", d.nrows, d.ncols);
    }
    printf("Loaded successfully\n");

    // // Print out column names
    // for (int i = 0; i < d.ncols; i++) {
    //     printf("%f, ", d.col[i][0]);
    // }


    double *educ = get_col(&d, "educ");
    double *lwage = get_col(&d, "lwage");

    // for (int i = 0; i < d.nrows; i++) {
    //     printf("This is the education: %f", educ[i]);
    //     printf("\n");
    //     printf("This is the lwage: %f", lwage[i]);
    // }

    printf("This is the mean of education: %f\n", mean(educ, d.nrows));
    printf("This is the mean of lwage: %f\n", mean(lwage, d.nrows));


    printf("This is the variance of education: %f\n", variance(educ, d.nrows));
    printf("This is the variance of lwage: %f\n", variance(lwage, d.nrows));

    printf("This is the standard deviation of education: %f\n", std_dev(educ, d.nrows));
    printf("This is the standard deviation of lwage: %f\n", std_dev(lwage, d.nrows));

    printf("This is the covariance of education on lwage: %f\n", covariance(educ, lwage, d.nrows));
    printf("This is the correlation between education and lwage: %f\n", correlation(educ, lwage, d.nrows));

    SimpleOLS simols = simple_ols(educ, lwage, d.nrows);


    printf("This is the intercept %f\n", simols.b0);
    printf("This is the slope for education: %f", simols.b1);


    // ---- sums of squares and fit ----
    printf("This is SST: %f\n", simols.sst);                                     // 12.661470
    printf("This is SSE: %f\n", simols.sse);                                     // 5.532811
    printf("This is SSR: %f\n", simols.ssr);                                     // 7.128659
    printf("This is R-squared: %f\n", simols.r2);                                // 0.436980
    printf("This is sigma-hat (std error of regression): %f\n", simols.sigma);   // 0.350582

    // ---- standard errors and t values ----
    printf("This is the standard error of the intercept: %f\n", simols.se_b0);   // 0.199886
    printf("This is the standard error of the slope: %f\n", simols.se_b1);       // 0.015112

    return 0;

}


