#include <stdio.h>
#include "stack.h"

int main(){
	int n = -1;
	int *arr;
	int i = 0;
	while (n != 0){
		scanf("%d", &n);
		arr[i] = n;
		i++;
	}
	int len = i - 1;
	
	Stack s1;
	CreateEmpty(&s1);
	for (i = 0; i < len; i++){
		// printf("%d", arr[i]);
		Push(&s1, arr[i]);
		// printf("%d", InfoTop(s1));
	}

	// printf("\n");
	if (IsEmpty(s1)){
		printf("Stack kosong\n");
	}

	else{
		Stack s2, s3;
		CreateEmpty(&s2);
		CreateEmpty(&s3);
		infotype x;
		while (!IsEmpty(s1)){
			Pop(&s1, &x);
			Push(&s2, x);
			Push(&s3, x);
			// printf("%d", InfoTop(s2));
		}
		// printf("\n");

		while (!IsEmpty(s3)){
			Pop(&s3, &x);
			Push(&s1, x);
		}

		boolean found = false;
		for (i = 0; i < Top(s1); i++){
			if (s1.T[i] != s2.T[i]){
				found = true;
			}
		}

		if (found){
			printf("Bukan Palindrom\n");
		}

		else{
			printf("Palindrom\n");
		}
	}
	return 0;
}