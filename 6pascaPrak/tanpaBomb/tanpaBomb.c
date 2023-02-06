// Nama 		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 17 Oktober 2022
// Topik 		: tanpa Bomb
// Deskripsi	: mengembalikan Queueu yang tidak memiliki bomb

#include <stdio.h>
#include "queue.h"

Queue tanpaBomb(Queue queue, ElType bomb){
	Queue q2;
	CreateQueue(&q2);
	int i = IDX_HEAD(queue);
	int found = 0;
	ElType temp;
	while (i != IDX_TAIL(queue)){
		if (HEAD(queue) == bomb){
			found = 1;
			temp = bomb;
		} 
		i = (i + 1) % CAPACITY;
	}

	while (!isEmpty(queue)){
		ElType val;
		ElType bom;
		if (HEAD(queue) != bomb){
			dequeue(&queue, &val);
			enqueue(&q2, val);
		}
		dequeue(&queue, &bom);
	}

	return q2;
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/