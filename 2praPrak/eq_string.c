#include <stdio.h>
#include <string.h>

int main(){
	char s1[100] = "", s2[100] = "";

	scanf("%s", s1);
	scanf("%s", s2);

	int i, result;
	for(i = 0; i < strlen(s1); i++){
		if (s1[i] >= 'A' && s1[i] <= 'Z'){
			s1[i] += 32;
		}
	}
	for(i = 0; i < strlen(s2); i++){
		if (s2[i] >= 'A' && s2[i] <= 'Z'){
			s2[i] += 32;
		}
	}

	if (strcmp(s1,s2) == 0){
		printf("Ya\n");
	}
	else{
		printf("Tidak\n");
	}
	
	return 0;	
}