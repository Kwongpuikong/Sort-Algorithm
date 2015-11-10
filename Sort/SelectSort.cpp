/*SelectSort Algorithm*/
/*Author: Loapui*/
/*2015.11.10*/

#include "SelectSort.h"
#include "HeapSort.h"

void SelectSort(int L[], int length){

	for (int i = 1; i < length; i++){

		int min = i;
		for (int j = i + 1; j <= length; j++){
		
			if (L[min] > L[j]){
			
				min = j;
			}
		}
		if (i != min){
		
			swap(L, i, min);
		}
	}
}

void SelectSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){
	
		std::cout << L[i] << '\t';
	}
	std::cout << std::endl;
}
