/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Luis Felipe de Melo Costa Silva
// Numero USP: 9297961
// Sigla: LUISFELI
// Data: 2015-10-07
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* Programa: mergemultiplo.c
// Data: 2015-10-05
// Autores: Luis Felipe de Melo Costa Silva
//
// 
///////////////////////////////////////////////////////////////*/

#include <stdio.h>              /* fopen, fclose, fscanf, fprintf */
#include <stdlib.h>             /* malloc, free, EXIT_SUCCESS */
#include "is.h"                 /* intercalaSimples */

#define FALSE 0
#define TRUE 1

void debug (FILE *saida);

int main (int argc, char *argv[]) {
    
    int k, i, total;
    FILE **entrada;
    FILE *saida;

    k = argc - 3;

    entrada = malloc (k * sizeof (FILE *)); 

    for (i = 0; i < k; i++)
        entrada[i] = fopen (argv[i + 2], "r");  

    saida = fopen (argv[argc - 1], "w");

    if (argv[1][1] == 's')
        total = intercalaSimples (k, entrada, saida);    

    /*else if (argv[1][1] == 'h') 
        total = intercalaHeap (k, entrada[], saida);*/

    for (i = 0; i < k; i++)
        fclose (entrada[i]);

    debug (saida, total);

    fclose (saida);

    free (entrada);

    /*meudebug (k, entrada, saida, argv);*/

    return EXIT_SUCCESS;
}

void debug (FILE *saida, int n) {
    int leitura, tmp, soma, resposta, ant;

    soma = 0;

    resposta = TRUE;

    leitura = fscanf (saida, "%d", &tmp);

    while (leitura != EOF) {
        ant = tmp;
        soma++;
        leitura = fscanf (saida, "%d", &tmp);
        if (ant <= tmp)
            continue;
        else if (ant > tmp && leitura == TRUE)
            leitura = FALSE;
        else if (ant > tmp && leitura == FALSE)
            continue;
    }

    if (soma == n) {
        fprintf(saida, "O número de elementos lidos nos arquivos é igual ao número de elementos impressos.\n");
    }
    else 
        fprintf(saida, "O número de elementos lidos nos arquivos é diferente ao número de elementos impressos.\n");

    if (resposta == TRUE) printf("O arquivo está em ordem cresente.\n");
    else printf("O arquivo não está em ordem crescente.\n");

}