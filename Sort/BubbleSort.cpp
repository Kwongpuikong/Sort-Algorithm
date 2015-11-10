/*BubbleSort Algorithm*/
/*Author: Loapui*/
/*2015.11.10*/

#include "BubbleSort.h"
#include "HeapSort.h"


void BubbleSort(int L[], int length){

	for (int i = 1; i < length; i++){
	
		for (int j = length - 1; j >= i; j--){
		
			if (L[j + 1] < L[j]){
			
				swap(L, j, j + 1);
			}
		}
	}
}

void BubbleSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){
	
		std::cout << L[i] << '\t';
	}
	std::cout << std::endl;
}