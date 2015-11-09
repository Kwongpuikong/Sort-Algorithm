/*ShellSort Algorithm*/
/*Author: Loapui*/
/*2015.11.8*/

#include "ShellSort.h"

void ShellSort(int L[], int length){

	int seq[] = { 4, 2, 1 };
	for (int k = 0; k < 3; k++){
	
		int increment = seq[k];
		for (int i = 1 + increment; i <= length; i++){
		
			int j;
			if (L[i] < L[i - increment]){

				L[0] = L[i];
				for (j = i - increment; j>0 && L[j]>L[0]; j -= increment){
				
					L[j + increment] = L[j];
				}
				L[j + increment] = L[0];
			}
		}
		std::cout << "increment = " << seq[k] << std::endl;
		ShellSort_print(L, length);
	}
}

void ShellSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){
	
		std::cout << L[i] << '\t';
	}

	std::cout << std::endl;
}