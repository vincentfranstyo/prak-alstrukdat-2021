// Nama     : Vincent Franstyo
// NIM      : 18221100
// Tanggal : 5/11/2022
// Topik    : OddEvenList
// Deskripsi    : memisahkan elemen ganjil dan genap dari list L dengan mengurut membesar


#include <stdio.h>
#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even){
	CreateEmpty(Odd);
	CreateEmpty(Even);

	List L2;
	CreateEmpty(&L2);

	address p = First(L);

	while (p != Nil){
		InsVLast(&L2, Info(p));
		p = Next(p);
	}

	while (!IsEmpty(L2)){
		infotype min = Min(L2);
		if (min % 2 == 0){
			InsVLast(Even, min);
			DelP(&L2, min);
		}

		else{
			InsVLast(Odd, min);
			DelP(&L2, min);
		}
	}
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/