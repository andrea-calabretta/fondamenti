/*
Creare un array di struct di Lavoratori con campi:
- nome
- cognome
- stipendio

e calcolare la media degli stipendi, il minimo e il massimo

*/

#include<stdio.h>
#include<string.h>
#define DIM 30
#define FFLUSH  while (getchar()!='\n');
#define NUM_LAVORATORI 5

void leggiStringa(char str[], int dim) {
    fgets(str, dim, stdin);
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    else
        while (getchar()!='\n');
}

struct Lavoratore{
  char nome[DIM];
  char cognome[DIM];
  int stipendio;
};

int main(){
  struct Lavoratore lavoratori[5];
  int i;
  float media = 0;
  int somma_stipendi = 0;
  for(i=0; i<NUM_LAVORATORI; i++){
    printf("\n\n---Lavoratore n° %d ---\n", i);
    printf("Nome : ");
    leggiStringa(lavoratori[i].nome, DIM);
    printf("Cognome : ");
    leggiStringa(lavoratori[i].cognome, DIM);
    printf("Stipendio : ");
    scanf("%d", &lavoratori[i].stipendio);
    FFLUSH
  }

  int min = lavoratori[0].stipendio;
  int max = lavoratori[0].stipendio;

  for(i=0; i<NUM_LAVORATORI;i++){
    if(lavoratori[i].stipendio>max)
      max = lavoratori[i].stipendio;
    if(lavoratori[i].stipendio<min)
      min = lavoratori[i].stipendio;
    somma_stipendi += lavoratori[i].stipendio;
  }

  media = (float) somma_stipendi/NUM_LAVORATORI;
  printf("Stipendio minimo = %d\n", min);
  printf("Stipendio massimo = %d\n", max);
  printf("Stipendio medio = %.2f\n", media);
  
}
