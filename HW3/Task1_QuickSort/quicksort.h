#ifndef QUICKSORT_H
#define QUICKSORT_H

template <typename T>
void quicksort(T arr[], int left, int right);

template <typename T>
int partition(T arr[], int left, int right);

#include "quicksort.cpp"

#endif // QUICKSORT_H

