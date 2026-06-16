#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <string.h>


/* Validações */
int validarCodigo(int codigo) {
    if(codigo <= 0) {
        printf("[ERRO] Codigo invalido, o mesmo precisa ser um inteiro positivo. \n");
        return 0;
    }
    return 1;
}


int validarNome(const char *nome) {
    if (nome == NULL || strlen(nome) == 0) {
        printf("[ERRO] Nome invalido: nao pode ser vazio.\n");
        return 0;
    }
    if (strlen(nome) > 99) {
        printf("[ERRO] Nome invalido: deve ter no maximo 99 caracteres.\n");
        return 0;
    }
    return 1;
}
 

int validarElemento(t_elemento dado) {
    return validarCodigo(dado.codigo) && validarNome(dado.nome);
}
 


/* Comparação baseada no código (chave de pesquisa da ABB) */
int compara(t_elemento a, t_elemento b)
{
    if (a.codigo < b.codigo) return -1;
    if (a.codigo > b.codigo) return 1;
    return 0;
}

/* Pré-ordem */
void exibirPreOrdem(t_arvore tree)
{
    if (tree != NULL) {
        printf("[%d] %s\n", tree->dado.codigo, tree->dado.nome);
        exibirPreOrdem(tree->esq);
        exibirPreOrdem(tree->dir);
    }
}

/* In-ordem */
void exibirInOrdem(t_arvore tree)
{
    if (tree != NULL) {
        exibirInOrdem(tree->esq);
        printf("[%d] %s\n", tree->dado.codigo, tree->dado.nome);
        exibirInOrdem(tree->dir);
    }
}

/* Pós-ordem */
void exibirPosOrdem(t_arvore tree)
{
    if (tree != NULL) {
        exibirPosOrdem(tree->esq);
        exibirPosOrdem(tree->dir);
        printf("[%d] %s\n", tree->dado.codigo, tree->dado.nome);
    }
}

/* Criar nó */
t_no *criar(t_elemento dado)
{
    t_no *novo = (t_no *) malloc(sizeof(t_no));

    if (novo == NULL) {
        printf("[ERRO] Falha ao alocar memoria para o no. \n");
        return NULL;
    }

    novo -> dado = dado;
    novo->esq = novo->dir = NULL;
    return novo;
}

/* Nó vazio */
int isVazia(t_no *no)
{
    return (no == NULL);
}

/* Busca (percorre toda a árvore, sem usar a propriedade de ABB) */
t_no *busca(t_arvore tree, t_elemento dado)
{
    t_no *achou;

    if (tree == NULL)
        return NULL;

    if (compara(tree->dado, dado) == 0)
        return tree;

    achou = busca(tree->esq, dado);

    if (achou == NULL)
        achou = busca(tree->dir, dado);

    return achou;
}

/* Inserir raiz */
int insereRaiz(t_arvore *tree, t_elemento dado){
    if (!validarElemento(dado)) {
        return 0;
    }

    if (*tree != NULL){
        printf ("[AVISO] Arvore ja possui raiz. Use inserir() para adicionar novos nos.\n");
        return 0;
    }

    t_no *novo = criar(dado);

    if (novo == NULL){
        return 0;
    }
        

    if (novo == NULL){
        return 0;
    }
        

    *tree = novo;
    
    printf("[OK] Raiz inserida com sucesso\n");
    return 1;

}
/* Inserir à direita */
int insereDireita(t_arvore tree, t_elemento pai, t_elemento filho)
{
    t_no *f, *p, *novo;

    f = busca(tree, filho);
    if (f != NULL)
        return 0;

    p = busca(tree, pai);
    if (p == NULL)
        return 0;

    if (p->dir != NULL)
        return 0;

    novo = criar(filho);
    if (novo == NULL)
        return 0;

    p->dir = novo;

    return 1;
}

/* Inserir à esquerda */
int insereEsquerda(t_arvore tree, t_elemento pai, t_elemento filho)
{
    t_no *f, *p, *novo;

    f = busca(tree, filho);
    if (f != NULL)
        return 0;

    p = busca(tree, pai);
    if (p == NULL)
        return 0;

    if (p->esq != NULL)
        return 0;

    novo = criar(filho);
    if (novo == NULL)
        return 0;

    
    p->esq = novo;

    return 1;
}

/* Exibição gráfica (versão para terminal comum, sem conio.h) */
void exibirGraficamente(t_arvore tree, int col, int lin, int desloc)
{
    if (tree == NULL)
        return;

    /* Imprime recuo proporcional ao nível, simulando posição horizontal */
    for (int i = 0; i < lin; i++)
        printf("    ");

    printf("[%d] %s\n", tree->dado.codigo, tree->dado.nome);

    if (tree->esq != NULL)
        exibirGraficamente(tree->esq, col - desloc, lin + 1, desloc / 2 + 1);

    if (tree->dir != NULL)
        exibirGraficamente(tree->dir, col + desloc, lin + 1, desloc / 2 + 1);
}

/* Esvaziar */
void esvaziar(t_arvore *tree)
{
    if (*tree == NULL)
        return;

    esvaziar(&(*tree)->esq);
    esvaziar(&(*tree)->dir);

    free(*tree);
    *tree = NULL;
}

/* Busca ABB */
t_no *buscaABB(t_arvore tree, t_elemento dado)
{
    if (tree == NULL)
        return NULL;

    if (compara(tree->dado, dado) == 0)
        return tree;

    if (compara(tree->dado, dado) > 0)
        return buscaABB(tree->esq, dado);
    else
        return buscaABB(tree->dir, dado);
}

/* Inserção ABB */
int inserir(t_arvore *tree, t_elemento dado)
{
    if (!validarElemento(dado)) {
        return 0;
    }
    int ok;

    if (*tree == NULL) {
        *tree = criar(dado);

        if (*tree == NULL)
            return 0;

        return 1;
    }

    if (compara((*tree)->dado, dado) < 0)
        ok = inserir(&((*tree)->dir), dado);
    else if (compara((*tree)->dado, dado) > 0)
        ok = inserir(&((*tree)->esq), dado);
    else
        printf("[AVISO] Codigo %d ja existe na arvore. Insercao ignorada.\n", dado.codigo);
        ok = 0;

    return ok;
}

/* Busca um nó na ABB e retorna também seu nó pai */
t_no *buscaSetPai(t_arvore tree, t_elemento dado, t_no **pai)
{
    if (tree == NULL) {
        *pai = NULL;
        return NULL;
    }

    if (compara(tree->dado, dado) == 0)
        return tree;

    if (compara(tree->dado, dado) > 0) {
        *pai = tree;
        return buscaSetPai(tree->esq, dado, pai);
    } else {
        *pai = tree;
        return buscaSetPai(tree->dir, dado, pai);
    }
}

/* Remoção em ABB:
   Caso 1: nó folha
   Caso 2: nó com um filho
   Caso 3: nó com dois filhos usando sucessor
*/
int remover(t_arvore *tree, t_elemento item)
{
    t_no *no, *pai, *sub, *paiSuce, *suce;

    pai = NULL;

    no = buscaSetPai(*tree, item, &pai);

    if (no == NULL)
        return 0;

    /* Caso 1: nó sem filho esquerdo */
    if (no->esq == NULL)
        sub = no->dir;
        
    /* Caso 2: nó sem filho direito */
    else if (no->dir == NULL)
        sub = no->esq;
        
   /* Caso 3: nó com dois filhos */
    else {
        paiSuce = no;
        sub = no->dir;
        suce = sub->esq;
        
   /* Busca do sucessor em ordem */
        while (suce != NULL) {
            paiSuce = sub;
            sub = suce;
            suce = sub->esq;
        }
  /* Reorganiza os ponteiros após encontrar o sucessor */
        if (paiSuce != no) {
            paiSuce->esq = sub->dir;
            sub->dir = no->dir;
        }

        sub->esq = no->esq;
    }

    if (pai == NULL)
        *tree = sub;
    else if (no == pai->esq)
        pai->esq = sub;
    else
        pai->dir = sub;

    free(no);

    return 1;
}
