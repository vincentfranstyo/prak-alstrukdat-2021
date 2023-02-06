#include <stdio.h>

int main (){
	int z = 0, rem = 0, rev = 0;

	scanf("%d", &z);

	while (z > 0){
		rev *= 10;
		rem = z % 10;
		rev += rem;
		z /= 10;
	} 
	printf("%d\n", rev);
	return 0;
}