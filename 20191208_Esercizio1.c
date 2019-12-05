//Author: Filippo Venturini
//Date(DeadLine): 20191208
//Notes: Esercizio 1,
//       GESTIRE DOPPIO COGNOME,  GETS per acquisire il cognome INVECE DI SCANF, es: DAVIDE DI MARCO, nel programma risulta Davide DI
//       RIEMPIRE IL VETTORE DI INSEGNAMENTI, NON C0N UNA FUNZIONE, MA DIRETTAMENTE COME SE FOSSE UN VETTORE  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STUDENTI 5
#define NUM_ESAMI 5
#define MAX_INSEGNAMENTI 10
//Prototipi delle funzioni
void AggiungiStudente();
void StampaInfo(int);
void ModificaPianoStudi(int);
void Media();
void InizializzaInsegnamenti();

int contStudenti = 0; //Variabile globale che memorizza il numero di studenti presenti
int verificaScanf = 0; //Variabile globale per la verifica di tutti gli scanf

struct Studente
{
	int numMatricola;
	char nome[10];
	char cognome[10];
	int annoImmatricolazione;

	struct VotiEsami {
		int codice;
		int voto;
	}piano_di_studi [NUM_ESAMI];

} studenti [MAX_STUDENTI];

struct Insegnamento {
	int codice;
	char descrizione[100];
	int anno;
	int crediti;
} insegnamenti[MAX_INSEGNAMENTI];

//Inizializzazione dell'array di insegnamenti
void InizializzaInsegnamenti() {
	insegnamenti[0].codice = 819;
	strcat(insegnamenti[0].descrizione, "Programmazione");
	insegnamenti[0].anno = 1;
	insegnamenti[0].crediti = 12;

	insegnamenti[1].codice = 00013;
	strcat(insegnamenti[1].descrizione, "Analisi");
	insegnamenti[1].anno = 1;
	insegnamenti[1].crediti = 12;

	insegnamenti[2].codice = 58414;
	strcat(insegnamenti[2].descrizione, "Algebra_E_Geometria");
	insegnamenti[2].anno = 1;
	insegnamenti[2].crediti = 6;

	insegnamenti[3].codice = 26338;
	strcat(insegnamenti[3].descrizione, "Inglese_B1");
	insegnamenti[3].anno = 1;
	insegnamenti[3].crediti = 6;

	insegnamenti[4].codice = 69731;
	strcat(insegnamenti[4].descrizione, "Architetture_Degli_Elaboratori");
	insegnamenti[4].anno = 1;
	insegnamenti[4].crediti = 12;

	insegnamenti[5].codice = 70219;
	strcat(insegnamenti[5].descrizione, "Programmazione_Ad_Oggetti");
	insegnamenti[5].anno = 2;
	insegnamenti[5].crediti = 12;

	insegnamenti[6].codice = 8574;
	strcat(insegnamenti[6].descrizione, "Sistemi_Operativi");
	insegnamenti[6].anno = 2;
	insegnamenti[6].crediti = 12;

	insegnamenti[7].codice = 00405;
	strcat(insegnamenti[7].descrizione, "Fisica");
	insegnamenti[7].anno = 2;
	insegnamenti[7].crediti = 6;

	insegnamenti[8].codice = 10906;
	strcat(insegnamenti[8].descrizione, "Basi_Di_Dati");
	insegnamenti[8].anno = 2;
	insegnamenti[8].crediti = 12;

	insegnamenti[9].codice = 66736;
	strcat(insegnamenti[9].descrizione, "Metodi_Numerici");
	insegnamenti[9].anno = 2;
	insegnamenti[9].crediti = 6;
}

//Funzione per l'aggiunta di uno studente
void AggiungiStudente(){
	if (contStudenti == MAX_STUDENTI) { //In caso il vettore sia pieno
		printf("\n\t__STUDENTI AL COMPLETO__\n");
		return; //Esce dalla funzione
	}
	printf("-------------------------\n");
	printf("AGGIUNGERE STUDENTE :\n");
	int matricolaInserita = 0;
	bool presente; //Booleano per la verifica
	do {
		presente = false;
		printf("\n\tInserisci il numero di matricola: ");
		verificaScanf = scanf("%d", &matricolaInserita);
		while ((getchar()) != '\n'); //Pulizia del buffer

		for (int i = 0; i < contStudenti; i++) { //Ciclo di per controllare che lo studente non sia già presente
			if (studenti[i].numMatricola == matricolaInserita) {
				presente = true;
				printf("\t\tLo studente e' gia' presente!");
				break; //Esce dal ciclo
			}
		}
	} while (verificaScanf != 1 || presente);

	studenti[contStudenti].numMatricola = matricolaInserita; //Assegna il numero di matricola allo studente

	do {
		verificaScanf = 0;
		printf("\tInserire il nome: ");
		verificaScanf = scanf("%s", studenti[contStudenti].nome);
		while ((getchar()) != '\n'); //Pulizia del buffer
	} while (verificaScanf != 1);

	do {
		verificaScanf = 0;
		printf("\tInserire il cognome: ");
		verificaScanf = scanf("%s", studenti[contStudenti].cognome);
		while ((getchar()) != '\n'); //Pulizia del buffer
	} while (verificaScanf != 1);

	int annoInserito = 0;
	do {
		verificaScanf = 0;
		printf("\tInserire l'anno di immatricolazione [1900-2019]: ");
		verificaScanf = scanf("%d", &(annoInserito));
		while ((getchar()) != '\n'); //Pulizia del buffer
	}while(verificaScanf != 1 || annoInserito < 1900 || annoInserito > 2019); //Controlla che l'anno sia inserito entro un range
	studenti[contStudenti].annoImmatricolazione = annoInserito; //Inserimento dell'anno

	printf("\tSeleziona 5 esami per il piano di studi, tra quelli disponibili.\n"); //Output di presentazione di tutti gli insegnamenti disponibili
	for (int k = 0; k < MAX_INSEGNAMENTI; k++) {
		printf("\t%d) %s.\n", insegnamenti[k].codice, insegnamenti[k].descrizione);
	}

	int codiceInserito = 0;
	bool codCorretto; //Variabile per verificare il codice
	for (int j = 0; j < NUM_ESAMI; j++) {
		do {
			codCorretto = false;
			verificaScanf = 0;
			printf("\tDigita il codice dell'esame %d:", j + 1);
			verificaScanf = scanf("%d", &codiceInserito); //Inserisce il codice dentro all'elemento j-esimo del piano di studi
			while ((getchar()) != '\n'); //Pulizia del buffer
			for (int t = 0; t < MAX_INSEGNAMENTI; t++) { //Ciclo che controlla che il codice dell'insegnamento esista
				if (insegnamenti[t].codice == codiceInserito) {
					codCorretto = true;
					break;
				}
			}
		} while (verificaScanf != 1 ||codCorretto == false);

		studenti[contStudenti].piano_di_studi[j].codice = codiceInserito; //Assegna il codice dell'esame al piano di studi dello studente
	}

	contStudenti++; //Incremente il contatore di inserimento
	return;
}

//Funzione per stampare le informazioni relative ad uno studente
void StampaInfo(int matricola) {
	printf("-------------------------\n");
	printf("STAMPARE INFORMAZIONI:\n");
	for (int i = 0; i < MAX_STUDENTI; i++) { //Ciclo per trovare lo studente corrispondente
		if (studenti[i].numMatricola == matricola) {
			printf("\tNumero matricola: %d\n", studenti[i].numMatricola);
			printf("\tNome: %s\n", studenti[i].nome);
			printf("\tCognome: %s\n", studenti[i].cognome);
			printf("\tAnno di immatricolazione: %d\n", studenti[i].annoImmatricolazione);
			printf("\tPIANO DI STUDI:\n");
			for (int j = 0; j < NUM_ESAMI; j++){
				printf("\t\tCodice Esame: %d|Voto: %d|\n", studenti[i].piano_di_studi[j].codice, studenti[i].piano_di_studi[j].voto);
			}
			return; //Esce dalla funzione
		}
	}
	printf("\t__MATRICOLA NON PRESENTE__\n");
	return;
}

//Funzione per la modifica del piano di studi
void ModificaPianoStudi(int matricola) {
	printf("-------------------------\n");
	printf("MODIFICARE IL PIANO DI STUDI:\n");
	int codiceInserito = 0; //Variabile per il codice dell'esame
	int votoInserito = 0; //Variabile per il voto
	for (int i = 0; i < MAX_STUDENTI; i++) { //Ciclo per trovare lo studente corrispondente
		if (studenti[i].numMatricola == matricola) {
			StampaInfo(matricola); //Visualizza i dati relativi alla matricola di cui si vuole modificare il piano di studi
			do {
				verificaScanf = 0;
				printf("Codice dell'esame: ");
				verificaScanf = scanf("%d", &codiceInserito);
				while ((getchar()) != '\n'); //Pulizia del buffer
			} while (verificaScanf != 1);

			for (int k = 0; k < NUM_ESAMI; k++){
				if (studenti[i].piano_di_studi[k].codice == codiceInserito) {
					do {
						verificaScanf = 0;
						verificaScanf = printf("\tInserire il voto (31 per la lode): ");
						verificaScanf = scanf("%d", &votoInserito); //Inserisce il voto
						while ((getchar()) != '\n'); //Pulizia del buffer

						if (votoInserito < 18 || votoInserito > 31) {
							printf("\t\tVoto inserito errato!\n");
						}
					} while (verificaScanf != 1 || votoInserito < 18 || votoInserito > 31);

					studenti[i].piano_di_studi[k].voto = votoInserito; //Inserisce il voto
					printf("\t\tVOTO INSERITO.\n");
					return;//Esce dalla funzione perchè la valutazione è stata modificata
				}
			    if (k == NUM_ESAMI - 1) {
					printf("\tNon e' presente l'esame indicato."); //In caso l'esame indicato non sia presente
				}
			}
		}
	}
	printf("\t__MATRICOLA NON PRESENTE__\n");
	return;
}

void Media() {
	printf("-------------------------\n");
	printf("CALCOLARE LA MEDIA DEI VOTI:\n");
	if (studenti[0].numMatricola == NULL) { //Controlla che la struttura non sia vuota
		printf("\tNon sono presenti studenti!\n");
		return; //Esce dalla funzione
	}
	int sommaTotale; //Variabile per la somma pesata totale
	int sommaCrediti; //Somma di tutti i crediti
	int creditiEsame;
	bool completo;
	for (int i = 0; i < contStudenti; i++) {
		sommaTotale = 0;
	    sommaCrediti = 0;
		completo = true;
		for (int k = 0; k < NUM_ESAMI && completo == true; k++) {
			if (studenti[i].piano_di_studi[k].voto == 0) {
				completo = false; //Esce dal ciclo perchè lo studente non ha completato tutti gli esami
			}
			else {
				creditiEsame = 0;//Setta i crediti del singolo esame a 0
				for (int j = 0; j < MAX_INSEGNAMENTI; j++) { //Scorre tutti gli insegnamenti
					if (studenti[i].piano_di_studi[k].codice == insegnamenti[j].codice) {
						creditiEsame = insegnamenti[j].crediti; //Memorizza in una variabile i crediti corrispondenti all'insegnamento
						sommaCrediti += creditiEsame; //Aggiunge i crediti alla somma dei pesi
						break; //Esce dal ciclo
					}
				}
				sommaTotale += studenti[i].piano_di_studi[k].voto*creditiEsame; //Aggiunge alla somma totale il valore pesato del singolo esame
			}
		}
		if (completo) {
			printf("\tNome: %s |Cognome: %s |Media:%d\n",studenti[i].nome, studenti[i].cognome, sommaTotale / sommaCrediti); //Calcola la media del singolo studente
		}
		else {
			printf("\tNome: %s |Cognome: %s |\n\t\tPIANO DI STUDI NON COMPLETO!\n", studenti[i].nome, studenti[i].cognome); //In caso lo studente non abbia svolto tutti gli esami
		}
	}
}
int main() {
	InizializzaInsegnamenti(); //Inizializza tutti gli insegnamenti
	do {
		int opzioneScelta = 0; //Memorizza l'opzione da effetturare
		int matricolaInserita = 0; //Memorizza la matricola inserita
		do {
			verificaScanf = 0;
			printf("-------------------------\n");
			printf("|AGGIUNGERE STUDENTE : 1|\n|STAMPARE INFORMAZIONI: 2|\n|MODIFICARE IL PIANO DI STUDI: 3|\n|CALCOLARE LA MEDIA DEI VOTI: 4|\n|USCIRE: 5| ");
			printf("\nOpzione desiderata: ");
			verificaScanf = scanf("%d", &opzioneScelta);
			while ((getchar()) != '\n'); //Pulizia del buffer
		} while (verificaScanf != 1);

		if (opzioneScelta == 5) //Esce dal ciclo
			return 0;
		switch (opzioneScelta) { //Switch per le varie casistiche
		case 1:
			AggiungiStudente();
			break;
		case 2:
			do {
				verificaScanf = 0;
				printf("\tMatricola: ");
				verificaScanf = scanf("%d", &matricolaInserita);
				while ((getchar()) != '\n'); //Pulizia del buffer
			} while (verificaScanf != 1);

			StampaInfo(matricolaInserita); //Invoca la funzione per la stampa delle info
			break;
		case 3:
			do {
				verificaScanf = 0;
				printf("\tMatricola: ");
				verificaScanf = scanf("%d", &matricolaInserita);
				while ((getchar()) != '\n'); //Pulizia del buffer
			} while (verificaScanf != 1);

			ModificaPianoStudi(matricolaInserita); //Invoca la funzione per la modifica del piano di studi
			break;
		case 4:
			Media(); //Invoca la funzione per la media
			break;
		}
	} while (true);

	getchar();
	return 0;
}
