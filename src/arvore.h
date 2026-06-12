#ifndef ARVORE_H
#define ARVORE_H

/* Estruturas */
typedef struct elementos {
    int codigo;
    char nome[100];
} t_elemento;

typedef struct no {
    struct no *esq;
    t_elemento dado;
    struct no *dir;
} t_no;

typedef t_no* t_arvore;

/* Comparação (chave = codigo) */
int compara(t_elemento a, t_elemento b);

/* Criação / verificação */
t_no *criar(void);
int isVazia(t_no *no);

/* Busca */
t_no *busca(t_arvore tree, t_elemento dado);
t_no *buscaABB(t_arvore tree, t_elemento dado);
t_no *buscaSetPai(t_arvore tree, t_elemento dado, t_no **pai);

/* Inserção */
int insereRaiz(t_arvore *tree, t_elemento dado);
int insereDireita(t_arvore tree, t_elemento pai, t_elemento filho);
int insereEsquerda(t_arvore tree, t_elemento pai, t_elemento filho);
int inserir(t_arvore *tree, t_elemento item);

/* Remoção */
int remover(t_arvore *tree, t_elemento item);

/* Esvaziar */
void esvaziar(t_arvore *tree);

/* Exibição */
void exibirPreOrdem(t_arvore tree);
void exibirInOrdem(t_arvore tree);
void exibirPosOrdem(t_arvore tree);
void exibirGraficamente(t_arvore tree, int col, int lin, int desloc);

#endif