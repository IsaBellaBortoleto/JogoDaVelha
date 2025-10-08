# JOGO DA VELHA  - DOCUMENTAÇÃO TÉCNICA

**Projeto:** Crossbots - Jogo da Velha 
**Autor:** UTFPR
**Data:** Setembro 2025  
**Linguagem:** C++11  

---

## ÍNDICE

1. [Visão Geral](#visão-geral)
2. [Arquitetura do Sistema](#arquitetura-do-sistema)
3. [Bibliotecas Personalizadas](#bibliotecas-personalizadas)
4. [Algoritmo Minimax](#algoritmo-minimax)
5. [Compilação e Execução](#compilação-e-execução)
6. [Estrutura de Arquivos](#estrutura-de-arquivos)
7. [Manual de Uso](#manual-de-uso)
8. [Considerações Técnicas](#considerações-técnicas)

---

## VISÃO GERAL


### Características Principais


### Objetivos do Projeto


---

## ARQUITETURA DO SISTEMA



### Princípios Utilizados


## BIBLIOTECAS PERSONALIZADAS

### 1. Biblioteca Board (board.h/board.cpp)

**Responsabilidade**: Gerenciamento do estado do tabuleiro

**Principais Funções**:


**Estruturas de Dados**:


### 2. Biblioteca Minimax (minimax.h/minimax.cpp)







## ALGORITMO MINIMAX

### Fundamentos Teóricos


### Funcionamento

1. **Recursão**: Explora todas as jogadas possíveis até o fim do jogo
2. **Maximização**: BOT tenta maximizar sua pontuação
3. **Minimização**: Jogador humano tenta minimizar a pontuação do BOT
4. **Backtracking**: Retorna a melhor pontuação encontrada

### Pontuação

```cpp
+10: BOT venceu
-10: Jogador venceu  
  0: Empate
```

### Otimização por Profundidade



## COMPILAÇÃO E EXECUÇÃO

### Pré-requisitos

- Compilador C++ compatível com C++11 (g++, clang++, MSVC)
- Make (GNU Make ou compatível)
- Sistema operacional: Windows, Linux ou macOS

### Comandos do Makefile

```bash
# Compilação básica
make

# Compilação e execução
make build-run

# Versão debug (com símbolos de depuração)
make debug

# Versão otimizada para produção  
make release

# Executar após compilação
make run

# Limpar arquivos compilados
make clean

# Recompilar do zero
make rebuild

# Verificar sintaxe sem compilar
make check

# Contar linhas de código
make count

# Mostrar informações do projeto
make info

# Mostrar ajuda
make help
```

### Processo de Compilação

1. **Criação de Diretórios**: obj/ e bin/ são criados automaticamente
2. **Compilação Individual**: Cada .cpp é compilado para .o
3. **Linkagem**: Todos os .o são linkados no executável final
4. **Otimização**: Flags de compilação aplicadas conforme o modo

### Flags de Compilação

```makefile
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
```

- `-Wall -Wextra`: Habilita warnings importantes
- `-std=c++11`: Utiliza padrão C++11
- `-O2`: Otimização de performance
- `-g`: Símbolos de debug (modo debug)

---

## ESTRUTURA DE ARQUIVOS

```
crossbots/
├── src/                    # Código fonte
│   ├── main.cpp           # Arquivo principal
│   ├── board.cpp          # Implementação do tabuleiro
│   ├── minimax.cpp        # Implementação da IA
│   └── ui.cpp             # Implementação da interface
├── include/               # Cabeçalhos
│   ├── board.h            # Interface do tabuleiro
│   ├── minimax.h          # Interface da IA
│   └── ui.h               # Interface do usuário
├── bin/                   # Executáveis (gerado)
│   └── jogo_da_velha.exe
├── obj/                   # Arquivos objeto (gerado)
│   ├── main.o
│   ├── board.o
│   ├── minimax.o
│   └── ui.o
├── doc/                   # Documentação
│   └── documentacao.md
├── Makefile              # Arquivo de build
├── README.md             # Instruções básicas
└── velha.cpp             # Versão original (legacy)
```

### Descrição dos Diretórios

- **src/**: Contém todos os arquivos de implementação (.cpp)
- **include/**: Contém todos os cabeçalhos (.h) 
- **bin/**: Diretório para executáveis compilados
- **obj/**: Diretório para arquivos objeto intermediários
- **doc/**: Documentação do projeto

---

## MANUAL DE USO

### Execução do Programa

1. **Compilar o projeto**:
   ```bash
   make
   ```

2. **Executar o jogo**:
   ```bash
   make run
   ```
   ou
   ```bash
   ./bin/jogo_da_velha
   ```

### Interface do Jogo

1. **Tela de Boas-vindas**: Apresenta o jogo e as regras
2. **Tabuleiro**: Exibido com cores diferenciadas
   - 🔴 X: BOT (vermelho)
   - 🟠 O: Jogador (laranja)
3. **Entrada**: Digite linha (1-3) e coluna (1-3)
4. **Resultado**: Mostra vencedor ou empate

### Exemplo de Jogada

```
É a sua vez! Insira a linha (1-3): 2
Agora insira a coluna (1-3): 2
Jogador marcou (2,2):

-------------
|   |   |   |
-------------
|   | O |   |
-------------
|   |   |   |
-------------

BOT marcou (1,1):

-------------
| X |   |   |
-------------
|   | O |   |
-------------
|   |   |   |
-------------
```

### Validações

- **Posição válida**: Linha e coluna entre 1-3
- **Posição vazia**: Não permite sobrescrever jogadas
- **Entrada inválida**: Trata caracteres não numéricos
- **Jogar novamente**: Opção ao final de cada partida

---

## CONSIDERAÇÕES TÉCNICAS

### Complexidade Algorítmica

**Minimax no Jogo da Velha**:
- **Complexidade Temporal**: O(3^n) onde n é o número de posições vazias
- **Complexidade Espacial**: O(n) para a pilha de recursão
- **Estados Possíveis**: Máximo de 9! = 362.880 estados
- **Performance**: Instantânea devido ao espaço de busca pequeno

### Otimizações Implementadas



### Possíveis Melhorias



### Portabilidade

**Compatibilidade**:
- ✅ Windows (MSVC, MinGW)
- ✅ Linux (GCC, Clang)
- ✅ macOS (Clang, GCC)

**Dependências**:
- Padrão C++11 ou superior
- Biblioteca padrão C++ (iostream, string, limits, algorithm)



## CONCLUSÃO

Este projeto demonstra a implementação completa de um jogo da velha com IA utilizando práticas modernas de desenvolvimento em C++. A arquitetura modular facilita manutenção e extensão, enquanto o algoritmo Minimax garante uma IA imbatível.

### Aprendizados

1. **Algoritmos de IA**: Implementação prática do Minimax
2. **Engenharia de Software**: Arquitetura modular e separação de responsabilidades
3. **Ferramentas de Build**: Criação de Makefiles complexos
4. **Interface de Usuário**: Formatação visual com códigos ANSI

### Aplicações Futuras

- Extensão para outros jogos (Connect 4, Reversi)
- Interface gráfica (SDL, SFML)
- Multiplayer em rede
- Diferentes níveis de dificuldade

---

**© 2025 UTFPR - Universidade Tecnológica Federal do Paraná**  
**Projeto Crossbots - 5º Período**
