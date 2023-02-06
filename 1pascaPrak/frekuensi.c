#include <stdio.h>
#include <string.h>

int main(){
	char str[10] = "";
	int arr[10] = {0};
	int x = 0;
	scanf("%s", str);
	int i;
	for(i = 0; i < strlen(str); i++){
		x = str[i] - 48;
		// for (int j = 0; j < 10; j++){
		// 	if (str)
		// }
		switch(x){
			case 0: arr[0]++;
			break;

			case 1: arr[1]++;
			break;

			case 2: arr[2]++;
			break;

			case 3: arr[3]++;
			break;

			case 4: arr[4]++;
			break;

			case 5: arr[5]++;
			break;

			case 6: arr[6]++;
			break;

			case 7: arr[7]++;
			break;

			case 8: arr[8]++;
			break;

			case 9: arr[9]++;
			break;
		}
	}
	for(i = 0; i < 10; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
	// printf("%s", str);
	return 0;
}