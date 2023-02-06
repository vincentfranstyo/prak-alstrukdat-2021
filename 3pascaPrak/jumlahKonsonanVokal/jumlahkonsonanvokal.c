#include <stdio.h>
#include "jumlahkonsonanvokal.h"


int isAlphabet(char alph){
	if ((alph >= 'A' && alph <= 'Z') || (alph >= 'a' && alph <= 'z')){
		return 1;
	}
	return 0;
}

int isVowel (char alph){
	if (alph == 'A' || alph == 'E' || alph == 'I' || alph == 'O' || alph == 'U' || alph == 'a' || alph == 'e' || alph == 'i' || alph == 'o' || alph == 'u'){
		return 1;
	}
	return 0;
}

// Parameter pertama merupakan kalimat
// Parameter kedua merupakan jumlah huruf konsonan
// Parameter ketiga merupakan jumlah huruf vokal
void jumlahKonsonanVokal(char* word, int* countCons, int* countVocal){
	int i = 0;
	while (*(word + i) != '\0'){
		if (isAlphabet(*(word + i)) == 1){
			if (isVowel(*(word + i)) == 1){
				(*countVocal) ++;
			}
			else{
				(*countCons) ++;
			}
		}
		i++;
	}
}