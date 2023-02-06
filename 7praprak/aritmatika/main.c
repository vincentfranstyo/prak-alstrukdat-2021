#include <stdio.h>
#include <string.h>

#include "aritmatika.h"

int main(){
	char string[100];
	char *s=string;

	scanf("%s", s);
	// printf("%s", string);
	// printf("%d", isOperator('^'));
	int len = strlen(s);
	// printf("%d\n", len);
	// printf("%s\n", string);
	printf("%d", eval(s, len));
	return 0;
}