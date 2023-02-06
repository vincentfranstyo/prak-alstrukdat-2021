#include <stdio.h>

#include "OddEvenList.h"

int main(){
	List L, Odd, Even;
	CreateEmpty(&L);

	int n = 0;
	while (n >= 0 && n <= 100){
		scanf("%d", &n);
		if (n >= 0 && n <= 100){
			InsVFirst(&L, n);
		}
	}

	OddEvenList(L, &Odd, &Even);
	
	PrintInfo(L);
	printf("\n");

	PrintInfo(Even);
	printf("\n");

	PrintInfo(Odd);
	printf("\n");
	return 0;
}