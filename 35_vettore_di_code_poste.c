#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S 100
#define N 4

typedef struct{
	char cognome[S], nome[S], servizio[S];
}tipobaseQueue;

typedef short boolean;

struct nodoQueue{
	tipobaseQueue info;
	struct nodoQueue *next;
};

typedef struct{
	struct nodoQueue *front, *rear;
}queue;

#define CODAVUOTA NULL

void MakeNullQueue(queue *q){
	q->front=q->rear=CODAVUOTA;
}

boolean EmptyQueue(queue q){
	return(q.front==CODAVUOTA);
}

boolean FullQueue(queue q){
	struct nodoQueue *tmp;
	tmp=(struct nodoQueue *)malloc(sizeof(struct nodoQueue));
	if (!tmp) return 1; //non c'è spazio
	else {
		free(tmp);
		return 0;
	}
}

void EnQueue(queue *q, tipobaseQueue x){
	struct nodoQueue * tmp;
	if (!FullQueue(*q)) {
		tmp=(struct nodoQueue *)malloc(sizeof(struct nodoQueue));
		tmp->info=x;
		tmp->next=CODAVUOTA;
		if (EmptyQueue(*q)) q->front=q->rear=tmp;
		else {
			q->rear->next=tmp;
			q->rear=tmp;
		}
	}
}

void DeQueue(queue *q){
	struct nodoQueue *tmp;
	if (!EmptyQueue(*q)) {
		tmp=q->front->next;
		free(q->front);
		q->front=tmp;
		if (q->front==CODAVUOTA) q->rear=CODAVUOTA;
	}
}

tipobaseQueue Front(queue q){
	if (!EmptyQueue(q)) {
		return(q.front->info);
	}
}

#define FFLUSH while(getchar()!='\n')

void LeggiStringa(char s[], unsigned long dim){
	unsigned long i;
	for (i=0; (s[i]=getchar())!='\n' && i<dim-1; i++);
		s[i]='\0';
		if (i==dim-1)  FFLUSH;
}

void LeggiElementoQueue(tipobaseQueue *x){
	printf("\nInserisci il Cognome ");
	LeggiStringa(x->cognome, S);
	printf("Inserisci il Nome ");
	LeggiStringa(x->nome, S);
	printf("Inserisci la Descrizione del Servizio ");
	LeggiStringa(x->servizio, S);	
}

void VisualizzaElementoQueue(tipobaseQueue x){
	printf("\nCognome = %s", x.cognome);
	printf("\nNome = %s", x.nome);
	printf("\nServizio richiesto = %s", x.servizio);
}
queue archivio[N];

int main(){
	int i,s,indice;
	tipobaseQueue elem;
	
	for (i=0; i<N ; i++) 
		MakeNullQueue(&archivio[i]);
	
	do {
		printf("\n\nMenu di Operazioni ");
		printf("\n1-Inserimento in coda");
		printf("\n2-Visualizzazione ed Estrazione ");
		printf("\n3-Fine");
		printf("\nInserisci la scelta ");
		scanf("%d", &s);
		FFLUSH;
	switch (s) {
		case 1:do{
			printf("\nIn quale sportello vuoi metterti in coda?\n");
			printf("\n0-Invio Pacchi");
			printf("\n1-Creazione SPID");
			printf("\n2-Ritiro Pensione");
			printf("\n3-Emissione Bonifico");
			printf("\nInserisci la scelta: ");
			scanf("%d", &indice);
			FFLUSH;
		}while (indice>3);
			if (!FullQueue(archivio[indice])) {
				printf("\nInserisci Cliente");
				LeggiElementoQueue(&elem);
					EnQueue(&archivio[indice], elem);
			}else printf("\nCoda Piena \n");
			break;
		case 2: do{
			printf("\nQuale sportello vuoi servire?\n");
			printf("\n0-Invio Pacchi");
			printf("\n1-Creazione SPID");
			printf("\n2-Ritiro Pensione");
			printf("\n3-Emissione Bonifico");
			printf("\nInserisci la scelta: ");
			scanf("%d", &indice);
			FFLUSH;
		}while (indice>3);
			if (EmptyQueue(archivio[indice]))
				printf("\nCoda Vuota\n");
			else {
				elem=Front(archivio[indice]);
				DeQueue(&archivio[indice]);
				printf("\nPrimo Elemento Estratto\n");
				VisualizzaElementoQueue(elem);
			}
			break;
	}
	} while (s<3);
}



