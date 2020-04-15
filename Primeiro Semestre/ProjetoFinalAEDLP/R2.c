#include "library.h"

void clienteMSDSORT_WHITHOUT_CUTOFF(char **dic, int N) {
    int i;
    StringElementsArray a;
    StringElementsArray aux; // aux Array
    createStringElementsArrayAndFill(&a, N, dic);
    createStringElementsArray(&aux, N); // create aux array
    msd_sort_without_cutoff(&a, &aux, 0, N - 1, 0, CHAR_8BIT_RADIX); // MSD sort
    printf("\n----------------------------------\nDicionario Ordenado pelo MSD:\n");
    for (i = 0; i < N; i++)
        printf("%s\n", a.str[i]); // o diciionario ordenado e guardado na struct em StringElementsArray no array str
    // o cumprimentos de cada string é guardado na mesma struct em len
    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);

}

// funcao teste para o array ordenado
void msd_sort_without_cutoff(StringElementsArray *a, StringElementsArray *aux, int lo, int hi, int d, int R) {
    int i, r, c;
    int *count = newIntArray(R + 2);
    // reset count[] array
    for (i = 0; i < R + 2; i++)
        count[i] = 0;

    if (hi <= lo) return;
    //if (hi - lo <= cutoff_value) insertion_sort();

    // compute frequency counts
    for (i = lo; i <= hi; i++) {
        c = charAt(a, i, d);
        count[c + 2]++;
    }

    // transform counts to indicies
    for (r = 0; r < R + 1; r++)
        count[r + 1] += count[r];

    // distribute
    for (i = lo; i <= hi; i++) {
        c = charAt(a, i, d);
        aux->str[count[c + 1]] = a->str[i];
        aux->len[count[c + 1]] = a->len[i];
        count[c + 1]++;
    }

    // copy back
    for (i = lo; i <= hi; i++) {
        a->str[i] = aux->str[i - lo];
        a->len[i] = aux->len[i - lo];
    }


    // recursively sort for each character

    for (r = 0; r < R; r++)
        msd_sort_without_cutoff(a, aux, lo + count[r], lo + count[r + 1] - 1, d + 1, R);
}

void createStringElementsArrayAndFill(StringElementsArray *si, int N, char **strings) {
    int i;
    createStringElementsArray(si, N);
    for (i = 0; i < N; i++) {
        si->str[i] = strings[i];
        si->len[i] = (int) strlen(strings[i]);
    }
}

void freeStringElementsArray(StringElementsArray *si) {
    free(si->str);
    free(si->len);

}

void createStringElementsArray(StringElementsArray *si, int N) {
    si->N = N;
    si->str = (char **) malloc(sizeof(char *) * N);
    si->len = (int *) malloc(sizeof(int) * N);
}


int charAt(StringElementsArray *a, int i, int d) {

    return (d < a->len[i]) ? (a->str[i][d]) : STRING_END_CHAR;
}

int *newIntArray(int N) {
    return (int *) malloc(sizeof(int) * N);

}

