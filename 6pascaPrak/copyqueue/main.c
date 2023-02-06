#include <stdio.h>
#include "copyqueue.h"

int main(){
	Queue queueInput, queueOutput;
	CreateQueue(&queueInput);
	CreateQueue(&queueOutput);
	int i;
	for (i = 0; i <= 5; i++){
		enqueue(&queueInput, i);
	}
	// Queue qtemp;
	// CreateQueue(&qtemp);
	// int len = length(queueInput);
	// while (len != 0){
	// 	ElType val;
	// 	dequeue(&queueInput, &val);
	// 	enqueue(&qtemp, val);
	// 	len--;
	// }
	// Queue qtemp = queueInput;
	copyQueue(&queueInput, &queueOutput);
	displayQueue(queueInput);
	// displayQueue(qtemp);
	displayQueue(queueOutput);
	return 0;
}