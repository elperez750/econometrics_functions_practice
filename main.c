#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loading_data.h"
#include "required_structures.h"

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

    // Print out column names
    for (int i = 0; i < d.ncols; i++) {
        printf("%f, ", d.col[i][0]);
    }


    return 0;

}


