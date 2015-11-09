/*HeapSort Algorithm*/
/*Author: Loapui*/
/*2015.11.8*/

#include "HeapSort.h"

void HeapAdjust(int L[], int start, int end){

	int temp = L[start]; // '��ֵ'
	for (int j = 2 * start; j <= end; j *= 2){
	
		if (j < end && L[j] < L[j + 1]){
		
			j++; // ��¼����
		}
		if (temp < L[j]){
		
			L[start] = L[j];
			start = j; // �Դ���Ϊ��֧�ڵ�������������ѭ������
		}
		else{
		
			break;
		}
	}
	L[start] = temp;

}

void HeapSort(int L[], int length){

	// ��������һ��ѭ�����̣� ���������ϣ��������ң������еķ�֧�����жѵ�����
	for (int i = length / 2; i > 0; i--){
	
		HeapAdjust(L, i, length);
	}
	std::cout << "Finish Constructing Heap..." << std::endl;
	HeapSort_print(L, length);

	for (int j = 1; j < length; j++){
	
		swap(L, 1, length - j + 1);
		HeapAdjust(L, 1, length - j);
		std::cout << "The " << j << " runs:" << std::endl;
		HeapSort_print(L, length);
	}
}

void swap(int L[], int i, int j){

	int temp = L[i];
	L[i] = L[j];
	L[j] = temp;
}

void HeapSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){

		std::cout << L[i] << '\t';
	}

	std::cout << std::endl;
}