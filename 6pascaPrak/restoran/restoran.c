#include <stdio.h>
#include "queue.h"
#include "boolean.h"

int main(){
	int n = 999;
	Queue food;
	boolean first = true;
	CreateQueue(&food);
	
	int mintime = 0, count = 0, counttime = 0, maxtime = 0, extime = 0;
	while(n != 0){
		scanf("%d", &n);
		int time = 0;
		if (n == 1){
			scanf("%d", &time);
			if (time > 0){
				enqueue(&food, time);
			}
			// displayQueue(food);
		}

		if (n == 2){
			if (!isEmpty(food)){
				dequeue(&food, &extime);
				if (first){
					// printf("first1 : %d\n", first);
					mintime = extime;
					first = false;
				}
				// displayQueue(food);
				// printf("first2 : %d\n", first);
				if(mintime > extime){
					mintime = extime;
				}

				if(maxtime < extime){
					maxtime = extime;
				}
				// printf("mintime : %d\n", mintime);
				// printf("maxtime : %d\n", maxtime);
				count++;
			}
		}
	}

	// printf("0\n0\n0\n");
	printf("%d\n%d\n%d\n", count, mintime, maxtime);
	return 0;
}