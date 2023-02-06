// Nama 		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 3/10/2022
// Topik		: Anagram Alstrukdat
// Deskripsi	: Menghitung jumlah anagram kata alstrukdat

#include <stdio.h>
#include "mesinkarakterv2.h"
#include "mesinkata.h"
#include "anagramalstrukdat.h"

int stringLength (char* string){
	int count = 0;
	while (*string != '\0'){
		count++;
		string++;
	}
	return count;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command){
	Word kata;
	kata.Length = stringLength(command);
	int i = 0;

	while (*command != '\0'){
		kata.TabWord[i] = *command;
		command++;
		i++;
	}

	return kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2){
	boolean flag = false;
	if (string1.Length != string2.Length){
		flag = false;
	}
	else{
		int asc1 = 0, asc2 = 0;
		for (int i = 0; i < string1.Length; i++){
			asc1 += string1.TabWord[i];
			asc2 += string2.TabWord[i];
		}

		flag = (asc1 == asc2);
	}

	return flag;
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek){
	Word firstWord = toKata("alstrukdat");
	STARTWORD();

	while (!isEndWord()){
		if (isAnagram(firstWord, currentWord)){
			(*frek) ++;
		}
		ADVWORD();
	}
}