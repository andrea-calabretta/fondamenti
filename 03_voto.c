#include <stdio.h>

int main(){
  int voto;
  printf("Inserisci il voto : ");
  scanf("%d", &voto);
  if(voto >= 6){
    printf("promosso \n");
  }else{
    printf("bocciato \n");
  }
}
