# Makefile para o Jogo da Velha com IA
# Autor: Crossbots Project
# Data: 2025

# Configurações do compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
DEBUGFLAGS = -g -DDEBUG

# Diretórios
SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

# Nome do executável
TARGET = $(BINDIR)/jogo_da_velha

# Arquivos fonte e objeto
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Incluir diretório de headers
INCLUDES = -I$(INCDIR)

# Regra padrão
all: directories $(TARGET)

# Criar diretórios necessários
directories:
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	@if not exist "$(BINDIR)" mkdir "$(BINDIR)"

# Compilar o executável
$(TARGET): $(OBJECTS)
	@echo Linkando $(TARGET)...
	$(CXX) $(OBJECTS) -o $@
	@echo Compilacao concluida com sucesso!

# Compilar arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo Compilando $<...
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compilação em modo debug
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean directories $(TARGET)
	@echo Versao debug compilada com sucesso!

# Executar o programa
run: $(TARGET)
	@echo Executando o jogo...
	@$(TARGET)

# Compilar e executar
build-run: all run

# Compilar versão de release otimizada
release: CXXFLAGS += -DNDEBUG -O3
release: clean directories $(TARGET)
	@echo Versao release compilada com sucesso!

# Limpar arquivos compilados
clean:
	@echo Limpando arquivos compilados...
	@if exist "$(OBJDIR)" rmdir /s /q "$(OBJDIR)"
	@if exist "$(BINDIR)" rmdir /s /q "$(BINDIR)"
	@echo Limpeza concluida!

# Limpar e recompilar
rebuild: clean all

# Instalar (copiar para diretório do sistema)
install: $(TARGET)
	@echo Instalando o jogo...
	@copy "$(TARGET)" "C:\Program Files\JogoDaVelha\"
	@echo Instalacao concluida!

# Criar pacote de distribuição
package: release
	@echo Criando pacote de distribuicao...
	@if not exist "dist" mkdir "dist"
	@copy "$(TARGET)" "dist\"
	@copy "README.md" "dist\" 2>nul || echo README.md nao encontrado
	@copy "doc\*.pdf" "dist\" 2>nul || echo Documentacao nao encontrada
	@echo Pacote criado em dist/

# Verificar sintaxe sem compilar
check:
	@echo Verificando sintaxe dos arquivos...
	$(CXX) $(CXXFLAGS) $(INCLUDES) -fsyntax-only $(SOURCES)
	@echo Verificacao de sintaxe concluida!

# Contar linhas de código
count:
	@echo Contando linhas de codigo...
	@find $(SRCDIR) $(INCDIR) -name "*.cpp" -o -name "*.h" | xargs wc -l
	@echo Contagem concluida!

# Mostrar informações do projeto
info:
	@echo ======================================
	@echo    JOGO DA VELHA COM IA - CROSSBOTS
	@echo ======================================
	@echo Compilador: $(CXX)
	@echo Flags: $(CXXFLAGS)
	@echo Arquivos fonte: $(SOURCES)
	@echo Executavel: $(TARGET)
	@echo ======================================

# Ajuda
help:
	@echo Comandos disponiveis:
	@echo   all       - Compila o projeto (padrao)
	@echo   debug     - Compila versao debug
	@echo   release   - Compila versao otimizada
	@echo   run       - Executa o programa
	@echo   build-run - Compila e executa
	@echo   clean     - Remove arquivos compilados
	@echo   rebuild   - Limpa e recompila
	@echo   install   - Instala no sistema
	@echo   package   - Cria pacote de distribuicao
	@echo   check     - Verifica sintaxe
	@echo   count     - Conta linhas de codigo
	@echo   info      - Mostra informacoes do projeto
	@echo   help      - Mostra esta ajuda

# Declarar regras que não são arquivos
.PHONY: all debug release run build-run clean rebuild install package check count info help directories

# Evitar remoção de arquivos intermediários
.PRECIOUS: $(OBJDIR)/%.o