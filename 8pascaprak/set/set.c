// Nama 		: Vincent Franstyo	
// NIM 		: 18221100
// Tanggal 	: 31/10/2022
// Topik 		: Set
// Deskripsi 	: Implementasi ADT Set dengan fungsi tambahan

#include <stdio.h>
#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
	(*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
	return (S).Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
	return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
	if (!IsMember(*S, Elmt)){
		(*S).Count++;
		(*S).Elements[(*S).Count - 1] = Elmt;
	}
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
	if (IsMember(*S, Elmt)){
		int i = 0;
		while (i < (*S).Count && (*S).Elements[i] != Elmt){
			i++;
		}

		for (int j = i + 1; j < (*S).Count; j++){
			(*S).Elements[j - 1] = (*S).Elements[j];
		}
		(*S).Count--;
	}
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
	int i = 0;
	boolean found = false;
	while (i < S.Count && !found){
		if (S.Elements[i] == Elmt){
			found = true;
		}
		i++;
	}

	return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2){
	Set s3;
	CreateEmpty(&s3);
	for (int i = 0; i < s1.Count; i++){
		Insert(&s3, s1.Elements[i]);
	}

	for (int i = 0; i < s2.Count; i++){
		Insert(&s3, s2.Elements[i]);
	}
	return s3;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2){
	Set s;
	CreateEmpty(&s);
	for (int i = 0; i < s1.Count; i++){
		if (IsMember(s2, s1.Elements[i])){
			Insert(&s, s1.Elements[i]);
		}
	}
	return s;
}
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2){
	Set s;
	CreateEmpty(&s);

	for (int i = 0; i <s1.Count; i++){
		if (!IsMember(s2, s1.Elements[i])){
			Insert(&s, s1.Elements[i]);
		}
	}
	
	for (int i = 0; i < s2.Count; i ++){
		if (!IsMember(s1, s2.Elements[i])){
			Insert(&s, s2.Elements[i]);
		}
	}

	return s;
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2){
	Set s;
	CreateEmpty(&s);

	for (int i = 0; i <s1.Count; i++){
		if (!IsMember(s2, s1.Elements[i])){
			Insert(&s, s1.Elements[i]);
		}
	}

	return s;
}
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]

