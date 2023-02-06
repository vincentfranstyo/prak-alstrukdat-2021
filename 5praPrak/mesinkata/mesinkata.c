#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakterv2.h"


boolean EndWord = false;
Word currentWord;

void IgnoreBlanks(){
	while ((currentChar == BLANK) && (currentChar != MARK)){
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
	START();
	IgnoreBlanks();

	if (currentChar == MARK){
		EndWord = true;
	}

	else {
		EndWord = false;
		CopyWord();
	}

}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
	IgnoreBlanks();
	if (currentChar == MARK){
		EndWord = true;
	}

	else{
		EndWord = false;
		CopyWord();
	}
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
	// typedef struct
	// {
 //   		char TabWord[NMax];  container penyimpan kata, indeks yang dipakai [0..NMax-1] 
 //   		int Length;
	// } Word;
	int i = 0;
	while ((currentChar != MARK) && (currentChar != BLANK)){

		if (i < NMax){
			currentWord.TabWord[i] = currentChar;
			i++;
		}

		ADV();
	}
	currentWord.Length = i;
	IgnoreBlanks();
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
