#include <stdio.h>

int main(){
  int i; //dichiaro la variabile i
  int somma = 0; //inizializzo la variabile somma
  printf("somma all'inizio -> %d\n", somma);
  for(i=0; i<=100; i++){
    somma += i; //accumulo la somma dei numeri dentro la variabile somma
    printf("Ciclo %d - somma = %d\n", i, somma);
  }
}
