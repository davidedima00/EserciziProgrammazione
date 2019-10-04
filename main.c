//Author: Filippo Venturini
//Date(Deadline): 20191013
//Notes: Esercizio 2
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Conversione implicita
    float f = 3.123;
    int i = f; //Assegna ad una variabile intera un valore float
    printf("APPLICAZIONE DELLA CONVERSIONE IMPLICITA:\n");
    printf("f = %f,\ni = f,\nValore di i: %d.\n\n",f,i); //Print del risultato

    //Superamento del range di memorizzazione
    printf("SUPERAMENTO DEL RANGE DI MEMORIZZAZIONE:\n");
    short incassiGiugno = 25000;
    short incassiLuglio = 30000;
    short incassiAgosto = 31000;
    short incassiEstivi = incassiGiugno + incassiLuglio + incassiAgosto;
    printf("Incassi Giugno: %d;\nIncassi Luglio: %d;\nIncassi Agosto: %d;\nIncassi Estivi(Giugno+Luglio+Agosto): %d. ",incassiGiugno,incassiLuglio,incassiAgosto,incassiEstivi);

    return 0;
}
