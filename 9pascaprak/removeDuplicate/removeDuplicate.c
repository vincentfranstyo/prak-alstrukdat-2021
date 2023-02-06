// Nama 		: Vincent Franstyo
// NIM 			: 18221100
// Tanggal		: 7/11/2022
// Topik		: removeDuplicate
// Deskripsi	: menghapus bilangan yang duplikat

#include <stdio.h>
#include <stdlib.h>
#include "removeDuplicate.h"
#include "listlinier.h"

List removeDuplicate(List l){
	List l2;
	CreateEmpty(&l2);
	address p = First(l);
	while (p != Nil){
		if (Search(l2, Info(p)) == Nil){
			InsVLast(&l2, Info(p));
		}

		p = Next(p);
	}

	return l2;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/

// int main(){
// 	List l1;
// 	int n = 0;
// 	while (n >= 0 && n <= 10){
// 		scanf("%d", n);
// 		InsVLast(&l1, n);
// 	}

// 	removeDuplicate(l1);
// }