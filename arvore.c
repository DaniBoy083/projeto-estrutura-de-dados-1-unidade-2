#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void inserir(t_arvore *raiz, t_elemento elem) {
    if (*raiz == NULL) {
        *raiz = (t_no*) malloc(sizeof(t_no));
        (*raiz)->dado = elem;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        if (elem.codigo < (*raiz)->dado.codigo) {
            inserir(&((*raiz)->esq), elem);
        } else {
            inserir(&((*raiz)->dir), elem);
        }
    }
}