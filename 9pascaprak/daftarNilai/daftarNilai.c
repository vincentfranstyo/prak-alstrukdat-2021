// Nama     : Vincent Franstyo
// NIM      : 18221100
// Tanggal : 5/11/2022
// Topik    : implementasi ADT ListLinear
// Deskripsi    : implementasi ADT List Linear

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	List daftarNilai;
	CreateEmpty(&daftarNilai);
	int n = 0;
	while (n >= 0 && n <= 100){
		scanf("%d", &n);
		if (n >= 0 && n <= 100){
			InsVFirst(&daftarNilai, n);
		}
	}

	if (NbElmt(daftarNilai) > 0){
		printf("%d\n", NbElmt(daftarNilai));
		printf("%d\n", Max(daftarNilai));
		printf("%d\n", Min(daftarNilai));
		printf("%.2f\n", Average(daftarNilai));
		InversList(&daftarNilai);
		PrintInfo(daftarNilai);
		printf("\n");
		InversList(&daftarNilai);
		PrintInfo(daftarNilai);
		printf("\n");
	}

	else{
		printf("Daftar nilai kosong\n");
	}

	return 0;
}