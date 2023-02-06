/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
  /* Tuliskan implementasi di sini */
  address p = First(L);
  int count = 0;
  while (count != r){
    p = Next(p);
    count ++;
  }
  return Info(p);

}

int main () {
  List L;
  CreateEmpty(&L);
  int r;
  /* Tuliskan implementasi di sini */
  int n;
  scanf("%d", &n);
  while (n != 0){
    InsVLast(&L, n);
    scanf("%d", &n);
  }

  scanf("%d", &r);

  if (IsEmpty(L)){
    printf("List Kosong\n");
  }

  else{
    printf("%d\n", ElemenKeN(L, r));
  }
  return 0;
}