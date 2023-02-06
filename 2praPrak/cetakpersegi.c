#include <stdio.h>

int main(){
	int n = 0, s = 0;
	scanf("%d", &n);
	s = 2 * n - 1;

	int i, j;
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)){
				printf("O");
			}
			else{
				printf("X");
			}
		}
		printf("\n");
	}
	return 0;
}