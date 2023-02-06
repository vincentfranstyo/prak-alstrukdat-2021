#include <stdio.h>

int fact(int x){
	int res = 1;
	while (x > 1){
		res *= x;
		x -= 1;
	}

	return res;
}

int main(){
	int num = 0, sum = 0, rem = 0, origin = 0;
	scanf("%d", &num);
	origin = num;
	while (num >= 10){
		rem = num % 10;
		sum += fact(rem);
		num /= 10;
	}
	sum += fact(num);
	printf("%d", sum);
	// printf("%d", origin);
	if (sum == origin){
		printf("Y\n");
	}
	else{
		printf("N\n");
	}
	return 0;
}