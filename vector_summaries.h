//
// Created by elper on 11/14/2026.
//

#ifndef ECONOMETRICS_FUNCTIONS_PRACTICE_VECTOR_SUMMARIES_H
#define ECONOMETRICS_FUNCTIONS_PRACTICE_VECTOR_SUMMARIES_H

double sum(const double *x, int n);
double mean(const double *x, int n);
double variance(const double *x, int n);
double std_dev(const double *x, int n);
double covariance(const double *x, const double *y, int n);
double correlation(const double *x, const double *y, int n);
double min_value(const double *x, int n);
double max_value(const double *x, int n);
void transform_log(const double *x, const double *out, int n);
void transform_square(const double *x, const double *out, int n);


#endif //ECONOMETRICS_FUNCTIONS_PRACTICE_VECTOR_SUMMARIES_H
