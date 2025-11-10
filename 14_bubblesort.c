/*
ordiniamo un array di numeri casuali (random) da 0 a 100
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 6




int main(){
  int a[N];
  int i, tmp;
  int max = 300;
  int min = 100;
  srand(time(NULL));


  printf("------ valori random----\n");
  for(i=0; i<N; i++){
    a[i]=rand()%(max-min+1)+min;
    printf("a[%d] = %d\n", i, a[i]);
  }
  for(int i = 0; i< N-1; i++){
    for(int j=0; j< N-1; j++){
      // se l'elemento attuale è maggiore del successivo, scambiali
      if(a[j]>a[j+1]){
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
  

  printf("-----Array ordinato: ---- \n");
  for(int i=0; i<N; i++){
    printf("a[%d] = %d\n", i, a[i]);
  }




}

