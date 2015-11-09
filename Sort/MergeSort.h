/*MergeSort Algorithm*/
/*Author: Loapui*/
/*2015.11.9*/

#ifndef MERGESORT_H
#define MERGESORT_H

#define MAXSIZE 50
#include <iostream>

void Merge(int S[], int T[], int s1_start, int s1_end, int s2_end);
void MergeNeighbour(int S[], int T[], int s_len, int length);
void MergeSort(int L[], int length);
void MergeSort2(int L[],int T[], int start, int end);

void MergeSort_print(int L[], int length);


#endif