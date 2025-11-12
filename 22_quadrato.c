#include<stdio.h>

int quadrato(int n){
  return n * n;
}

int main(){
  int numero = 0;
  printf("Inserisci un numero: ");
  scanf("%d", &numero);
  int risultato = quadrato(numero);
  printf("Il suo quadrato e' = %d\n", risultato);

}
