//
// Created by elper on 11/14/2026.
//

#ifndef ECONOMETRICS_FUNCTIONS_PRACTICE_REQUIRED_STRUCTURES_H
#define ECONOMETRICS_FUNCTIONS_PRACTICE_REQUIRED_STRUCTURES_H
#define MAX_COLS 16
#define MAX_NAME 32


typedef struct {
    int nrows, ncols;
    char name[MAX_COLS][MAX_NAME];
    double *col[MAX_COLS];
} Dataset;



typedef struct { /* a 2-D table of numbers, stored row by row */
    int rows, cols;
    double *data; /* element (i,j) is data[i*cols + j] */
} Matrix;


typedef struct { double lo, hi; } Interval; /* confidence / prediction interval */


typedef struct { /* result of any hypothesis test */
    double stat; /* t, F, z, or chi-square statistic */
    double p; /* p-value */
    double df1, df2; /* degrees of freedom (df2 = 0 if not used) */
} TestResult;



typedef struct { /* everything from one regression */
    int n, p, df; /* df = n - p */
    double *beta; /* length p */
    double *se, *t, *pval; /* length p each (pval is two-sided) */
    double *fitted, *resid; /* length n each */
    double sst, sse, ssr;
    double r2, adj_r2;
    double sigma; /* sqrt(ssr / df) */
    double f_stat, f_p; /* overall F test: all slopes zero */
    Matrix *xtx_inv; /* (X’X)^-1, kept for tests and predictions */
} OLS;


typedef struct { /* a prediction at one point x0 */
    double fit;
    double se_mean; /* standard error of the fitted average */
    Interval ci; /* for the AVERAGE y at x0 */
    Interval pi; /* for ONE new y at x0 */
} Prediction;



#endif //ECONOMETRICS_FUNCTIONS_PRACTICE_REQUIRED_STRUCTURES_H
