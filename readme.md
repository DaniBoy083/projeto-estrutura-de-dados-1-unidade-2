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
typedef struct elementos {
    int codigo;
    char nome[100];
} t_elemento;
```

---

# Estrutura da Árvore

```c
typedef struct no {
    struct no *esq;
    t_elemento dado;
    struct no *dir;
} t_no;

typedef t_no* t_arvore;
```

---

# Organização dos Arquivos

| Arquivo | Conteúdo |
|---------|----------|
| `arvore.h` | Estruturas (`t_elemento`, `t_no`, `t_arvore`) e protótipos de todas as funções da ABB |
| `arvore.c` | Implementação das funções da ABB (inserir, remover, buscar, percursos, exibição) |
| `main.c` | Menu interativo e controle de fluxo do sistema (parte do Daniel) |

### Compilação

```bash
gcc main.c arvore.c -o programa
./programa
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
===== EDITOR DE ARVORE =====
1 - INSERIR
2 - REMOVER UM NO
3 - PESQUISAR
4 - ESVAZIAR A ARVORE
5 - EXIBIR A ARVORE
0 - SAIR
```

Ao escolher a opção **5 - EXIBIR A ARVORE**, um submenu é exibido:

```txt
--- EXIBIR ARVORE ---
1 - Pre-Ordem
2 - In-Ordem
3 - Pos-Ordem
4 - Exibicao grafica
```

---

# Divisão de Responsabilidades

A distribuição foi realizada de forma equilibrada.

## Daniel Costa Carvalho Martins
- Estrutura principal do projeto
- Menu interativo
- Controle de fluxo do sistema
- Integração entre módulos

**Status:** ✅ Concluído
- Implementado `main.c` com loop principal do menu (opções 0 a 5)
- Funções de fluxo separadas: `menuInserir`, `menuRemover`, `menuPesquisar`, `menuEsvaziar`, `menuExibir`
- Submenu de exibição com as 4 opções de percurso/visualização
- Tratamento básico de entrada inválida (`limparBuffer`)
- Liberação de memória da árvore ao encerrar o programa (`esvaziar`)
- Integração com as funções da ABB via `arvore.h`/`arvore.c`

## Carlos Eduardo Menezes Cavalcante
- Estruturas de dados da ABB
- Criação dos nós
- Inserção de registros
- Validação de dados

**Status:** Código legado adaptado (estrutura `t_elemento` ajustada com campo `codigo`; funções `criar`, `inserir`, `insereRaiz`, `insereEsquerda`, `insereDireita` e `compara` movidas para `arvore.c`). Validação adicional pendente de revisão por Carlos.

## Nelson Francisco Suassuna Neto
- Pesquisa de registros
- Percursos da árvore
- Exibição Pré-Ordem
- Exibição In-Ordem
- Exibição Pós-Ordem

**Status:** Código legado adaptado (`exibirPreOrdem`, `exibirInOrdem`, `exibirPosOrdem` em `arvore.c`, agora exibindo código e nome). `busca`/`buscaABB` integradas ao submenu de pesquisa.

## José Adrian Cosmo de Sousa
- Remoção de nós
- Implementação do sucessor
- Busca com nó pai
- Tratamento dos casos de remoção

**Status:** Código legado adaptado (`remover`, `buscaSetPai` em `arvore.c`, com pequena correção na inicialização da variável `pai`). Integrado ao menu (opção 2).

## Evelyn Vitória Dantas Silva do Nascimento
- Leitura de arquivos
- Esvaziamento da árvore
- Exibição gráfica
- Testes, documentação e validação final

**Status:** 
- `esvaziar` já integrada ao menu (opção 4) e à finalização do programa
- `exibirGraficamente` adaptada para terminal padrão (sem `gotoxy`/`conio.h`), usando recuo por nível — **pendente revisão de Evelyn**
- **Pendente:** implementação da leitura de arquivo texto (item 6 do menu) e função de carregamento de registros para a árvore

---

# Pendências Gerais

- [ ] Implementar opção **6 - Carregar dados de arquivo texto** (Evelyn)
- [ ] Revisar exibição gráfica adaptada (Evelyn)
- [ ] Revisar validações de inserção (Carlos)
- [ ] Testes finais de todos os percursos e casos de remoção
- [ ] Gravação do vídeo demonstrativo

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

- Código fonte (`arvore.h`, `arvore.c`, `main.c`)
- README
- Arquivo de entrada
- Vídeo demonstrativo

Disciplina: Estrutura de Dados I
Professor: Walace Bonfim