// Nama : Vincent Franstyo
// NIM : 18221100
// Tanggal : 24 Oktober 2022
// Topik : valid
// Deskripsi : memasukkan parantheses yang valid secara berurut ke stack

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "valid.h"

Stack validParantheses(char* input, int length){
	Stack s;
	CreateEmpty(&s);

	if (length >= 2){
		int i = 0;
		while (i < length){
			if (input[i] == '(' && input[i+1] == ')'){
				Push(&s, input[i]);
				Push(&s, input[i + 1]);
			}
			if (input[i] == '[' && input[i+1] == ']'){
				Push(&s, input[i]);
				Push(&s, input[i + 1]);
			}
			if (input[i] == '{' && input[i+1] == '}'){
				Push(&s, input[i]);
				Push(&s, input[i + 1]);
			}
			i++;
		}
	}
	return s;
}

// int main(){
// 	char inp[100];
// 	Stack s;
// 	infotype val;
// 	scanf("%s", inp);
// 	printf("current string : ");
// 	for (int i = 0; i < strlen(inp); i++){
// 		printf("%c", inp[i]);
// 	}
// 	printf("\n");

// 	int length = strlen(inp);
// 	s = validParantheses(inp, length);

// 	// printf("stack : ");
// 	while (!IsEmpty(s)){
// 		// printf("infotop : %c\n", InfoTop(s));
// 		Pop(&s, &val);
// 		printf("%c", val);
// 	}
// 	printf("\n");
// 	return 0;
// }