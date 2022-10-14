#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void PrintArray(int *array, int iBeg, int iEnd);
void CopyArray(int *array, int iBeg, int iEnd, int *work_copy);
void TopDownMerge(int *array, int iBeg, int iMid, int iEnd, int *work_copy);
void TopDownSplitMerge(int *work_copy, int iBeg, int iEnd, int *array);
void merge_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif
