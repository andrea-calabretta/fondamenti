#include<stdio.h>

#define DIM 8

int main(){
  int a[]={1,1,2,2,3,4,9,3};
  int b[]={0,0,0,0,0,0,0,0};
  int i,j;
  int k=0;
  int isPresent = 0;
  printf("--- [ 1° vettore ] ---\n");
  for(i=0; i<DIM; i++){
    printf("a[%d] = %d\n",i, a[i]);
  }


  for(i=0; i<DIM; i++){
    isPresent = 0;
    for(j=0; j<DIM; j++){
      if(a[i]==b[j]){
        isPresent = 1;
        break;
        //se incontro un duplicato me lo segno nel FLAG isPresent
      }

    }
    if(!isPresent){//se non è presente lo inserisco nel nuovo array
      b[k]=a[i];
      k++;
    }
    
  }

  printf("--- [ 2° vettore senza duplicati ] ---\n");
  for(i=0; i<DIM; i++){
    printf("b[%d] = %d\n",i, b[i]);
  }
}
