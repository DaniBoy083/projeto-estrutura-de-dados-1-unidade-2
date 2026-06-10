#include <stdio.h>
#include "arvore.h"
#include "arquivo.h"

int main() {
    t_arvore raiz = NULL;

    // leitura do arquivo e inserção na árvore
    lerArquivo(&raiz);

    // exibe a árvore
    printf("\nArvore:\n");
    exibirGrafico(raiz, 0);

    // testa o esvaziamento
    printf("\nEsvaziando a arvore...\n");
    esvaziar(&raiz);

    // tenta exibir depois de esvaziar
    printf("\nArvore apos esvaziar:\n");
    exibirGrafico(raiz, 0);

    return 0;
}