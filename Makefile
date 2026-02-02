# Nome do executável final
TARGET = linear-regression

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS = 

# Pastas
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Encontra todos os arquivos .c na pasta src
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Converte a lista de .c para .o na pasta obj
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Encontra todos os arquivos de teste na pasta tests
TEST_SRCS = $(wildcard tests/*.c)
# Cria uma lista de executáveis de teste na pasta bin
TEST_BINS = $(patsubst tests/%.c, $(BIN_DIR)/%, $(TEST_SRCS))

# Regra principal (a primeira que o 'make' executa)
all: $(BIN_DIR)/$(TARGET)

# Regra para criar o executável
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "\033[0;32m✓ Compilação concluída: $@\033[0m"

# Regra para compilar cada arquivo .c em um .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para rodar TODOS os testes
test: all $(TEST_BINS)
	@echo "\033[0;34m--- Rodando Testes ---\033[0m"
	@for test in $(TEST_BINS); do ./$$test; done

# Filtra o arquivo main da lista de objetos para evitar conflito de 'main'
OBJS_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

# Regra para compilar cada arquivo de teste individualmente
$(BIN_DIR)/%: tests/%.c $(OBJS_NO_MAIN)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(OBJS_NO_MAIN) -o $@ -lm
	@echo "\033[0;32m✓ Teste compilado sem conflitos: $@\033[0m"

# Limpa os arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Limpeza concluída."

# Atalho para rodar o programa
run: all
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run