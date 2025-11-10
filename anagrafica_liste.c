/* Scrivere un programma in c che permetta la gestione
 * dell'anagrafica tramite una lista a puntatori i cui
 * elementi sono strutture.
 * 
 * La struttura comprende:
 * - Una stringa nome
 * - Una stringa cognome
 * - Un intero eta
 * - Una stringa indirizzo
 * 
 * Il programma prevede:
 * 1. Una funzione inserimento in testa che permette
 *    l'inserimento di un elemento in testa alla lista.
 * 2. Una funzione visualizza anagrafica che mostra
 *    tutti gli elementi
 * 3. Una funzione elimina che dati nome e cognome
 *    elimini l'elemento dalla lista
 * 4. Una funzione ricerca che permetta di visualizzare
 *    un elemento cercato tramite nome e cognome.
 * 5. Una funzione età media che permetta di calcolare
 *    l'età media di tutti gli elementi
 * 6. Una funzione salva lista, che salvi su file in formato
 *    testuale tutti gli elementi presenti in anagrafica
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMEDIM 30
#define INDDIM 50
#define NOMEFILE "dati_anagrafica.txt"

struct persona {
    char nome[NOMEDIM];
    char cognome[NOMEDIM];
    int eta;
    char ind[INDDIM];
};

struct elemento {
    struct persona info;
    struct elemento *next;
};

struct elemento * inserisci(struct elemento *testa);
void visualizza_elemento(struct persona ele);
void visualizza(struct elemento *testa);
struct elemento * elimina(struct elemento *testa);
struct elemento * ricerca(struct elemento *testa);
void eta_media(struct elemento *testa);
void salva(struct elemento *testa);

int main() {
    int scelta;
    struct elemento *testa = NULL, *paus;
    
    do {
        printf("\n\n1. Inserisci\n2. Visualizza\n3. Elimina\n");
        printf("4. Ricerca\n5. Eta' media\n6. Salva\n0. Esci\n");
        printf("Scegli operazione: ");
        scanf("%d%*c", &scelta);
        
        switch(scelta) {
            case 1:
                testa = inserisci(testa);
                break;
            case 2:
                visualizza(testa);
                break;
            case 3:
                testa = elimina(testa);
                break;
            case 4:
                paus = ricerca(testa);
                if(paus == NULL) {
                    printf("Elemento non trovato!\n");
                } else {
                    visualizza_elemento(paus->info);
                }
                break;
            case 5:
                eta_media(testa);
                break;
            case 6:
                salva(testa);
                break;
            case 0:
                break;
            default:
                printf("Operazione non consentita!\n");
                break;
        }
    } while(scelta != 0);
}

void salva(struct elemento *testa) {
    FILE *pf;
    
    pf = fopen(NOMEFILE, "w");
    if(pf == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    
    while(testa != NULL) {
        fprintf(pf, "Nome e cognome: %s %s\n", testa->info.nome, testa->info.cognome);
        fprintf(pf, "Eta': %d\nIndirizzo: %s\n", testa->info.eta, testa->info.ind);
        fprintf(pf, "-----------------------------------\n");
        testa = testa->next;
    }
    
    fclose(pf);
}

void eta_media(struct elemento *testa) {
    double conta = 0, somma = 0;
    
    while(testa != NULL) {
        conta++;
        somma = somma + testa->info.eta;
        testa = testa->next;
    }
    
    printf("Eta' media: %.2lf\n", somma/conta);
}

struct elemento * ricerca(struct elemento *testa) {
    struct elemento *paus;
    char nome[NOMEDIM], cognome[NOMEDIM];
    
    printf("Inserisci nome: ");
    fgets(nome, NOMEDIM, stdin);
    nome[strlen(nome)-1] = '\0';
    printf("Inserisci cognome: ");
    fgets(cognome, NOMEDIM, stdin);
    cognome[strlen(cognome)-1] = '\0';
    
    paus = testa;
    while(paus != NULL) {
        if(strcmp(nome, paus->info.nome) == 0 &&
            strcmp(cognome, paus->info.cognome) == 0) {
            return paus;
        }
        paus = paus->next;
    }
    
    return NULL;
}

struct elemento * elimina(struct elemento *testa) {
    char nome[NOMEDIM], cognome[NOMEDIM];
    struct elemento *paus, *paus2;
    
    if(testa == NULL) {
        printf("Lista vuota\n");
        return testa;
    }
    
    printf("Inserisci nome: ");
    fgets(nome, NOMEDIM, stdin);
    nome[strlen(nome)-1] = '\0';
    printf("Inserisci cognome: ");
    fgets(cognome, NOMEDIM, stdin);
    cognome[strlen(cognome)-1] = '\0';
    
    if(strcmp(nome, testa->info.nome) == 0 &&
        strcmp(cognome, testa->info.cognome) == 0) {
        
        paus = testa->next;
        free(testa);
        return paus;
    }
    
    paus = testa;
    while(paus->next != NULL) {
        if(strcmp(nome, paus->next->info.nome) == 0 &&
            strcmp(cognome, paus->next->info.cognome) == 0) {
            
            paus2 = paus->next;
            paus->next = paus2->next;
            free(paus2);
            return testa;
        }
        paus = paus->next;
    }
    
    printf("Elemento non trovato\n");
    return testa;
}

void visualizza(struct elemento *testa) {
    if(testa == NULL) {
        printf("Lista vuota\n");
        return;
    }
    
    while(testa != NULL) {
        visualizza_elemento(testa->info);
        printf("-----------------------------------\n");
        testa = testa->next;
    }
}

void visualizza_elemento(struct persona ele) {
    printf("Nome e cognome: %s %s\n", ele.nome, ele.cognome);
    printf("Eta': %d\nIndirizzo: %s\n", ele.eta, ele.ind);
}

struct elemento * inserisci(struct elemento *testa) {
    struct elemento *nuovo;
    
    nuovo = (struct elemento *)malloc(sizeof(struct elemento));
    if(nuovo == NULL) {
        printf("errore allocazione!\n");
        return testa;
    }
    
    printf("Inserisci nome: ");
    fgets(nuovo->info.nome, NOMEDIM, stdin);
    nuovo->info.nome[strlen(nuovo->info.nome)-1] = '\0';
    printf("Inserisci cognome: ");
    fgets(nuovo->info.cognome, NOMEDIM, stdin);
    nuovo->info.cognome[strlen(nuovo->info.cognome)-1] = '\0';
    printf("Inserisci indirizzo: ");
    fgets(nuovo->info.ind, INDDIM, stdin);
    nuovo->info.ind[strlen(nuovo->info.ind)-1] = '\0';
    printf("Inserisci eta': ");
    scanf("%d%*c", &(nuovo->info.eta));
    
    nuovo->next = testa;
    return nuovo;
}













