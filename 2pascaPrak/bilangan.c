#include <stdio.h>

int isCantik(int x){
	int found = 0, rem = 0;
	if (x % 7 == 0){
		found = 1;
	}
	else{
		while (x > 6){
			if (x % 10 == 7){
				found = 1;
			}
			x /= 10;
		}
	}
	return found;
}

int main(){
	int n = 0;
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i ++){
		int inp = 0, sum = 0;
		scanf("%d", &inp);

		for (j = 0; j <= inp; j++){
			if (isCantik(j) == 1){
				sum += j;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}