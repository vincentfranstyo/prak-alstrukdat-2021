#include <stdio.h>
#include "hashmap.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
	for (int i = 0; i < MaxEl; i++){
		(*M).Elements[i].Key = Undefined;
		(*M).Elements[i].Value = Undefined;
	}
	(*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
	address hashKey;
	hashKey = K % MaxEl;
	return hashKey;
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k){
	valuetype val = Undefined;
	int i = 0;
	boolean found = false;
	while (i < MaxEl && !found){
		if ((M).Elements[i].Key == k){
			val = M.Elements[i].Value;
			found = true;
		}
		else{
			i ++;
		}
	}
	
	return val;
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v){
	// mengecek apabila ada di dalam hash map
	int i = 0;
	boolean found = false;
	while (i < MaxEl && !found){
		if ((*M).Elements[i].Key == k){
			found = true;
		}
		else{
			i ++;
		}
	}	

	// jika tidak ada di hashmap
	address hashKey = Hash(k);
	if (!found){
		// probing jika index hashkey telah terisi
		while ((*M).Elements[(hashKey)].Key != Undefined){
			hashKey ++;
		}
		// memasukkan ke index hashkey yang telah ditemukan
		(*M).Elements[hashKey].Key = k;
		(*M).Elements[hashKey].Value = v;
		(*M).Count++;
	}
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi     */