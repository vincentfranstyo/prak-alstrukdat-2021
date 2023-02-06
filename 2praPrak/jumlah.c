#include <stdio.h>

int main (){
	int n = 0, rem = 0, sum = 0;
	scanf("%d", &n);

	while (n > 0){
		rem = n % 10;
		sum += rem;
		n /= 10;
	}
	printf("%d\n", sum);
	return 0;
}