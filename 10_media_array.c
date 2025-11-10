/*
  Calcolare la media dei valori di un array
*/

#include<stdio.h>
#define N 5

int main(){
  int v[N];
  float somma = 0;
  float media;
  

  printf("Inserisci i numeri di cui vuoi calcolare la media: \n");

  for(int i=0;i<N;i++){
    printf("numero %d : ", i+1);
    scanf("%d", &v[i]);
    somma += v[i]; // somma = somma + v[i]
  }

  media = somma / N;
  printf("media = %f\n", media);

  return 0;
}
