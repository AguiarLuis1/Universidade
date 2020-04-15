#include "library.h"
char **Create_Dictionary(int n) {
    int i;
    char **matrix = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        *(matrix + i) = (malloc(n * sizeof(char)));
        printf("Palavra[%d](EM CAPS LOCK)\n",(i+1));
        scanf("%s", matrix[i]);
    }
    return matrix;
}
char** read_dictionary(int *npalavras) {
    int i;
    char *test = malloc(sizeof(char) * (MAX_WORD_LENGTH + 1));
    FILE *arquivo = fopen("C:\\Users\\Aguia\\CLionProjects\\ProjetoFinalAEDLP\\dicionario.txt", "r");
    fscanf(arquivo, "%d", npalavras);
    char **matriz = (char**) malloc(*npalavras * sizeof(char *));
    memset(&test[0], 0, sizeof(test));
    for (i = 0; i < *npalavras; i++) {
        fscanf(arquivo, "%s", test);
        *(matriz+i) = (char*)malloc(sizeof(char) * (strlen(test)));
        strcpy(matriz[i], test);
    }
    fclose(arquivo);
    return matriz;
}

void print_dictionary(char **matrix, int n) {
    printf("\n---------------------------------\nDicionario:");
    for (int i = 0; i < n; ++i) {
        printf("\n%s", matrix[i]);
    }
}