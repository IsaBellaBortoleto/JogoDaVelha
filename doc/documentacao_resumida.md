# JOGO DA VELHA - DOCUMENTAÇÃO TÉCNICA

**Projeto:** Crossbots - Jogo da Velha
**Autor:** 026
**Data:** Outubro 2025
**Linguagem:** C++11

---

## ÍNDICE

1.  [Visão Geral](#visão-geral)
2.  [Arquitetura do Sistema](#arquitetura-do-sistema)
3.  [Algoritmo Minimax](#algoritmo-minimax)
4.  [Compilação e Execução](#compilação-e-execução)
5.  [Manual de Uso](#manual-de-uso)
6.  [Considerações Técnicas](#considerações-técnicas)
7. [Referências](#referências)

---

## VISÃO GERAL

Este documento apresenta a solução para o desafio "Jogo da Velha", proposto no processo seletivo da equipe Crossbots 2025.2. O projeto consiste em uma aplicação em C++ que implementa o clássico Jogo da Velha, onde um jogador humano enfrenta um bot controlado por inteligência artificial.

### Características Principais

* **Modo de Jogo**: Jogador vs. Computador (Bot).
* **Inteligência Artificial**: O bot utiliza o algoritmo **Minimax** para calcular a jogada ótima, tornando-o um adversário imbatível.
* **Interface**: A interação ocorre via terminal (console), com um tabuleiro visualmente claro e comandos intuitivos.
* **Paradigma**: Desenvolvido com os princípios da Programação Orientada a Objetos (OOP) para garantir um código modular, coeso e de baixo acoplamento.
* **Portabilidade**: O código é compatível com os principais sistemas operacionais (Windows, Linux, macOS) e compiladores C++.

### Objetivos do Projeto

* Desenvolver uma implementação funcional e robusta do Jogo da Velha.
* Aplicar o algoritmo Minimax para criar uma IA desafiadora.
* Utilizar boas práticas de engenharia de software, como a separação de responsabilidades e o uso de um sistema de build automatizado (`Makefile`).
* Criar uma documentação técnica clara e abrangente do projeto.

---

## ARQUITETURA DO SISTEMA

A arquitetura do projeto foi planejada para ser modular e extensível, separando as responsabilidades em diferentes componentes lógicos.

### Princípios Utilizados

O projeto segue o paradigma da **Programação Orientada a Objetos (OOP)**. As principais vantagens dessa abordagem foram:
* **Coesão**: Agrupar funcionalidades relacionadas em classes específicas (ex: `Board` para o tabuleiro, `Bot` para a IA).
* **Baixo Acoplamento**: Reduzir a dependência entre os módulos, facilitando a manutenção e a reutilização de código.
* **Abstração**: Ocultar a complexidade interna, expondo apenas interfaces simples para a interação entre os componentes.

### Diagrama de Classes

O diagrama de classes abaixo ilustra a relação entre as principais entidades do sistema. Foi modelado utilizando a ferramenta Mermaid.

<img src="https://github.com/IsaBellaBortoleto/JogoDaVelha/blob/main/Diagramas/diagrama%20de%20classes.png">
*Figura 1: Diagrama de classes do sistema.*

---

## ALGORITMO MINIMAX

### Fundamentos Teóricos

O Minimax é um algoritmo de busca adversária usado em jogos de dois jogadores com informação perfeita. Seu objetivo é minimizar a perda máxima possível (cenário do pior caso). No contexto do Jogo da Velha, ele maximiza a chance de vitória do bot enquanto assume que o jogador humano sempre fará a melhor jogada para si.

### Funcionamento

O algoritmo funciona explorando recursivamente todas as jogadas possíveis até o final do jogo através de uma busca em profundidade (Depth-First Search - DFS).

1.  **Recursão**: A função `minimax` explora cada galho da árvore de possibilidades de jogo.
2.  **Maximização (Turno do Bot)**: O bot (jogador MAX) escolhe a jogada que leva ao estado com a maior pontuação.
3.  **Minimização (Turno do Humano)**: O bot assume que o jogador (jogador MIN) escolherá a jogada que leva ao estado com a menor pontuação.
4.  **Backtracking**: As pontuações dos estados finais (folhas da árvore) são propagadas de volta para cima, permitindo que a decisão seja tomada na raiz da busca.
<img src="https://github.com/IsaBellaBortoleto/JogoDaVelha/blob/main/imagens/4.png">

*Figura 2: Demonstração do fluxo do algoritmo Minimax. Fonte: [1]*

### Pontuação

Para avaliar os estados finais do jogo, o algoritmo atribui a seguinte pontuação:
```cpp
+10: BOT venceu
-10: Jogador venceu
  0: Empate
```

---

## COMPILAÇÃO E EXECUÇÃO

### Pré-requisitos

* Compilador C++ compatível com C++11 (g++, clang++, MSVC)
* Make (GNU Make ou compatível)
* Sistema operacional: Windows, Linux ou macOS

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

1.  **Criação de Diretórios**: `obj/` e `bin/` são criados automaticamente se não existirem.
2.  **Compilação Individual**: Cada arquivo `.cpp` em `src/` é compilado para um arquivo objeto `.o` em `obj/`.
3.  **Linkagem**: Todos os arquivos objeto são linkados para gerar o executável final em `bin/`.
4.  **Otimização**: Flags de compilação são aplicadas conforme o alvo (`debug` ou `release`).

---



### Descrição dos Diretórios

* **src/**: Contém todos os arquivos de implementação (`.cpp`).
* **include/**: Contém todos os arquivos de cabeçalho (`.h`).
* **obj/**: Diretório para arquivos objeto intermediários gerados durante a compilação.
* **doc/**: Armazena a documentação do projeto.

---

## MANUAL DE USO

### Execução do Programa

1.  **Compilar o projeto**:
    ```bash
    make
    ```

2.  **Executar o jogo**:
    ```bash
    make run
    ```
    ou diretamente:
    ```bash
    ./bin/jogo_da_velha
    ```

### Interface do Jogo

1.  **Tela de Boas-vindas**: Apresenta o jogo e suas regras.
2.  **Tabuleiro**: Exibido com cores para diferenciar os jogadores.
3.  **Entrada**: O jogador deve digitar a linha (1-3) e a coluna (1-3) para fazer sua jogada.
4.  **Resultado**: Ao final da partida, o programa exibe uma mensagem indicando o vencedor ou se houve empate.

### Exemplo de Partida
<img src="https://github.com/IsaBellaBortoleto/JogoDaVelha/blob/main/imagens/1.png">
*Figura 3: Tela inicial do jogo.*

<img src="https://github.com/IsaBellaBortoleto/JogoDaVelha/blob/main/imagens/2.png">
*Figura 4: Partida em andamento após algumas jogadas.*

<img src="https://github.com/IsaBellaBortoleto/JogoDaVelha/blob/main/imagens/3.png">
*Figura 5: Tela de finalização com a vitória do bot.*

### Validações

* **Posição válida**: O sistema verifica se a linha e a coluna estão no intervalo [1, 3].
* **Posição vazia**: Impede que uma jogada seja feita em uma casa já ocupada.
* **Entrada inválida**: O programa trata entradas não numéricas, solicitando ao jogador que tente novamente.
* **Jogar novamente**: Ao final de cada partida, o usuário tem a opção de iniciar um novo jogo.

---

## CONSIDERAÇÕES TÉCNICAS

### Complexidade Algorítmica

**Minimax no Jogo da Velha**:
* **Complexidade Temporal**: $O(b^m)$, onde `b` é o fator de ramificação (número de jogadas possíveis) e `m` é a profundidade máxima da árvore. No Jogo da Velha, o número de estados é finito e pequeno (menos de 362.880), tornando o desempenho do algoritmo praticamente instantâneo.
* **Complexidade Espacial**: $O(m)$ para armazenar a pilha de recursão.

### Portabilidade

**Compatibilidade**:
* ✅ Windows (MSVC, MinGW)
* ✅ Linux (GCC, Clang)
* ✅ macOS (Clang, GCC)

**Dependências**:
* O projeto depende apenas da **biblioteca padrão do C++11 ou superior**, não necessitando de bibliotecas externas para compilação ou execução.


---

## REFERÊNCIAS

[1] Hassaan, M. (2025). *Minimax Algorithm in Tic-Tac-Toe*.

---

**© 2025 UTFPR - Universidade Tecnológica Federal do Paraná**
**Projeto Crossbots**
