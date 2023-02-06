#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin(){
	/**
 	* Konstruktor
 	* I.S. sembarang
 	* F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 	*/
 	ArrayDin array;
 	(array).A = (ElType*) malloc (InitialSize * sizeof(ElType));
 	(array).Capacity = InitialSize;
 	(array).Neff = 0;
 	return array;
}

void DeallocateArrayDin (ArrayDin *array){
	/**
 	* Destruktor
	* I.S. ArrayDin terdefinisi
 	* F.S. array->A terdealokasi
 	*/
 	free(array -> A);
 	array -> Neff = 0;
 	array -> Capacity = 0;
}

boolean IsEmpty(ArrayDin array){
	/**
 	* Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 	* Prekondisi: array terdefinisi
 	*/
 	return ((array).Neff == 0);
}

int Length(ArrayDin array){
	/**
 	* Mengembalikan elemen array L yang ke-I (indeks lojik).
 	* Prekondisi: array tidak kosong, i di antara 0..Length(array).
 	*/
	return (array).Neff;
}

ElType Get(ArrayDin array, IdxType i){
	/**
 	* Mengembalikan elemen array L yang ke-I (indeks lojik).
 	* Prekondisi: array tidak kosong, i di antara 0..Length(array).
 	*/
 	return (array).A[i];
}

int GetCapacity(ArrayDin array){
	/**
 	* Fungsi untuk mendapatkan kapasitas yang tersedia.
 	* Prekondisi: array terdefinisi
 	*/
 	return (array).Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i){
	/**
 	* Fungsi untuk menambahkan elemen baru di index ke-i
 	* Prekondisi: array terdefinisi, i di antara 0..Length(array).
 	*/
 	int temp = 0;

 	((array) -> Neff)++;

 	while (i <= (array) -> Neff){
 		temp = (array)->A[i];
 		(array)->A[i] = el;
 		(array)->A[i+1] = temp;
 		i++;
 	}
}

void DeleteAt(ArrayDin *array, IdxType i){
	/**
 	* Fungsi untuk menghapus elemen di index ke-i ArrayDin
 	* Prekondisi: array terdefinisi, i di antara 0..Length(array).
 	*/
 	while (i <= (array)->Neff){
 		(array)->A[i] = (array)->A[i+1];
 		i++;
 	}

 	(array)->Neff--;
}
