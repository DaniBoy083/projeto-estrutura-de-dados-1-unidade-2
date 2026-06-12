#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

/* Protótipos das funções de fluxo do menu */
void menuInserir(t_arvore *raiz);
void menuRemover(t_arvore *raiz);
void menuPesquisar(t_arvore *raiz);
void menuEsvaziar(t_arvore *raiz);
void menuExibir(t_arvore *raiz);
void limparBuffer(void);

int main(void)
{
    t_arvore raiz = NULL;
    int opcao;

    do {
        printf("\n===== EDITOR DE ARVORE =====\n");
        printf("1 - INSERIR\n");
        printf("2 - REMOVER UM NO\n");
        printf("3 - PESQUISAR\n");
        printf("4 - ESVAZIAR A ARVORE\n");
        printf("5 - EXIBIR A ARVORE\n");
        printf("0 - SAIR\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                menuInserir(&raiz);
                break;
            case 2:
                menuRemover(&raiz);
                break;
            case 3:
                menuPesquisar(&raiz);
                break;
            case 4:
                menuEsvaziar(&raiz);
                break;
            case 5:
                menuExibir(&raiz);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    /* Garante que toda a memoria seja liberada ao final */
    esvaziar(&raiz);

    return 0;
}

/* Limpa o buffer de entrada (restos de \n, etc.) */
void limparBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Insere um novo registro na arvore */
void menuInserir(t_arvore *raiz)
{
    t_elemento novo;

    printf("\n--- INSERIR REGISTRO ---\n");
    printf("Codigo: ");
    scanf("%d", &novo.codigo);
    limparBuffer();

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    if (inserir(raiz, novo))
        printf("Registro inserido com sucesso!\n");
    else
        printf("Erro: codigo ja existe na arvore.\n");
}

/* Remove um registro da arvore */
void menuRemover(t_arvore *raiz)
{
    t_elemento chave;

    printf("\n--- REMOVER REGISTRO ---\n");
    printf("Codigo a remover: ");
    scanf("%d", &chave.codigo);
    limparBuffer();

    if (remover(raiz, chave))
        printf("Registro removido com sucesso!\n");
    else
        printf("Registro nao encontrado.\n");
}

/* Pesquisa um registro pelo codigo */
void menuPesquisar(t_arvore *raiz)
{
    t_elemento chave;
    t_no *resultado;

    printf("\n--- PESQUISAR REGISTRO ---\n");
    printf("Codigo a pesquisar: ");
    scanf("%d", &chave.codigo);
    limparBuffer();

    resultado = buscaABB(*raiz, chave);

    if (resultado != NULL)
        printf("Encontrado -> Codigo: %d | Nome: %s\n",
               resultado->dado.codigo, resultado->dado.nome);
    else
        printf("Registro nao encontrado.\n");
}

/* Esvazia toda a arvore */
void menuEsvaziar(t_arvore *raiz)
{
    esvaziar(raiz);
    printf("\nArvore esvaziada com sucesso!\n");
}

/* Submenu de exibicao da arvore */
void menuExibir(t_arvore *raiz)
{
    int op;

    if (isVazia(*raiz)) {
        printf("\nArvore vazia.\n");
        return;
    }

    printf("\n--- EXIBIR ARVORE ---\n");
    printf("1 - Pre-Ordem\n");
    printf("2 - In-Ordem\n");
    printf("3 - Pos-Ordem\n");
    printf("4 - Exibicao grafica\n");
    printf("Escolha: ");
    scanf("%d", &op);
    limparBuffer();

    switch (op) {
        case 1:
            printf("\n-- Pre-Ordem --\n");
            exibirPreOrdem(*raiz);
            break;
        case 2:
            printf("\n-- In-Ordem --\n");
            exibirInOrdem(*raiz);
            break;
        case 3:
            printf("\n-- Pos-Ordem --\n");
            exibirPosOrdem(*raiz);
            break;
        case 4:
            printf("\n-- Exibicao Grafica --\n");
            exibirGraficamente(*raiz, 0, 0, 10);
            break;
        default:
            printf("Opcao invalida.\n");
    }
}