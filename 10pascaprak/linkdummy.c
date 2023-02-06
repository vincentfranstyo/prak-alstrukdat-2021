// Nama 		: Vincent Franstyo
// NIM 			: 18221100
// Tanggal 		: 14/11/2022
// Topik		: Link Dummy
// Deskripsi	: Implementasi Link Dummy

#include <stdio.h>
#include "linkdummy.h"


boolean IsEmpty(List L){
	return First(L) == Last(L); 
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L){
	ElType n = 0;
	address p = Alokasi(n);

	if (p != Nil){
		First(*L) = p;
		Last(*L) = p;
	}

	else{
		First(*L) = Nil;
		Last(*L) = Nil;
	}
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X){
	address p = (address) malloc (sizeof(Node));

	if (p != Nil){
		Info(p) = X;
		Next(p) = Nil;
		return p;
	}
	else{
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X){
	address p = First(L);
	Info(Last(L)) = X;

	while ((Info(p) != X)){
		p = Next(p);
	}

	if (p != Last(L)){
		return p;
	}

	else{
		return Nil;
	}
}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X){
	address p = Alokasi(X);

	if (p != Nil){
		Next(p) = First(*L);
		First(*L) = p;
	}

}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X){
	address prec = First(*L);

	if (IsEmpty(*L)){
		InsertFirst(L, X);
	}

	else{
		address p = Alokasi(X);
		while (Next(prec) != Last(*L)){
			prec = Next(prec);
		}
		Next(prec) = p;
		Next(p) = Last(*L);
	}
	
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X){
	address p = First(*L);

	(*X) = Info(p);
	First(*L) = Next(First(*L));
	Next(p) = Nil;
	Dealokasi(p);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X){
	address prec = Nil, Last = First(*L);

	while (Next(Last) != Last(*L)){
		prec = Last;
		Last = Next(Last);
	}

	(*X) = Info(Last);
	if (prec == Nil){
		First(*L) = Last(*L);
	}

	else{
		Next(prec) = Last(*L);
	}
	Dealokasi(Last);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */