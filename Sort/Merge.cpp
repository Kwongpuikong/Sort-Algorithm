/*MergeSort Algorithm*/
/*Author: Loapui*/
/*2015.11.9*/

#include "MergeSort.h"

void Merge(int S[], int T[], int s1_start, int s1_end, int s2_end){
	/*��S����������������й鲢��T��*/
	/*��������������зֱ���1:s1_start~s1_end �� 2:s1_end+1~s2_end*/
	int i1 = s1_start, i2 = s1_end + 1, k = s1_start;

	/*�Ƚ��±�������¼�����ݣ�С�ĸ�ֵ�������ռ䣬���±����*/
	for (; i1 <= s1_end && i2 <= s2_end; k++){
	
		if (S[i1] < S[i2]){

			T[k] = S[i1++];
		}
		else
			T[k] = S[i2++];
	}

	/*����δԽ����±��Ӧ�����У������������е����ݸ����������ռ�*/
	/*ע��forѭ��������һ����i1>s1_end �� i2>s2_end
		����һ����������i2<=s2_end �� i1<=s1_end
	*/
	if (i1 <= s1_end){
	
		for (int l = 0; l < s1_end - i1 + 1; l++){
		
			T[k + l] = S[i1 + l];
		}
	}
	if (i2 <= s2_end){
	
		for (int l = 0; l < s2_end - i2 + 1; l++){

			T[k + l] = S[i2 + l];
		}
	}
}

void MergeNeighbour(int S[], int T[], int s_len, int length){

	int i = 1;

	/*
	ע������Ϊs_len�������У������鲢��ĳ���Ϊ2*s_len��
		�����һ��Ҫ�鲢��ʼ���±�Ϊlength-2*s_len+1
	*/
	while (i <= length - 2 * s_len + 1){

		Merge(S, T, i, i + s_len - 1, i + 2 * s_len - 1);
		i += 2 * s_len;
	}

	/*
	����ѭ��ʱ��i���������
	1��i>length�� ��ʾ�鲢�Ѿ����
	2��i<length����������ֳַ��������
	*/
	/*
	21��i<length-s+1����1������Ϊs_len�����к�1�����Ȳ���s_len�����У���������������鲢
	22��i>=length-s+1����1������Ϊs_len�����л�1�����Ȳ���s_len�����У�ֻ��һ�����У�ֱ�Ӹ����������ռ�
	*/

	if (i < length - s_len + 1){
	
		Merge(S,T,i,i+s_len-1, length);
	}
	else{
		for (int j = i; j <= length; j++){

			T[j] = S[j];
		}
	}
}

void MergeSort(int L[], int length){

	int s_len = 1;
	int *T = (int*)malloc(MAXSIZE*sizeof(int));
	/*
	��k<nʱ��֮ǰ��kһ����k<length/2��
	�������鲢�󻹻������ݲ���������ѭ����Ҫ����
	*/
	while (s_len < length){
	
		MergeNeighbour(L, T, s_len, length);
		std::cout << "sequence length = " << s_len << std::endl;
		MergeSort_print(T, length);

		s_len *= 2;
		MergeNeighbour(T, L, s_len, length);
		std::cout << "sequence length = " << s_len << std::endl;
		MergeSort_print(L, length);

		s_len *= 2;
		
	}
}

void MergeSort_print(int L[], int length){

	for (int i = 1; i <= length; i++){

		std::cout << L[i] << '\t';
	}

	std::cout << std::endl;
}