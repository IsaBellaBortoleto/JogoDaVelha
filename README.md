# Jogo da Velha - Crossbots

Este projeto implementa um jogo da velha utilizando o algoritmo Minimax.

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador C++ (g++, clang++ ou MSVC)
- Make (GNU Make ou compatível)

### Compilação Rápida
```bash
# Compilar
make

# Compilar e executar
make build-run

# Apenas executar (após compilar)
make run
```

### Outras Opções
```bash
make debug      # Versão debug
make release    # Versão otimizada
make clean      # Limpar arquivos
make help       # Ver todas as opções
```

## 📁 Estrutura do Projeto

```
crossbots/
├── src/           # Código fonte (.cpp)
├── include/       # Cabeçalhos (.h)
├── bin/           # Executáveis
├── obj/           # Arquivos objeto
├── doc/           # Documentação
└── Makefile       # Build automatizado
```

## 🎮 Como Jogar

1. Execute o programa
2. Digite a linha (1-3) e coluna (1-3) da sua jogada
3. O BOT (X) jogará automaticamente
4. Continue até haver um vencedor ou empate

## 📚 Bibliotecas Personalizadas

- **board.h/cpp**: Gerenciamento do tabuleiro
- **minimax.h/cpp**: Inteligência artificial
- **ui.h/cpp**: Interface do usuário

## 📖 Documentação Completa

Consulte `doc/documentacao.md` para documentação técnica detalhada incluindo:
- Arquitetura do sistema
- Explicação do algoritmo Minimax
- Manual de compilação
- Guia do desenvolvedor

## 👨‍💻 Desenvolvimento

Este projeto foi desenvolvido como parte do curso de Engenharia de Software na UTFPR, demonstrando:
- Arquitetura modular em C++
- Ferramentas de build automatizado
- Documentação técnica completa

 ## 🎯 Características

- **Interface Colorida**: Formatação visual com cores no terminal
- **Arquitetura Modular**: Código organizado em bibliotecas personalizadas
- **Multiplataforma**: Compatível com Windows, Linux e macOS
- **Build Automatizado**: Makefile completo com múltiplas opções

---

**UTFPR | 2025**
