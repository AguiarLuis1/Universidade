#include "library.h"

int main() {
    int dim1, dim2;
    char **sopa;//matrix sopa
    char **dictionary; //matrix dicionario
    int ncol;
    int nline;
    int npalavras;
    int numpalavras;
/*  printf("Insira a dimensao da sopa de letras (linha x coluna):\n");
    scanf("%d%d", &dim1, &dim2);
    sopa = Create_Sopa(dim1, dim2);
    printf("\nQuantas palavras deseja colocar no dicionario?");
    scanf("%d", &numpalavras);*/
//   dictionary = Create_Dictionary(numpalavras);

//    print_dictionary(dictionary, numpalavras);
//    clienteMSDSORT_WHITHOUT_CUTOFF(dictionary, numpalavras);
    sopa = read_sopa(&nline, &ncol);//ncol=nº colunas da matriz ,nline=nº linhas da matriz*/
    print_sopa(sopa, nline, ncol);
    dictionary = read_dictionary(&npalavras);
    print_dictionary(dictionary, npalavras);
    clienteMSDSORT_WHITHOUT_CUTOFF(dictionary,npalavras);
    printf("\nPalavras encontradas:\n");
      for (int i = 0; i < npalavras; i++) {//ciclo para procurar as palavras na sopa
        printf("%s\n", *(dictionary + i));
        checkword(ncol, nline, *(dictionary + i), sopa);
        printf("\n");
    }

 //   checkword(ncol, nline, "PORTO", sopa);

    return 0;
}
