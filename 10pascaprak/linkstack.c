// Nama 		: Vincent Franstyo
// NIM 			: 18221100
// Tanggal 		: 14/11/2022
// Topik		: Stack List
// Deskripsi	: Implementasi Stack list

#include <stdio.h>
#include "linkstack.h"

void Alokasi(address *P, ElType X){
	(*P) = (address) malloc (sizeof(Node));

	if ((*P) != Nil){
		Info(*P) = X;
		Next(*P) = Nil;
	}

	else{
		(*P) = Nil;
	}
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P){
	free(P);
}
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S){
	return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push(Stack *S, ElType X){
	address p;
	Alokasi(&p, X);

	if (p != Nil){
		Next(p) = Top(*S);
		Top(*S) = p;
	}
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop(Stack *S, ElType *X){
	(*X) = InfoTop(*S);

	address p = Top(*S);
	Top(*S) = Next(p);
	Next(p) = Nil;
	Dealokasi(p);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */