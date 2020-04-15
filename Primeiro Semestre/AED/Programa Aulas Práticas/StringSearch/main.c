#include <stdio.h>
#include "strings.h"
//percorre cada caracter do texto e no pior dos casos e testa a substring até ao fim
//no pior caso tem custo de O(N+M)
char *strstrbf(char *txt, char *pat);

int main() {
    char *txt = "abracadabra";
    char *pat = "abra";
    char *c = strstrbf(txt, pat);
    int count=0;
    printf("String ORIGINAl\tString Procurada\n");
    printf("%s\t|%s\n", txt, pat);
    while (c != -1) {
        c = strstrbf(c, pat);
        if (c != -1) {
            count++;
            printf("Match in i=%d\n", (int) (c - txt));//subtrai o endereço de txt ao de c para obter o indice
            c++;//só se incrementa 1 para procurar na posição seguinte á encontrada
        } else printf("Nao existem mais match da Substring na String\n");
    }
    return 0;
}//é um algoritmo de brute-force porque testa todas as alternativas possiveis

char *strstrbf(char *txt, char *pat) {
    int j;
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i < N - M+1; ++i) {
        for (j = 0; j < M; ++j)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
            return &txt[i];
    }
    return -1;
}
