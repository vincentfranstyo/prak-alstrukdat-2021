#include <stdio.h>
#include "panjangstring.h"

int panjangString (char * inp){
	int count = 0;
	while (*inp != '\0'){
		count ++;
		*inp ++;
	}
	return count;
}