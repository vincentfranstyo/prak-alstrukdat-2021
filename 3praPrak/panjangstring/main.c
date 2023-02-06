#include <stdio.h>
#include "panjangstring.h"

int main(){
	//KAMUS
	char inp[100];
	// char * inp;
	// char str[100];

	//Algoritma
	// inp = str;
	// scanf("%s", str);
	scanf("%s", &inp);
	printf("Panjang string ini adalah \n");
	printf("%d\n", panjangString(inp));
	return 0;
}
