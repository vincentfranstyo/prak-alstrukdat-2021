#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int i, j;
	int arr[n];
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	int q;
	scanf("%d", &q);

	int query[q], totalSum[q];
	for (i = 0; i < q; i++){
		int firstIdx = 0, lastIdx = 0, sum = 0, sumIdx;
		scanf("%d %d", &firstIdx, &lastIdx);

		for (j = firstIdx; j <= lastIdx; j++){
			if ((j > n) && (j % n != 0)){
				sumIdx = j % n;
				// printf("indeks now = %d\n", sumIdx);
			}
			else if (j % n == 0){
				sumIdx = n;
				// printf("indeks now = %d\n", sumIdx);
			}
			else{
				sumIdx = j;
			}
			// printf("indeks sekarang = %d\n", sumIdx);
			sum += arr[sumIdx - 1];
			// printf("%d\n", sum);

		}
		totalSum[i] = sum;

	}

	for (i = 0; i < q; i++){
		printf("%d\n", totalSum[i]);
	}
	return 0;

}