#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

void lerArquivo(t_arvore *raiz) {
    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    char linha[150];
    t_elemento elem;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d;%99[^\n]", &elem.codigo, elem.nome) == 2) {
            inserir(raiz, elem);
        }
    }

    fclose(arquivo);
    printf("Arquivo carregado com sucesso!\n");
}