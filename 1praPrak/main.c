#include <stdio.h>

int main(){
	int time = 0, h = 0, m = 0, origin = 0;
	scanf("%d", &time);
	origin = time;
	h = time / 3600;
	time %= 3600;
	m = time / 60;
	time %= 60;
	printf("%d detik = %d jam %d menit %d detik\n", origin, h, m, time);
	return 0;
}