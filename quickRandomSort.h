//
// Created by root on 23.10.18.
//

#ifndef MIITCOMPLEXTYOFQUICKRANDOMSORT_COMPLEXITYCHECKER_H
#define MIITCOMPLEXTYOFQUICKRANDOMSORT_COMPLEXITYCHECKER_H

#include <glob.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define a 48271
#define m 2147483647
#define q (m / a)
#define r (m % a)
void quickSortEnvoke(int arr[], int low, int high, double *avg);

long int PMrand();


#endif //MIITCOMPLEXTYOFQUICKRANDOMSORT_COMPLEXITYCHECKER_H
