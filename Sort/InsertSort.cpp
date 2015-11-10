/*InsertSort Algorithm*/
/*Author: Loapui*/
/*2015.11.10*/

#include "InsertSort.h"

void InsertSort(int L[], int length){

	for (int i = 2; i <= length; i++){
	
		L[0] = L[i]; // ÉèÖÃÉÚ±ø
		int j;
		for (j = i - 1; L[j] > L[0]; j--){
		
			L[j + 1] = L[j];
		}
		L[j + 1] = L[0];
	}
}

void InsertSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){

		std::cout << L[i] << '\t';
	}
	std::cout << std::endl;
}
