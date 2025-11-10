/*
Dato un array di interi, contiamo quanti numeri sono pari e quanti sono dispari
*/

#include<stdio.h>
#define N 6

int main(){
  int a[N];
  int i;
  int cnt_pari = 0;
  int cnt_dispari = 0;
  printf("vedo quali numeri sono memorizzati nelle celle di memoria dello stack\n");
  for(i = 0; i<N; i++){
    printf("a[%d] = %d\n", i, a[i]);
  }

  printf("inizializzo /sovrascrivo quelle celle con dei valori miei\n");


  for(i = 0; i<N; i++){
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
  }
  
  for (i=0; i<N; i++){
    if(a[i]%2==0){
      cnt_pari++; //cnt_pari = cnt_pari +1; cnt_pari += 1
    }else{
      cnt_dispari++;
    }
  }

  printf("I numeri pari sono %d \n", cnt_pari);
  printf("I numeri dispari sono %d \n", cnt_dispari);

  
  return 0;
}
