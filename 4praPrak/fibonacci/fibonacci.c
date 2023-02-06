#include <stdio.h>
#include "fibonacci.h"

// Deret bilangan fibonacci adalah deret angka yang susunan angkanya
// merupakan penjumlahan dari dua angka sebelumnya.
// Contoh:
// Fib 0: 1
// Fib 1: 1
// Fib 2: 1 + 1 = 2
// Fib 3: 2 + 1 = 3
// Fib 4: 3 + 2 = 5
// Fib 5: 5 + 3 = 8

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result){
	int i, x = 1, y = 1, z = 0;
	if (n == 0 || n == 1){
		*result = 1;
	}
	else{
		for (i = 2; i <= n; i++){
			z = x + y;
			x = y;
			y = z;
		}
		*result = y;
	}
	
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
	if (n == 0 || n == 1){
		return 1;
	}
	else{
		int i, x = 1, y = 1, z = 0;
		for (i = 2; i <= n; i ++){
			z = x + y;
			x = y;
			y = z;
		}
		return y;
	}
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result){
	int i;
	result[n];
	result[0] = 1;
	result[1] = 1;
	if (n >= 2){
		for (i = 2; i <= n; i++){
			result[i] = result[i - 1] + result[i - 2];
		}
	}
}