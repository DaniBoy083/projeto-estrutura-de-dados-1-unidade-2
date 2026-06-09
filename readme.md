
# Mini Projeto - Árvore Binária de Busca (ABB)

## Estrutura de Dados I
**Professor:** Walace Bonfim

---

## Integrantes (Desenvolvedores)

| Nome | RGM |
|------|------|
| Daniel Costa Carvalho Martins | 37196201 |
| Carlos Eduardo Menezes Cavalcante | 41602102 |
| Nelson Francisco Suassuna Neto | 42785651 |
| José Adrian Cosmo de Sousa | 43086365 |
| Evelyn Vitória Dantas Silva do Nascimento | 43627307 |

---

# Descrição do Projeto

O sistema implementa uma Árvore Binária de Busca (ABB) em linguagem C.

O conteúdo da árvore será composto por registros personalizados informados pelo usuário ou carregados de um arquivo de entrada.

Cada registro armazenado possui:

- Código (chave de pesquisa)
- Nome
- Informações adicionais definidas pela equipe

Os dados dos integrantes acima representam apenas os desenvolvedores do projeto e não fazem parte dos dados armazenados na árvore.

---

# Funcionalidades

1. Inserir registro
2. Remover registro
3. Pesquisar registro
4. Esvaziar árvore
5. Exibir árvore
   - Pré-Ordem
   - In-Ordem
   - Pós-Ordem
   - Exibição gráfica
6. Carregar dados de arquivo texto
7. Encerrar sistema

---

# Estrutura do Registro

```c
typedef struct {
    int codigo;
    char nome[100];
} t_elemento;
```

---

# Estrutura da Árvore

```c
typedef struct no {
    t_elemento dado;
    struct no *esq;
    struct no *dir;
} t_no;

typedef t_no* t_arvore;
```

---

# Exemplo de Arquivo de Entrada

```txt
1001;Notebook
1002;Monitor
1003;Teclado
1004;Mouse
1005;Impressora
```

Os registros podem ser alterados livremente pelo usuário.

---

# Menu do Sistema

```txt
EDITOR DE ÁRVORE

1 - INSERIR
2 - REMOVER UM NÓ
3 - PESQUISAR
4 - ESVAZIAR A ÁRVORE
5 - EXIBIR A ÁRVORE
0 - SAIR
```

---

# Divisão de Responsabilidades

A distribuição foi realizada de forma equilibrada.

## Daniel Costa Carvalho Martins
- Estrutura principal do projeto
- Menu interativo
- Controle de fluxo do sistema
- Integração entre módulos

## Carlos Eduardo Menezes Cavalcante
- Estruturas de dados da ABB
- Criação dos nós
- Inserção de registros
- Validação de dados

## Nelson Francisco Suassuna Neto
- Pesquisa de registros
- Percursos da árvore
- Exibição Pré-Ordem
- Exibição In-Ordem
- Exibição Pós-Ordem

## José Adrian Cosmo de Sousa
- Remoção de nós
- Implementação do sucessor
- Busca com nó pai
- Tratamento dos casos de remoção

## Evelyn Vitória Dantas Silva do Nascimento
- Leitura de arquivos
- Esvaziamento da árvore
- Exibição gráfica
- Testes, documentação e validação final

---

# Testes

- Inserção
- Busca
- Remoção
- Percursos
- Leitura de arquivo
- Esvaziamento da árvore
- Exibição gráfica

---

# Entrega

O projeto será entregue contendo:

- Código fonte
- README
- Arquivo de entrada
- Vídeo demonstrativo

Disciplina: Estrutura de Dados I
Professor: Walace Bonfim
