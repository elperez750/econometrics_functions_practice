//
// Created by elper on 11/14/2026.
//

#include "loading_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct {
    int nrows, ncols;
    char name[MAX_COLS][MAX_NAME];
    double *col[MAX_COLS];
} Dataset;
*/

int load_csv(const char *path, Dataset *ds) {
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL) {
        perror("There was an error opening the file");
        return 0;
    }

    char line[256];
    fgets(line, sizeof(line), fptr);

    char *token = strtok(line, ",");

    while (token != NULL) {
        int len = strlen(token);
        for (int i = 0; i < len; i++) {
            ds->name[ds->ncols][i] = token[i];
        }
        ds->ncols++;
        ds->name[ds->ncols][len] = '\0';
        token = strtok(NULL, ",\r\n");
    }

    for (int i = 0; i < ds->ncols; i++) {
        // So for each column, we define an array that can store at most 100 doubles
        ds->col[i] = malloc(100 * sizeof(double));
    }


    // While there is a line to get
    while (fgets(line, sizeof(line), fptr) != NULL) {
        char *p = strtok(line, ",");
        char *end;
        int c = 0;

        while (p != NULL && c < ds->ncols) {
            double x = strtod(p, &end);
            if (end == p) return 0;
            ds->col[c][ds->nrows] = x;
            c++;
            p = strtok(NULL, ",\n");
        }
        ds->nrows++;


    }

    return 1;
}
