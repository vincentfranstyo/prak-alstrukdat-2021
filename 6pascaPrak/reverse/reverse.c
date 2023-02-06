#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2){
	ElType x;
	int length = Length(*q1);

	while (length > 0){
		if (length == 1){
			x = Pop(q1);
			Push(q2, x);
			length--;
		}
		
		// length > 1
		else{
			int i = 0;
			while (i < length - 1){
				x = Pop(q1);	
				Push(q1	, x);
				i++;
			}
			x = Pop(q1);
			Push(q2, x);
			length--;
		}
	}
}

// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik


// [1,2,3,4,5]
// [5,4,3,2,1] -> [5,1,2,3,4] -> q2[5]
// [1,2,3,4] -> [4,1,2,3] -> q2[5,4]



// [1,2,3,4,5] -> [5,4,3,2,1] ??? TLE??
