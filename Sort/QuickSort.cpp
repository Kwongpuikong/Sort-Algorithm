/*QuickSort Algorithm*/
/*Author: Loapui*/
/*2015.11.9*/

#include "QuickSort.h"

int Partition(int L[], int low, int high){

	int pivotkey = L[low];

	while (low < high){
	
		while (low<high && L[high] > pivotkey){

			high--;
		}
		L[low] = L[high];

		while (low < high && L[low] < pivotkey){

			low++;
		}
		L[high] = L[low];
	}
	L[low] = pivotkey;
	return low;
}

void QuickSort(int L[], int low, int high){

	if (low < high){
	
		int pivot = Partition(L, low, high);
		QuickSort(L, low, pivot-1);
		QuickSort(L, pivot+1, high);
	}
}

void QuickSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){

		std::cout << L[i] << '\t';
	}

	std::cout << std::endl;
}