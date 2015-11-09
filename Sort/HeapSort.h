/*HeapSort Algorithm*/
/*Author: Loapui*/
/*2015.11.8*/

#ifndef HEAPSORT_H
#define	HEAPSORT_H

#include <iostream>

void HeapAdjust(int L[], int start, int end);
void HeapSort(int L[], int length);
void swap(int L[], int i, int j);
void HeapSort_print(int L[], int length);

#endif