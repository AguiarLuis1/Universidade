#include "library.h"

/**
 *
 * @param col = coluna atual
 * @param line = linha atual
 * @param nCols =nª total de colunas
 * @param nLines =nª total de linhas
 * @param search =char na posição testada
 * @param sopa =matriz sopa de letras
 * @return 1 se poder avançar e 0 se não poder
 */
int checkconsistency(int col, int line, int nCols, int nLines, char search, char **sopa) {

    if (line >= 0 && col >= 0 && line < nLines && col < nCols)
        if (*(*(sopa + line) + col) == search)
            return 1;

    return 0;
}

/**
 *
 * @param nCols = numero total de colunas
 * @param nLines = numero total de linhas
 * @param word = palavra que estamos á procura
 * @param sopa = matriz sopa
 */
void checkword(int nCols, int nLines, char *word, char **sopa) {
    int sizewrd = strlen(word);
    int *direction = calloc(4 + sizewrd, sizeof(int));
    for (int line = 0; line < nLines; ++line) {

        for (int col = 0; col < nCols; ++col) {
            if (sopa[line][col] ==
                *word) { //Compara todas as letras da sopa de letras com a primeira letra da palavra que procuramos
                *(direction + 0) = line;
                *(direction + 1) = col;
                find_path(col, line, nCols, nLines, word + 1, direction, 4,
                          sizewrd,
                          sopa);//word+1 porque já se encontrou a pos da pos 0 e size começa em 1 pelo mesmo motivo

            }
        }
    }
}

/**
 *
 * @param col = col da prim letra
 * @param line =line da prim letra
 * @param nCols =nº de colunas
 * @param nLines  =nº de linhas
 * @param word =palavra que estamos a procura sem a primeira letra
 * @param direction
 * @param size
 * @param sizewrd
 * @param sopa
 */
void find_path(int col, int line, int nCols, int nLines, char *word, int *direction, int size,
               int sizewrd, char **sopa) {
    if (size - 3 == sizewrd) {//porque o size só é incrementado quando se encontra a letra ou seja quando o size tem o tamanho da str significa que se encontraram todas as letras
        *(direction + 2) = line;//size -3 porque o find path so trabalha com a palavra sem a 1ª letra e tem 4 espaços reservados
        *(direction + 3) = col;
        print_directions(direction,size);
        return;
    }
    //SUL
    if (checkconsistency(col, line + 1, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 1;
        find_path(col, line + 1, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //NORTE
    if (checkconsistency(col, line - 1, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 2;
        find_path(col, line - 1, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //ESTE
    if (checkconsistency(col + 1, line, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 3;
        find_path(col + 1, line, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //OESTE
    if (checkconsistency(col - 1, line, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 4;
        find_path(col - 1, line, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //NO
    if (checkconsistency(col - 1, line - 1, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 5;
        find_path(col - 1, line - 1, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //NE
    if (checkconsistency(col + 1, line - 1, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 6;
        find_path(col + 1, line - 1, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //SE
    if (checkconsistency(col + 1, line + 1, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 7;
        find_path(col + 1, line + 1, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }
    //SO
    if (checkconsistency(col - 1, line + 1, nCols, nLines, *word, sopa) == 1) {
        *(direction + size) = 8;
        find_path(col - 1, line + 1, nCols, nLines, (word + 1), direction, size + 1, sizewrd, sopa);
    }

}

void print_directions(int *direction, int size) {//Decodifica o "código" do array directions
    static int count = 0;
    count++;
    printf("%d", count);
    printf("[%d,%d]->[%d,%d] | ", *(direction + 0), *(direction + 1), *(direction + 2), *(direction + 3));//pos primeira letra e ultima letra
    printf("[%d,%d]->", *(direction + 0), *(direction + 1));
    for (int i = 4; i < size; ++i) {//size-1 porque imprime a ultima pos com coordenadas
        if (*(direction + i) == 1)
            printf("S");
        if (*(direction + i) == 2)
            printf("N");
        if (*(direction + i) == 3)
            printf("E");
        if (*(direction + i) == 4)
            printf("O");
        if (*(direction + i) == 5)
            printf("NO");
        if (*(direction + i) == 6)
            printf("NE");
        if (*(direction + i) == 7)
            printf("SE");
        if (*(direction + i) == 8)
            printf("SO");
        if (i != size-1) {
            printf("->");
        }
    }
    printf("\n");
}

