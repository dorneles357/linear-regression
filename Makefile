# Nome do executável final
TARGET = meu_programa

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

# Nova regra para compilar e rodar os testes
test: $(SRC_DIR)/linear_regression.c tests/test_regression.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/test_runner -lm
	./$(BIN_DIR)/test_runner

# Limpa os arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Limpeza concluída."

# Atalho para rodar o programa
run: all
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run