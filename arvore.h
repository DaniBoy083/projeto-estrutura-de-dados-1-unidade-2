#ifndef ARVORE_H
#define ARVORE_H

typedef struct {
    int codigo;
    char nome[100];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no *esq;
    struct no *dir;
} t_no;

typedef t_no* t_arvore;

// protótipo da função inserir (pra não dar erro)
void inserir(t_arvore *raiz, t_elemento elem);

#endif