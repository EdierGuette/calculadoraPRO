# ============================================
# CONFIGURACION DE COMPILACION
# ============================================

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -Iapp/src/include -g
LDFLAGS = -lm

# Colores ANSI para mensajes
VERDE = \033[1;32m
ROJO = \033[1;31m
AMARILLO = \033[1;33m
AZUL = \033[1;34m
RESET = \033[0m

# Directorios
SRC_DIR = app/src
INC_DIR = app/src/include
BUILD_DIR = build
BIN_DIR = .
DATA_DIR = data
LOG_DIR = logs

# Archivos fuente y objeto
FUENTES = $(wildcard $(SRC_DIR)/*.c) app/main.c
OBJETOS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c)) \
          $(BUILD_DIR)/main.o

# Nombre del ejecutable
EJECUTABLE = calculadora_pro

# ============================================
# REGLAS PRINCIPALES
# ============================================

.PHONY: all clean run install debug help

# Compilacion principal
all: directorios $(EJECUTABLE)
	@printf "\n$(VERDE)=========================================\n"
	@printf "   COMPILACION EXITOSA \n"
	@printf "   Ejecutable: $(EJECUTABLE)\n"
	@printf "=========================================\n$(RESET)"

# Crear directorios necesarios
directorios:
	@mkdir -p $(BUILD_DIR) $(DATA_DIR) $(LOG_DIR)

# Enlazar ejecutable
$(EJECUTABLE): $(OBJETOS)
	@printf "$(AZUL)Enlazando ejecutable...$(RESET)\n"
	@$(CC) $(OBJETOS) -o $@ $(LDFLAGS)

# Compilar archivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(AZUL)Compilando $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: app/main.c
	@printf "$(AZUL)Compilando main.c...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

# Ejecutar programa
run: all
	@printf "\n$(AMARILLO)Ejecutando programa...$(RESET)\n\n"
	@./$(EJECUTABLE)

# Limpiar archivos compilados
clean:
	@printf "$(ROJO)Limpiando archivos...$(RESET)\n"
	@rm -rf $(BUILD_DIR) $(EJECUTABLE) *.tmp
	@printf "$(VERDE) Limpieza completada$(RESET)\n"

# Instalar dependencias y configurar
install: directorios
	@printf "$(VERDE)Configurando entorno...$(RESET)\n"
	@printf "$(VERDE) Entorno configurado$(RESET)\n"

# Compilar con informacion de depuracion
debug: CFLAGS += -DDEBUG -O0
debug: clean all

# Mostrar ayuda
help:
	@printf "$(AZUL)=== OPCIONES DISPONIBLES ===$(RESET)\n"
	@printf "$(VERDE)make all$(RESET)     - Compilar proyecto completo\n"
	@printf "$(VERDE)make run$(RESET)     - Compilar y ejecutar\n"
	@printf "$(VERDE)make clean$(RESET)   - Limpiar archivos compilados\n"
	@printf "$(VERDE)make install$(RESET) - Configurar entorno\n"
	@printf "$(VERDE)make debug$(RESET)   - Compilar con depuracion\n"
	@printf "$(VERDE)make help$(RESET)    - Mostrar esta ayuda\n"