// Nama 		: Vincent Franstyo
// NIM 		: 18221100
// Tanggal 	: 14/11/2022
// Topik		: Queue List
// Deskripsi	: Implementasi Queue List
#include <stdio.h>
#include "queuelist.h"

void Alokasi(address *P, infotype X){
	*P = (address) malloc (sizeof(ElmtQueue));

	if ((*P) != Nil){
		Info(*P) = X;
		Next(*P) = Nil;
	}
	else {
		(*P) = Nil;
	}
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi(address P){
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty(Queue Q){
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
	address p = Head(Q);
	int count = 0;
	while (p != Nil){
		count ++;
		p  = Next(p);
	}

	return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue *Q){
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X){
	address p;
	Alokasi(&p, X);

	if (p != Nil){

		if (IsEmpty(*Q)){
			Head(*Q) = p;
			Tail(*Q) = p;
		}

		else{
			Next(Tail(*Q)) = p;
			Tail(*Q) = p;
		}
		
	}
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */

void Dequeue(Queue *Q, infotype *X){
	(*X) = InfoHead(*Q);
	address p = Head(*Q);
	Head(*Q) = Next(p);
	if (Head(*Q) == Nil){
		Tail(*Q) = Nil;
	}
	Next(p) = Nil;
	Dealokasi(p);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */