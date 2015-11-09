/*MergeSort Algorithm*/
/*Author: Loapui*/
/*2015.11.9*/

#include "MergeSort.h"

void Merge(int S[], int T[], int s1_start, int s1_end, int s2_end){
	/*将S内两个有序的子序列归并到T中*/
	/*两个有序的子序列分别是1:s1_start~s1_end 和 2:s1_end+1~s2_end*/
	int i1 = s1_start, i2 = s1_end + 1, k = s1_start;

	/*比较下标索引记录中数据，小的赋值至辅助空间，并下标后移*/
	for (; i1 <= s1_end && i2 <= s2_end; k++){
	
		if (S[i1] < S[i2]){

			T[k] = S[i1++];
		}
		else
			T[k] = S[i2++];
	}

	/*对于未越界的下标对应的序列，将其中序列中的数据复制至辅助空间*/
	/*注：for循环的跳出一定是i1>s1_end 或 i2>s2_end
		则另一个还仍满足i2<=s2_end 或 i1<=s1_end
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
	注：长度为s_len的子序列，两两归并后的长度为2*s_len，
		则最后一个要归并的始端下标为length-2*s_len+1
	*/
	while (i <= length - 2 * s_len + 1){

		Merge(S, T, i, i + s_len - 1, i + 2 * s_len - 1);
		i += 2 * s_len;
	}

	/*
	跳出循环时，i有两种情况
	1：i>length， 表示归并已经完成
	2：i<length，这种情况又分成两种情况
	*/
	/*
	21：i<length-s+1：有1个长度为s_len的序列和1个长度不足s_len的序列，这两个序列仍需归并
	22：i>=length-s+1：有1个长度为s_len的序列或1个长度不足s_len的序列，只有一个序列，直接复制至辅助空间
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
	当k<n时，之前的k一定是k<length/2，
	则两两归并后还会有数据残留，所以循环仍要进行
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