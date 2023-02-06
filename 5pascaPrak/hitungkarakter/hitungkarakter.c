#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;

int hitungkarakter (char karakter){
	START(pita);
	int count = 0;
	while (!IsEOP(pita)){
		if (GetCC(pita) == karakter){
			count++;
		}
		ADV(pita);		
	}
	return count;
}