#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"

int main(){
	char inp1[101];
	char inp2[101];

	Stack s1, s2, s3, s0, s00;
	CreateEmpty(&s1);
	CreateEmpty(&s2);
	CreateEmpty(&s3);

	scanf("%s", inp1);
	scanf("%s", inp2);

	int i = 0, len1 = strlen(inp1), len2 = strlen(inp2);
	boolean isNeg = false;
	if (len1 < len2){
		isNeg = true;
	}

	else if (len1 == len2){
		while ((i < len1) && (!isNeg)){
			if ((inp1[i] - '0') < (inp2[i] - '0')){
				isNeg = true;
			}
			i++;
		}
		
	}
	while (len1 < len2){
		Push(&s1, 0);
		len1++;
	}

	while (len1 > len2){
		Push(&s2, 0);
		len2++;
	}

	int len = len1;
	i = 0;
	while (inp1[i] != '\0'){
		Push(&s1, inp1[i] - '0');
		i++;
	}

	i = 0;
	while (inp2[i] != '\0'){
		Push(&s2, inp2[i] - '0');
		i++;
	}

	s0 = s1;
	s00 = s2;
	boolean isZero = true;
	int n0, n00;

	for (i = 0; i < len; i++){
		Pop(&s0, &n0);
		Pop(&s00, &n00);
		if (n0 != n00){
			isZero = false;
		}
	}
	int n1, n2, n3;
	boolean lend = false;
	while (!IsEmpty(s1)){
		Pop(&s1, &n1);
		Pop(&s2, &n2);

		if (!isNeg){
			if (lend){
				n1 --;
				lend = false;
			}
			n3 = n1 - n2;
		}

		else{
			if (lend){
				n2--;
				lend = false;
			}
			n3 = n2 - n1;
		}

		if (n3 < 0){
			n3 += 10;
			lend = true;
		}
		Push(&s3, n3);
	}

	//insert here
	if (isNeg){
		printf("-");
	}

	if (isZero){
		printf("0");
	}
	
	else{
		boolean found = false;
		int res;
		for (int i = 0; i < len; i++){
			Pop(&s3, &res);
			if (res > 0){
				found = true;
			}

			if (res == 0){
				if (found){
					printf("%d", res);
				}
			}

			else{
				printf("%d", res);
			}
		}
	}

	printf("\n");
	return 0;
}