// Nama         : Vincent Franstyo
// NIM          : 18221100
// Tanggal      : 5/11/2022
// Topik        : implementasi ADT ListLinear
// Deskripsi    : implementasi ADT List Linear

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L){
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address p = (address) malloc (sizeof(ElmtList));
    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    } else {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address p = First(L);
    boolean found = false;
    while ((p != Nil) && (!found)){
        if (Info(p) == X){
            found = true;
        } else {
            p = Next(p);
        }
    }
    return p;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address p = Alokasi(X);
    if (p != Nil){
        Next(p) = First(*L);
        First(*L) = p;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address p, last;
    if (IsEmpty(*L)){
        InsVFirst(L,X);
    } else {
        p = Alokasi(X);
        if (p != Nil){
            last = First(*L);
            while (Next(last) != Nil){
                last = Next(last);
            }
            Next(last) = p;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address p = First(*L);
    *X = Info(p);
    First(*L) = Next(p);
    Next(p) = Nil;
    free(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address p, loc;
    p = First(*L);
    loc = Nil;
    while (Next(p) != Nil){
        loc = p;
        p = Next(p);
    }
    if (loc == Nil){
        First(*L) = Nil;
    } else {
        Next(loc) = Nil;
    }
    *X = Info(p);
    Dealokasi(&p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address last;
    if (IsEmpty(*L)){
        InsertFirst(L,P);
    } else {
        last = First(*L);
        while (Next(last) != Nil){
            last = Next(last);
        }
        Next(last) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    (*P) = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    address p, loc;
    p = Search(*L,X);
    loc = First(*L);
    if (p != Nil){
        if (NbElmt(*L) == 1){
            DelFirst(L, &p);
        } else {
            while (Next(loc) != p){
                loc = Next(loc);
            }
            DelAfter(L, &p, loc);
        }
    }
    Dealokasi(&p);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    (*P) = First(*L);
    address loc = Nil;
    while (Next(*P) != Nil){
        loc = (*P);
        (*P) = Next(*P);
    }
    if (loc == Nil){
        First(*L) = Nil;
    } else {
        Next(loc) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address p = First(L);
    if (p == Nil){
        printf("[]");
    } else {
        printf("[");
        while (p != Nil){
            printf("%d", Info(p));
            if (Next(p) != Nil){
                printf(",");
            }
            p = Next(p);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    int ctr = 0;
    address p = First(L);
    while (p != Nil){
        ctr++;
        p = Next(p);
    }
    return ctr;
}
/* Mengirimkan banyaknya elemen list{} mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    address p = First(L);
    infotype max = Info(p);
    while (p != Nil){
        if (Info(p) > max){
            max = Info(p);
        }
        p = Next(p);
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
    return Search(L, Max(L));
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
    address p = First(L);
    infotype min = Info(p);
    while (p != Nil){
        if (Info(p) < min){
            min = Info(p);
        }
        p = Next(p);
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
    return Search(L, Min(L));
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
    infotype sum = 0;
    int ctr = 0;
    address p = First(L);
    while (p != Nil){
        sum += Info(p);
        ctr++;
        p = Next(p);
    }
    float avg = (float)sum / (float)ctr;
    return avg;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address prev = Nil;
    address cur = First(*L);
    address next = Next(cur);
    while (cur != Nil){
        Next(cur) = prev;
        prev = cur;
        cur = next;
        if (next != Nil){
            next = Next(next);
        }
    }
    First(*L) = prev;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
    First(*L3) = First(*L1); 
    InsertLast(L3, First(*L2));
    First(*L1) = Nil;
    First(*L2) = Nil;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */