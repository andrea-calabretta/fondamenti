#include<stdio.h>
#include<string.h>
#define DIM 20

void leggiStringa (char str[], int dim) {
    fgets(str, dim, stdin);
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    else
        while (getchar()!='\n');
}

int main(){
  char username[DIM];
  
  printf("username : ");
  leggiStringa(username, DIM);

  printf("username = %s\n", username);
  printf("lunghezza username = %lu\n", strlen(username));
  return 0;
}
