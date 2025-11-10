/*
fare uno switch case che stampa i giorni della settimana in base al carattere inserito
*/

#include<stdio.h>

int main(){
  char giorno;
  printf("Inserire una lettera che rappresenta il giorno della settimana: ");
  giorno = getchar(); //scanf("%c", &giorno);
  switch(giorno){
    case 'l':
      printf("Lunedì\n");
      break;
    case 'm':
      printf("Martedì\n");
      break;
    case 'M':
      printf("Mercoledì\n");
      break;
    case 'g':
      printf("Giovedì\n");
      break;
    case 'v':
      printf("Venerdì\n");
      break;
    case 's':
      printf("Sabato\n");
      break;
    case 'd':
      printf("Domenica\n");
      break;
    default:
      printf("carattere non valido\n");
  }
}
