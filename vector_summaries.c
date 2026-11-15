//
// Created by elper on 11/14/2026.
//

#include "vector_summaries.h"
#include <math.h>

double sum(const double *x, int n) {
    double total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += x[i];
    }
    return total_sum;
}

double mean(const double *x, int n) {
    double total_sum = sum(x, n);
    return total_sum / n;
}

double variance(const double *x, int n) {
    double sample_mean = mean(x, n);
    double variance_sample = 0;
    for (int i = 0; i < n; i++) {
        variance_sample += (x[i] - sample_mean) * (x[i] - sample_mean);
    }
    return variance_sample / (n - 1);
}


double std_dev(const double *x, int n) {
    double sample_variance = variance(x, n);
    return sqrt(sample_variance);
}

double covariance(const double *x, const double *y, int n) {
    double x_mean = mean(x, n);
    double y_mean = mean(y, n);
    double terms_added = 0;
    for (int i = 0; i < n; i++) {
        terms_added += (x[i] - x_mean) * (y[i] - y_mean);
    }
    return terms_added / (n - 1);
}

double correlation(const double *x, const double *y, int n) {
    return covariance(x, y, n) / (std_dev(x, n) * std_dev(y, n));
}

double min_value(const double *x, int n) {
    double min = INFINITY;
    for (int i = 0; i < n; i++) {
        if (x[i] < min) {
            min = x[i];
        }
    }
    return min;
}

double max_value(const double *x, int n) {
    double max = -INFINITY;
    for (int i = 0; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max;

}









