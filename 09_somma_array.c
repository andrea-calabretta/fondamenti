/*
Dato un array di n elementi, calcolare la loro somma e stamparla
*/

#include<stdio.h>
#define N 5



int main(){
  int array[N]={7,5,4,10,12};
  int somma = 0;
  int i;

  printf ("--------Stampo il vettore-------\n");
  for(i=0; i<N ; i++){
    printf("a[%d] = %d\n", i, array[i]);
  }


  printf ("--------Calcolo la somma-------\n"); 
  for(i=0; i<N; i++){
    
    somma = somma + array[i];
    printf("ciclo %d - somma attuale = %d\n", i, somma);
  }


  printf("\n\n -----------------\n");
  printf("somma = %d\n", somma);
  return 0;
}
