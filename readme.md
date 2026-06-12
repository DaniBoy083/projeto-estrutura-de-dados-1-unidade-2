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
0. Encerrar sistema

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
| `src/arvore.h` | Estruturas (`t_elemento`, `t_no`, `t_arvore`) e protótipos de todas as funções da ABB |
| `src/arvore.c` | Implementação das funções da ABB (inserir, remover, buscar, percursos, exibição) |
| `src/arquivo.h` | Protótipo da função de leitura de arquivo |
| `src/arquivo.c` | Implementação da leitura de `dados.txt` e inserção dos registros na árvore |
| `src/main.c` | Menu interativo e controle de fluxo do sistema |
| `dados.txt` | Arquivo de entrada com os registros (na raiz do projeto) |

### Compilação

```bash
gcc src/main.c src/arvore.c src/arquivo.c -o programa
./programa
```

> **Importante:** o `dados.txt` deve estar na mesma pasta onde o `programa`/`programa.exe` é executado (raiz do projeto), pois a leitura usa caminho