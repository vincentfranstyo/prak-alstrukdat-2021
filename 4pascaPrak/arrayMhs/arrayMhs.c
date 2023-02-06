// Nama		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 26/09/2022
// Topik		: arrayMhs
// Deskripsi	: Melakukan operasi terhadap arrayMhs

#include <stdio.h>
#include "boolean.h"
#include "arrayMhs.h"

/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMhs *T){
	(*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu p

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMhs T){
	return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Daya tampung container *** */
int MaxNbEl (TabMhs T){
	return IdxMax - IdxMin + 1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
 
IdxType GetFirstIdx (TabMhs T){
	return IdxMin;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
IdxType GetLastIdx (TabMhs T){
	return T.Neff;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
ElType GetElmt (TabMhs T, IdxType i){
	return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMhs Tin, TabMhs *Tout){
	(*Tout).Neff = Tin.Neff;
	for(int i = IdxMin; i <= Tin.Neff; i++){
    	(*Tout).TI[i] = Tin.TI[i];
	}
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

void SetEl (TabMhs *T, IdxType i, ElType v){
	(*T).TI[i] = v;
	if ((*T).Neff < i){
    	(*T).Neff = i;
	}
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

void SetNeff (TabMhs *T, IdxType N){
	(*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMhs T, IdxType i){
	return ((i >= IdxMin) && (i <= IdxMax));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

boolean IsIdxEff (TabMhs T, IdxType i){
	return ((i >= IdxMin) && (i <= T.Neff));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMhs T){
	return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Test tabel penuh *** */
boolean IsFull (TabMhs T){
	return (T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMhs T){
	if (IsEmpty(T)){
		printf("Tabel kosong\n");
	}
	else{
		int i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
			printf("%s | %s | %.2f\n",(GetElmt(T, i)).nama, (GetElmt(T, i)).nim, (GetElmt(T, i)).nilai);
		}
	}
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh print tabel
Test | 12321123 | 3.61
Ini Juga Test | 12321124 | 3.21
Test Lagi | 12321125 | 3.11
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

ElType MakeMahasiswa (char* Nama, char* NIM, float Nilai){
	ElType mhs;
	mhs.nama = Nama;
	mhs.nim = NIM;
	mhs.nilai = Nilai;
	return mhs;
}

/* Membentuk sebuah Mahasiswa dari komponen-komponennya */
/* I.S. Nama, NIM, Nilai terdefinisi */
/* F.S. Mahasiswa M terbentuk dengan Nama, NIM, Nilai yang sesuai */

/* ********** OPERATOR STATISTIK MAHASISWA ********** */
float RataRata (TabMhs T){
	float sum = 0.0, rata = 0.0;
	IdxType i;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
		sum += (GetElmt(T,i).nilai);
	}
	rata = sum / NbElmt(T);
	return rata;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rata-rata dari elemen tabel */

float Max (TabMhs T){
	float max = GetElmt(T,IdxMin).nilai;
	IdxType i;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
		if (max < (GetElmt(T,i)).nilai){
			max = GetElmt(T,i).nilai;
		}
	}
	return max;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai maksimum dari elemen tabel */

float Min (TabMhs T){
	float min = GetElmt(T,IdxMin).nilai;
	IdxType i;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
		if (min > (GetElmt(T,i)).nilai){
			min = GetElmt(T,i).nilai;
		}
	}
	return min;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai minimum dari elemen tabel */

char *MaxNama (TabMhs T){
	float max = Max(T);
	IdxType i, found = IdxMin;

	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
		if (GetElmt(T, i).nilai > max){
			max = GetElmt(T,i).nilai;
			found = i;
		}

		else if (GetElmt(T,i).nilai == max){
			if(GetElmt(T, i).nim < GetElmt(T, found).nim){
				found = i;
			}
		}
	}
	return GetElmt(T, found).nama;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai tertinggi */
/* Jika ada lebih dari satu mahasiswa dengan nilai tertinggi, maka yang diambil yang nim lebih rendah */
char *MinNama (TabMhs T){
	float min = Min(T);
	IdxType i, found = IdxMin;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
		if (GetElmt(T, i).nilai < min){
			min = GetElmt(T, i).nilai;
			found = i;
		}
		else if(GetElmt(T,i).nilai == min){
			if(GetElmt(T, i).nim > GetElmt(T, found).nim){
				found = i;
			}
		}


	}
	return(GetElmt(T, found).nama);
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai terendah */
/* Jika ada lebih dari satu mahasiswa dengan nilai terendah, maka yang diambil yang nim lebih rendah */

int JumlahJurusan (TabMhs T, char* Jurusan){
	IdxType count = 0, i, j;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
		if (GetElmt(T,i).nim[0] == Jurusan[0] && GetElmt(T, i).nim[1] == Jurusan[1] && GetElmt(T,i).nim[2] == Jurusan[2]){
			count ++;
		}
		// for (j = 0; j < 3; j++){
		// 	tiga[j] = GetElmt(T,i).nim[j];
		// }
		// if (tiga == Jurusan){
		// 	count++;
		// }
	}
	return count;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan jumlah mahasiswa yang berasal dari jurusan Jurusan, yang berbentuk 3 angka (contoh: 182) */
/* Jika tidak ada mahasiswa yang berasal dari jurusan Jurusan, maka menghasilkan 0 */
