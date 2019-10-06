//Author: Filippo Venturini
//Date(Deadline): 20191013
//Notes: Esercizio 1
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Libreria per i limiti di int e char
#include <float.h> //Libreria per i limiti di float e double
int main()
{
    //Dichiarazione e assegnazione di una variabile per ogni tipo studiato
    int intero = 20;
    unsigned int intNoSegno = 50;
    signed int intSegno = -30;
    short int intShort = 2;
    long int intLong = 123456;
    float precisioneSingola = 3.123f;
    double precisioneDoppia = 7.123456;
    char carattere = 'C';
    signed char charConSegno = 'S';
    unsigned char charNoSegno = 'U';

    printf("|Numero di caratteri: %d\n",printf("Intero            | Valore: %8d |Byte: %d |Valore Min: %13d | Valore Max: %14d\t",intero, sizeof(int), INT_MIN, INT_MAX));
    printf("|Numero di caratteri: %d\n",printf("Intero senza segno| Valore: %8d |Byte: %d |Valore Min: %13d | Valore Max: %14u\t",intNoSegno, sizeof(unsigned int), 0, UINT_MAX));
    printf("|Numero di caratteri: %d\n",printf("Intero con segno  | Valore: %8d |Byte: %d |Valore Min: %13d | Valore Max: %14d\t",intSegno, sizeof(signed int), INT_MIN, INT_MAX));
    printf("|Numero di caratteri: %d\n",printf("Intero short      | Valore: %08d |Byte: %d |Valore Min: %13d | Valore Max: %14d\t",intShort, sizeof(short int), SHRT_MIN, SHRT_MAX)); //Sostituzione degli spazi con 0
    printf("|Numero di caratteri: %d\n",printf("Intero long       | Valore: %8ld |Byte: %d |Valore Min: %13ld | Valore Max: %14ld\t",intLong, sizeof(long int), LONG_MIN, LONG_MAX)); //Modificatore di lunghezza per indicare che la variabile è long
    printf("|Numero di caratteri: %d\n",printf("Float             | Valore: %-8.4f |Byte: %d |Valore Min: %13e | Valore Max: %14e\t",precisioneSingola, sizeof(float), FLT_MIN, FLT_MAX)); //Allineamento a sinistra, campoMinimo e precisione
    printf("|Numero di caratteri: %d\n",printf("Double            | Valore: %-8.4f |Byte: %d |Valore Min: %13e | Valore Max: %14e\t",precisioneDoppia, sizeof(double), DBL_MIN, DBL_MAX)); //Allineamento a sinistra, campoMinimo e precisione
    printf("|Numero di caratteri: %d\n",printf("Char              | Valore: %8c |Byte: %d |Valore Min: %13d | Valore Max: %14d\t",carattere, sizeof(char),CHAR_MIN, CHAR_MAX));
    printf("|Numero di caratteri: %d\n",printf("Char senza segno  | Valore: %8c |Byte: %d |Valore Min: %13d | Valore Max: %14d\t",charNoSegno, sizeof(unsigned char),0, UCHAR_MAX));
    printf("|Numero di caratteri: %d\n",printf("Char con segno    | Valore: %8c |Byte: %d |Valore Min: %13d | Valore Max: %14d\t",charConSegno, sizeof(signed char),SCHAR_MIN, SCHAR_MAX));

    system("PAUSE"); //Pausa per permettere la visualizzazione dell'output

    return 0;
}
