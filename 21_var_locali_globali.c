#include<stdio.h>

int incrementa(int n){
  n = n+1;
  printf("Il nuovo valore di n e': %d\n", n);
  return n;
}



int main(){
  int k = 0;
  printf("Inserisci un numero : ");
  scanf("%d", &k);
  k = incrementa(k);
  printf("il valore di a e' %d\n", k);
}
