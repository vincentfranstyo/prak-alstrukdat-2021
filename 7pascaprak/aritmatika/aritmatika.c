#include <stdio.h>
#include "stack.h"
#include "aritmatika.h"

boolean isOperator(char input){
	return (input == '+' || input == '-' || input == '*' || input == '/');
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op){
	int res;
	if (op == '+'){
		res = angka1 + angka2;
	}

	else if (op == '-'){
		res = angka1 - angka2;
	}

	else if (op == '*'){
		res = angka1 * angka2;
	}

	else if (op == '/'){
		res = angka1 / angka2;
	}

	return res;
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length){
	Stack s;
	CreateEmpty(&s);
	int i = 0, x = 0, y = 0, res = 0;

	while (i < length){
		if (!isOperator(input[i])){
			input[i] -= '0';
			// printf("oprand: %c\n", input[i]);
			Push(&s, input[i]);
		}
		
		else{
			Pop(&s, &y);
			Pop(&s, &x);
			// printf("oprator : %c\n", input[i]);
			// printf("angka 1: %d\n", x);
			// printf("angka 2: %d\n", y);
			res = hitung(x, y, input[i]);
			// printf("res : %d\n", res);
			Push(&s, res);
		}

		i++;
	}

	// Pop(&s, &res);
	return res;
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/