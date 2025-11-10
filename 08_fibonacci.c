#include<stdio.h>
#define DIM 100

int main(){
  
  long long v[DIM];
  v[0] = 1;
  v[1] = 2;
  int i;

  for (i = 2; i<DIM ; i++){
    v[i] = v[i-1]+v[i-2];
  }
  for(i=0; i<DIM; i++){
    printf("v[%d] = %lld\n", i, v[i]); 
  }
  return 0;
}
