#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef PROJETOFINALAEDLP_LIBRARY_H
#define PROJETOFINALAEDLP_LIBRARY_H
// tamanho do alfabeto de chars com 8 bits (ASCII)
#define CHAR_8BIT_RADIX 256
// simbolo de termino de strings
#define STRING_END_CHAR -1
// Tamanho maximo de qualquer palavra no fase1.
#define MAX_WORD_LENGTH 20


typedef struct Dicionario {
    // Um array 2D de char para guardar as palavras do ficheiro dicionario
    char **palavras;

    //matriz das palavras lidas do dicionario depois de ordenadas pelo metodo msd
    //char **palavras_msd;

    // Um array de inteiros para contar quantas vezes cada palavra do dicionario
    // é encontrada no puzzle de palavras. Deve ser dinamicamente alocada.
    int *conta;

    // O numero de palavras no fase1
    int tamanho;
} Dicionario;

typedef struct {
    char **str; // array de strings
    int *len; // array de comprimento de strings
    int N; // numero de strings (tamanho do array de strings)
} StringElementsArray;

//R1
char **Create_Dictionary(int n);


void print_dictionary(char **matrix, int n);


char** read_dictionary(int *npalavras);

//R2(MSD)
void clienteMSDSORT_WHITHOUT_CUTOFF(char **dic, int N);

int *newIntArray(int N);

void msd_sort_without_cutoff(StringElementsArray *a, StringElementsArray *aux, int lo, int hi, int d, int R);

void createStringElementsArrayAndFill(StringElementsArray *si, int N, char **strings);

void freeStringElementsArray(StringElementsArray *si);

void createStringElementsArray(StringElementsArray *si, int N);

int charAt(StringElementsArray *a, int i, int d);

//R3
char **Create_Sopa(int row, int col);

void print_sopa(char **matrix, int row, int col);

char **read_sopa(int *nlin,int *ncol);


//R4
int checkconsistency(int col, int line, int nCols, int nLines, char search, char **sopa);

void find_path(int col, int line, int nCols, int nLines, char *word, int *direction, int size,
               int sizewrd, char **sopa);

void checkword(int nCols, int nLines, char *word, char **sopa);

void print_directions(int *direction, int size);
int **matrizdirections(int *directions,int size,int pos);

#endif //PROJETOFINALAEDLP_LIBRARY_H
