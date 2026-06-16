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

> **Importante:** o `dados.txt` deve estar na mesma pasta onde o `programa`/`programa.exe` é executado (raiz do projeto), pois a leitura usa caminho relativo.

---

# Exemplo de Arquivo de Entrada (`dados.txt`)

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
6 - CARREGAR DADOS DE ARQUIVO
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
- Implementado `main.c` com loop principal do menu (opções 0 a 6)
- Funções de fluxo separadas: `menuInserir`, `menuRemover`, `menuPesquisar`, `menuEsvaziar`, `menuExibir`
- Submenu de exibição com as 4 opções de percurso/visualização
- Tratamento básico de entrada inválida (`limparBuffer`)
- Liberação de memória da árvore ao encerrar o programa (`esvaziar`)
- Integração de todos os módulos (`arvore.h/.c`, `arquivo.h/.c`) no `main.c`
- Adaptação temporária do código legado de `criar`, `inserir`, `compara`, `remover`, `buscaSetPai` em `arvore.c`, para manter o sistema funcional enquanto Carlos e Adrian não entregam suas partes

## Carlos Eduardo Menezes Cavalcante
- Estruturas de dados da ABB
- Criação dos nós
- Inserção de registros
- Validação de dados

**Status:** ✅ Concluído (em `arvore.c`/`arvore.h`)
- Adaptação do código legado concluída e revisada
- Funções `criar`, `inserir`, `insereRaiz`, `insereEsquerda`, `insereDireita` e `compara` totalmente integradas, refatoradas e testadas
- Validação de entrada do usuário implementada
- Checagem de campos antes da inserção implementada

## Nelson Francisco Suassuna Neto
- Pesquisa de registros
- Percursos da árvore
- Exibição Pré-Ordem
- Exibição In-Ordem
- Exibição Pós-Ordem

**Status:** ✅ Concluído (em `arvore.c`/`arvore.h`)
- `exibirPreOrdem`, `exibirInOrdem`, `exibirPosOrdem` exibindo código e nome de cada registro
- `busca`/`buscaABB` integradas ao submenu de pesquisa (opção 3 do menu principal)

## José Adrian Cosmo de Sousa
- Remoção de nós
- Implementação do sucessor
- Busca com nó pai
- Tratamento dos casos de remoção

**Status:** ✅ Concluído
- `remover` e `buscaSetPai` revisadas e reescritas em `arvore.c`
- Tratamento correto dos 3 casos de remoção (nó sem filhos, com um filho, com dois filhos/sucessor)
- Busca com nó pai validada e integrada ao fluxo de remoção

## Evelyn Vitória Dantas Silva do Nascimento
- Leitura de arquivos
- Esvaziamento da árvore
- Exibição gráfica
- Testes, documentação e validação final

**Status:** ✅ Concluído
- `lerArquivo` (em `arquivo.c`/`arquivo.h`) lê o `dados.txt` no formato `codigo;nome`, faz o parsing de cada linha e insere os registros na árvore — integrada ao menu (opção 6)
- `esvaziar` percorre a árvore recursivamente liberando cada nó, integrada ao menu (opção 4) e chamada automaticamente ao encerrar o programa (opção 0)
- `exibirGraficamente` adaptada para terminal padrão (sem `gotoxy`/`conio.h`), usando recuo proporcional ao nível de cada nó — integrada ao submenu de exibição (opção 5 → 4)
- Validação final do fluxo completo do sistema (testes de ponta a ponta)

---

# Testes Realizados

- ✅ Inserção manual de registros
- ✅ Carregamento via `dados.txt` (5 registros: Notebook, Monitor, Teclado, Mouse, Impressora)
- ✅ Pesquisa por código (encontrado e não encontrado)
- ✅ Remoção (casos sem filhos, um filho e dois filhos)
- ✅ Percursos Pré-Ordem, In-Ordem e Pós-Ordem
- ✅ Esvaziamento da árvore
- ✅ Exibição gráfica

---

# Pendências

- [ ] Carlos: revisar/reescrever `criar`, `inserir`, `insereRaiz`, `insereEsquerda`, `insereDireita`, `compara` e validações de dados
- [ ] Gravação do vídeo demonstrativo

---

# Entrega

O projeto será entregido contendo:

- Código fonte (`src/arvore.h`, `src/arvore.c`, `src/arquivo.h`, `src/arquivo.c`, `src/main.c`)
- README
- Arquivo de entrada (`dados.txt`)
- Vídeo demonstrativo

Disciplina: Estrutura de Dados I
Professor: Walace Bonfim