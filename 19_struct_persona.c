#include<stdio.h>
#include<string.h>

#define DIM 30

void leggiStringa (char str[], int dim) {
    fgets(str, dim, stdin);
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    else
        while (getchar()!='\n');
}
 
struct Persona{
  char nome[DIM];
  char cognome[DIM];
  int eta;
};

int main(){
  struct Persona p;
  printf("Inserisci nome : ");
  leggiStringa(p.nome, DIM);
  printf("Inserisci cognome : ");
  leggiStringa(p.cognome, DIM);
  printf("Inserisci eta' : ");
  scanf("%d", &p.eta);

  printf("\n\n---- stampo i valori inseriti: ----\n");
  printf("Nome = %s\n", p.nome);
  printf("Cognome = %s\n", p.cognome);
  printf("Eta' = %d \n", p.eta);
}
