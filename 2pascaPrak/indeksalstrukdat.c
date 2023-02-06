#include <stdio.h>

int main(){
	int nilai = 0, count = 0, lulus = 0;
	float mean = 0, sum = 0.0;
	char index;

	while (nilai != -999){
		scanf("%d", &nilai);
		if (nilai >= 0 && nilai <= 4){
			count += 1;
			sum += nilai;

			if (nilai >= 3){
				lulus += 1;
			}
		}
	}
	mean = sum/count;

	if (mean == 4){
		index = 'A';
	}

	else if(mean >= 3 && mean < 4){
		index = 'B';
	}

	else if(mean >= 2 && mean < 3){
		index = 'C';
	}

	else if (mean >= 1 && mean < 2){
		index = 'D';
	}

	else if (mean >= 0 && mean < 1){
		index = 'E';
	}

	if (count > 0){
		printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
		printf("Nilai rata-rata = %.2f\n", mean);
		printf("Indeks akhir kelas = %c\n", index);
	}
	
	else{
		printf("Tidak ada data\n");
	}
	return 0;
}