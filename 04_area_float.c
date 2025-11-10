#include<stdio.h>

int main(){
  float base, altezza, area;
  printf("base = ");
  scanf("%f", &base);
  printf("altezza = ");
  scanf("%f", &altezza);
  area = base * altezza /2;
  printf("area = %.2f\n", area);

}
