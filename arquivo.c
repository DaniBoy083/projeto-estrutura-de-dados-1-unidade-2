#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

void esvaziar(t_arvore *raiz) {
    if (*raiz != NULL) {
        esvaziar(&((*raiz)->esq));
        esvaziar(&((*raiz)->dir));
        free(*raiz);
        *raiz = NULL;
    }
}

void lerArquivo(t_arvore *raiz) {
    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    char linha[150];
    t_elemento elem;

    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%d;%99[^\n]", &elem.codigo, elem.nome);
        inserir(raiz, elem);
    }

    fclose(arquivo);
}

void exibirGrafico(t_arvore raiz, int nivel) {
    if (raiz != NULL) {
        exibirGrafico(raiz->dir, nivel + 1);

        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }

        printf("%d\n", raiz->dado.codigo);

        exibirGrafico(raiz->esq, nivel + 1);
    }
}