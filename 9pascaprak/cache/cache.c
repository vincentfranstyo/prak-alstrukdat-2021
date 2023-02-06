// Nama 		: Vincent Franstyo
// NIM 			: 18221100
// Tanggal		: 7/11/2022
// Topik		: Cache
// Deskripsi	: implementasi cache

#include <stdio.h>
#include "listlinier.h"

int main(){
	int n = 0;
	scanf("%d", &n);
	List cache;
	CreateEmpty(&cache);
	for (int i = 1; i <= n; i++){
		InsVLast(&cache, i);
	}

	int q = 0;
	int inp = 0;
	scanf("%d", &q);
	infotype deleted;
	for (int i = 0; i < q; i++){
		scanf("%d", &inp);
		if (Search(cache, inp) != Nil){
			DelP(&cache, inp);
			InsVFirst(&cache, inp);
			printf("hit ");
			PrintInfo(cache);
			printf("\n");
		}

		else{
			printf("miss ");
			DelVLast(&cache, &deleted);
			InsVFirst(&cache, inp);
			PrintInfo(cache);
			printf("\n");
		}
	}
	return 0;
}