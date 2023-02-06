#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    // Masukkan kode program disini
    infotype arr[el];
    int i = 0;
    int n = 0;
    if (el >= 2){
        n = 2;
    }

    else{
        n = el;
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if (el == 0) {
        // Masukkan kode program disini
        
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        // Masukkan kode program disini
        InsVLast(&fibonacci, arr[0]);

        PrintInfo(fibonacci);
        return 0;
    } else {
        // Masukkan kode program disini
        for (int i = 2; i < el; i++){
            arr[i] = arr[i-1] + arr[i - 2];
        }

        for (int i = 0; i < el; i++){
            InsVLast(&fibonacci, arr[i]);
        }

        PrintInfo(fibonacci);
    }

    return 0;
}