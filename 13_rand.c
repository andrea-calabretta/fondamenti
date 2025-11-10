/*
  creare un array di numeri casuali (random) da 0 a 100
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 6

int main(){
  int a[N];
  int i;
  int max = 300;
  int min = 100;
  srand(time(NULL));

  printf("------ valori nello stack -----\n");
  for(i=0; i<N; i++){
    printf("a[%d] = %d\n", i, a[i]);
  }


  printf("------ valori random----\n");
  for(i=0; i<N; i++){
    a[i]=rand()%(max-min+1)+min;
    printf("a[%d] = %d\n", i, a[i]);
  }
}

