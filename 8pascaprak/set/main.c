#include <stdio.h>
#include <stdlib.h>

#include "./set.h"

int main(){

	// char *command = (char *) malloc (5 * (sizeof(char)));

	// scanf("%s", command);

	// if (command == "COOK"){
	// 	printf("%s", command);
	// }

	Set s1, s2;
	CreateEmpty(&s1);
	CreateEmpty(&s2);

	// printf("full : %d\n", IsFull(s1));

	for (int i = 0; i < 3; i++){
		Insert(&s1, i);
	}


	for (int i = 1; i < 5; i++){
		Insert(&s2, i);
	}

	for (int i = 0; i < s1.Count; i++){
		printf("s1[%d] : %d\n", i + 1, s1.Elements[i]);
	}
	printf("\n");

	for (int i = 0; i < s2.Count; i++){
		printf("s2[%d] : %d\n", i + 1, s2.Elements[i]);
	}
	printf("\n");

	// printf("full : %d\n", IsFull(s1));
	// printf("empty : %d\n", IsEmpty(s1));
	
	// int length1 = s1.Count;
	// for (int i = 0; i < length1; i ++){
	// 	Delete(&s1, i);
	// }

	Set s3 = SetSubtract(s1, s2);

	
	// printf("count : %d\n", s1.Count);
	printf("\n");
	for (int i = 0; i < s3.Count; i++){
		printf("s3[%d] : %d\n", i + 1, s3.Elements[i]);
	}

	// printf("empty : %d\n", IsEmpty(s1));

	return 0;
}