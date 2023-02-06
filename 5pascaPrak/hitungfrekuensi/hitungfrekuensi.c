// Nama 		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 3/10/2022
// Topik		: Hitung Frekuensi
// Deskripsi	: Menghitung frekuensi kemunculan angka tiga

#include <stdio.h>

#include "mesinkarakter.h"
#include "hitungfrekuensi.h"
#include "boolean.h"

int hitungfrekuensi(){
	// Menghitung frekuensi kemunculan kata tiga dalam uppercase atau lowercase
	int count = 0;
	START();
	while (!IsEOP()){
		int tfound = 0, ifound = 0, gfound = 0, afound = 0;
		if (GetCC() == 't' || GetCC() == 'T'){
			tfound = 1;
			ADV();

			if ((!IsEOP()) && (tfound == 1) && (GetCC() == 'i' || GetCC() == 'I')){
				ifound = 1;
				ADV();

				if ((!IsEOP()) && (ifound == 1) && (GetCC() == 'g' || GetCC() == 'G')){
					gfound = 1;
					ADV();

					if ((!IsEOP()) && (gfound == 1) && (GetCC() == 'a' || GetCC() == 'A')){
						afound = 1;
						count ++;
					}
				}
			}
		}
		ADV();
	}
	return count;
}