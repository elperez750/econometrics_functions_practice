//
// Created by elper on 11/14/2026.
//

#ifndef ECONOMETRICS_FUNCTIONS_PRACTICE_LOADING_DATA_H
#define ECONOMETRICS_FUNCTIONS_PRACTICE_LOADING_DATA_H
#include "required_structures.h"

int load_csv(const char *path, Dataset *ds);

double *get_col(const Dataset *ds, const char *name);

void free_dataset(Dataset *ds);


#endif //ECONOMETRICS_FUNCTIONS_PRACTICE_LOADING_DATA_H
