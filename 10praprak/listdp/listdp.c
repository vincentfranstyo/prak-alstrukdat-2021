// Nama 		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 12/11/2022
// Topik		: Implementasi ADT List Linear dengan double pointer
// Deskripsi 	: Implementasi ADT List Linear dengan double pointer

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L) == Nil) && (Last(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
	Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	ElmtList *p = (ElmtList *) malloc (sizeof(ElmtList));

	if (p != Nil){
		Info(p) = X;
		Next(p) = Nil;
		Prev(p) = Nil;
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address p = First(L);

	while ((p != Nil) && (Info(p) != X)){
		 p = Next(p);
	}

	return p;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address p = Alokasi(X);

	if (p != Nil){
		InsertFirst(L, p);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X){
	address p = Alokasi(X);

	if (p != Nil){
		InsertLast(L, p);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	address p;
	DelFirst(L, &p);
	(*X) = Info(p);
	Dealokasi(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X){
	address p;
	DelLast(L, &p);
	(*X) = Info(p);
	Dealokasi(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	if (IsEmpty(*L)){
		Next(P) = Nil;
		Prev(P) = Nil;
		First(*L) = P;
		Last(*L) = P;
	}
	else{
		Next(P) = First(*L);
		Prev(P) = Nil;
		Prev(First(*L)) = P;
		First(*L) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertLast (List *L, address P){
	if (IsEmpty(*L)){
		InsertFirst(L, P);
	}
	else{
		Next(P) = Nil;
		Prev(P) = Last(*L);
		Next(Last(*L)) = P;
		Last(*L) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void InsertAfter (List *L, address P, address Prec){
	Next(P) = Next(Prec);
	Prev(P) = Prec;
	Next(Prec) = P;
	if (Next(P) == Nil){
		Last(*L) = P;
	}

	else{
		Prev(Next(P)) = P;
	}
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertBefore (List *L, address P, address Succ){
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
	if (Prev(P) == Nil){
		First(*L) = P;
	}
	else{
		Next(Prev(P)) = P;
	}

}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	(*P) = First(*L);

	if (Next(*P) != Nil){
		First(*L) = Next(*P);
		Prev(First(*L)) = Nil;
	}

	else{
		First(*L) = Nil;
		Last(*L) = Nil;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, address *P){
	(*P) = Last(*L);

	if (Prev(*P) == Nil){
		Last(*L) = Nil;
		First(*L) = Nil;
	}

	else{
		Last(*L) = Prev(*P);
		Next(Last(*L)) = Nil;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void DelP (List *L, infotype X){
	if (!IsEmpty(*L)){
		address P = Search(*L, X);

		if (P != Nil){
			if (P == First(*L)){
				DelFirst(L, &P);
			}
			else if (P == Last(*L)){
				DelLast(L, &P);
			}
			else{
				Next(Prev(P)) = Next(P);
				Prev(Next(P)) = Prev(P);
			}
		}
		Dealokasi(P);
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);

	if (*Pdel != Nil){
		Next(Prec) = Next(*Pdel);
		if (Next(Prec) != Nil){
			Prev(Next(Prec)) = Prev(Prev(Next(Prec)));
		}	 
		else{
			Last(*L) = Prec;
		}
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelBefore (List *L, address *Pdel, address Succ){
	*Pdel = Prev(Succ);

	if (*Pdel != Nil){
		Prev(Succ) = Prev(*Pdel);
		if (Prev(Succ) != Nil){
			Next(Prev(Succ)) = Next(Next(Prev(Succ)));
		}

		else{
			First(*L) = Succ;
		}
	}
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
	if (IsEmpty(L)){
		printf("[]");
	}

	else{
		address p = First(L);
		printf("[%d", Info(p));
		p = Next(p);

		while (p != Nil){
			printf(",%d", Info(p));
			p = Next(p);
		}

		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void PrintBackward (List L){
	if (IsEmpty(L)){
		printf("[]");
	}

	else{
		address p = Last(L);
		printf("[%d", Info(p));
		p = Prev(p);

		while (p != Nil){
			printf(",%d", Info(p));
			p = Prev(p);
		}
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */