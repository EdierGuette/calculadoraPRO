#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdarg.h>
#include "tipos.h"

// Códigos de colores ANSI
#define COLOR_ROJO "\033[1;31m"
#define COLOR_VERDE "\033[1;32m"
#define COLOR_AMARILLO "\033[1;33m"
#define COLOR_AZUL "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[0m"

// Funciones de interfaz
void limpiar_pantalla(void);
void pausar_pantalla(void);
void imprimir_titulo(const char *titulo);
void imprimir_color(const char *texto, const char *color);
void imprimir_color_f(const char *formato, const char *color, ...);

// Funciones de entrada robustas
int leer_entero(const char *mensaje, int *valor);
int leer_double(const char *mensaje, double *valor);
void limpiar_buffer(void);

// Sistema de logs
void registrar_log(const char *operacion, const char *resultado);

#endif