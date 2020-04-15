#include "library.h"
char **Create_Sopa(int row, int col) {
    srand(time(NULL));
    int i, j;
    char **matrix = malloc(row * sizeof(char *));
    for (i = 0; i < row; i++) {
        *(matrix + i) = malloc(col * sizeof(char));
        for (j = 0; j < col; j++) {
            matrix[i][j] = 'A' + (rand() % 26);
        }
    }

    return matrix;
}
void print_sopa(char **matrix, int row, int col) {
    printf("\n---------------------------------\nMatriz\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
char **read_sopa(int *nlin, int *ncol) {
    char linha[100];
    FILE *arquivo;
    arquivo = fopen("C:\\Users\\Aguia\\CLionProjects\\ProjetoFinalAEDLP\\sopa.txt", "r");
    if (arquivo == NULL) {
        printf("Erro a abrir o ficheiro\n");
    }
    fscanf(arquivo, "%d %d", nlin, ncol);
    char **matriz = malloc(*nlin * sizeof(char *));
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        for (int i = 0; i < *nlin; i++) {
            *(matriz + i) = malloc(*ncol * sizeof(char));
            for (int j = 0; j < (*ncol + 1); j++) {
                matriz[i][j] = getc(arquivo);
            }

        }
    }
    fclose(arquivo);
    return matriz;
}
