#include <stdio.h>
#include "MinMax.h"
#include "list.h"

ElType minimum(List L){
	IdxType i;	
	ElType min = 99999;
	for (i = 0; i <= LastIdx(L); i++){
		if (min >= L.A[i]){
			min = L.A[i];
		}
	}
	return min;
}

ElType maximum(List L){
	IdxType i;
	ElType max = 0;
	for (i = 0; i <= LastIdx(L); i++){
		if (max <= L.A[i]){
			max = L.A[i];
		}
	}
	return max;
}

IdxType GetIdx(List L, ElType val){
	IdxType i, found;
	for (i = 0; i <= LastIdx(L); i++){
		if (L.A[i] == val){
			found = i;
			break;
		}
	}
	return found;
}

List MinMax(List L){
	ElType minVal = minimum(L), maxVal = maximum(L);

	DeleteAt(&L, GetIdx(L, minVal));
	InsertLast(&L, minVal);
	DeleteAt(&L, GetIdx(L, maxVal));
	InsertLast(&L, maxVal);

	return L;
}

// int main(){
// 	list = MakeList();
// 	InsertFirst (L, 1);
// 	printf("");
// 	return 0;
// }