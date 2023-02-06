// Nama 		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 3/10/2022
// Topik		: Cipher
// Deskripsi	: Menghitung banyak pergeseran antara 2 string

#include <stdio.h>

#include "mesinkarakterv2.h"
#include "mesinkata.h"

char encrypt(char charNow, int shift){
	if (charNow + shift > 'Z'){
		return (charNow + shift - 'A') % 26 + 'A';
	}
	else{
		return charNow + shift;
	}
}

int main(){
	STARTWORD();

	int shiftAmt = currentWord.Length;

	while (!isEndWord()){
		for(int i = 0; i < currentWord.Length; i++){
			printf("%c", encrypt(currentWord.TabWord[i], shiftAmt));
		}

		if (EOP){
			printf(".");
		}

		else{
			printf(" ");
		}

		ADVWORD();
	}
	printf("\n");

	return 0;
}