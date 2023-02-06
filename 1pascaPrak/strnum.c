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
	int angka = 0;
	int origin = 0;
	int hasil = 0;
	int faktorial = 0;
	int hitung = 0;
	scanf("%d", &angka);
	origin = angka;

	while(angka > 0){
		hitung  = angka % 10;
		faktorial = fact(hitung);
		hasil += faktorial;
		angka /= 10;
	}

	printf("%d\n", hasil);
	if (origin == hasil){
		printf("Y\n");
	}
	else{
		printf("N\n");
	}
	// printf("%d\n", )
	// printf("%d", fact(angka));
	return 0;
}