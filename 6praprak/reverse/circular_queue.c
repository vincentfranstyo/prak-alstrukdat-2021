#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"
#include "boolean.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
	return (Q.HEAD == NIL) && (Q.TAIL == NIL);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull (Queue Q){
	return (Length(Q) == Q.MaxEl);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int Length (Queue Q){
	if (IsEmpty(Q)){
		return 0;
	}

	else{
		// kondisi saat head <= tail
		if (Q.HEAD <= Q.TAIL){
			return (Q.HEAD - Q.TAIL + 1);
		}
		// saat tail < head
		else{
			return Q.MaxEl - Q.HEAD + Q.TAIL + 1;
		}
	}
}

/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q){
	return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max){
	Queue Q;
	(Q).Tab = (ElType *) malloc ((Max) * sizeof(ElType));

	if ((Q).Tab != NULL){
		(Q).MaxEl = Max;
		(Q).HEAD = NIL;
		(Q).TAIL = NIL;
	}

	else{
		(Q).MaxEl = 0;
	}

	return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
	(*Q).MaxEl = 0;
	free((*Q).Tab);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
	if (IsEmpty(*Q)){
		(*Q).HEAD = 0;
		(*Q).TAIL = 0;
	}

	else{
		if (((*Q).TAIL + 1) == (*Q).MaxEl){
			(*Q).TAIL = 0;
		}

		else{
			(*Q).TAIL++;
		}
	}

	(*Q).Tab[(*Q).TAIL] = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */

ElType Pop (Queue * Q){
	ElType x;

	x = (*Q).Tab[(*Q).TAIL];

	// tail di 0
	if ((*Q).TAIL == 0){
		// kosong setelah pop
		if (Length(*Q) == 1){
			(*Q).TAIL = NIL;
			(*Q).HEAD = NIL;
			
		}

		// tidak kosong setelah pop
		else{
			(*Q).TAIL = ((*Q).MaxEl - 1);
		}
	}

	// tail tidak di 0
	else{
		(*Q).TAIL--;
	}
	
	return x;

}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

ElType Front (Queue Q){
	ElType x;

	x = (Q).Tab[(Q).HEAD];

	// Queue hanya memiliki 1 elemen
	if (Length(Q) == 1){
		(Q).HEAD = NIL;
		(Q).TAIL = NIL;
	}

	// Queue lebih dari 1 elemen
	else{
		// Head Queue sudah mencapai batas kapasitas
		if ((Q).HEAD + 1 == (Q).MaxEl){
			(Q).HEAD = 0;
		}

		// Head Queue belum mencapai batas kapasitas
		else{ 
			(Q).HEAD++;
		}
	}
	
	return x;
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */