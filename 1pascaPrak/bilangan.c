#include <stdio.h>

int main(){
	int x = 0;
	scanf("%d", &x);
	if (x == 2 || x % 2 != 0){
		printf("Tidak\n");
	}
	else{
		printf("Ya\n");
	}
	return 0;
}