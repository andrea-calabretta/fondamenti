#include<stdio.h>

float media(float n1, float n2){
  float m = (float)(n1+n2)/2;
  return m;

}

int main(){
  float a, b;
  printf("----Calcolo media tra due numeri-----\n");
  printf("Inserisci il 1° numero : ");
  scanf("%f", &a);
  printf("Inserisci il 2° numero : ");
  scanf("%f", &b);
  float risultato = media(a,b);
  printf("La media e' = %.2f\n", risultato);
}
