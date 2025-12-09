#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include "utilidades.h"

// Imprime texto con color
void imprimir_color(const char *texto, const char *color)
{
    printf("%s%s%s", color, texto, COLOR_RESET);
}

// Imprime texto con color y formato
void imprimir_color_f(const char *formato, const char *color, ...)
{
    va_list args;
    printf("%s", color);
    va_start(args, color);
    vprintf(formato, args);
    va_end(args);
    printf("%s", COLOR_RESET);
}


// Limpia la pantalla según el sistema operativo
void limpiar_pantalla(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa la ejecución hasta que se presione ENTER
void pausar_pantalla(void)
{
    printf("\n");
    imprimir_color("Presiona ENTER para continuar...", COLOR_AMARILLO);
    limpiar_buffer(); // Ahora usa limpiar_buffer internamente
}

// Imprime un título con formato (sin caracteres especiales)
void imprimir_titulo(const char *titulo)
{
    printf("\n");
    for (int i = 0; i < 50; i++)
        printf("=");
    printf("\n");

    // Centrar título
    int longitud = strlen(titulo);
    int espacios = (50 - longitud) / 2;
    if (espacios > 0)
    {
        for (int i = 0; i < espacios; i++)
            printf(" ");
    }

    imprimir_color(titulo, COLOR_VERDE);
    printf("\n");

    for (int i = 0; i < 50; i++)
        printf("=");
    printf("\n\n");
}

// Registra una operación en el archivo de logs
void registrar_log(const char *operacion, const char *resultado)
{
    FILE *archivo_log = fopen("logs/calculadora.log", "a");
    if (!archivo_log)
    {

// Intentar crear el directorio logs si no existe
#ifdef _WIN32
        system("mkdir logs 2>nul");
#else
        system("mkdir -p logs 2>/dev/null");
#endif

        archivo_log = fopen("logs/calculadora.log", "a");
        if (!archivo_log)
        {
            return; // No se pudo crear el log
        }
    }

    // Obtener fecha y hora actual
    time_t ahora = time(NULL);
    struct tm *tiempo_local = localtime(&ahora);
    char fecha_hora[100];
    strftime(fecha_hora, sizeof(fecha_hora), "%Y-%m-%d %H:%M:%S", tiempo_local);

    // Escribir en el log
    fprintf(archivo_log, "[%s] %s: %s\n", fecha_hora, operacion, resultado);
    fclose(archivo_log);
}

// Limpia el buffer de entrada estándar
void limpiar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Lee un número entero con validación y limpieza automática
// Devuelve: 1 si éxito, 0 si error
int leer_entero(const char *mensaje, int *valor) {
    if (mensaje != NULL && strlen(mensaje) > 0) {
        printf("%s", mensaje);
    }
    
    char input[50];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0; // Error de lectura
    }
    
    // Eliminar salto de línea
    input[strcspn(input, "\n")] = 0;
    
    // Verificar si está vacío
    if (strlen(input) == 0) {
        return 0;
    }
    
    char *endptr;
    long temp = strtol(input, &endptr, 10);
    
    // Verificar si la conversión fue exitosa
    if (*endptr != '\0') {
        return 0; // Caracteres no numéricos
    }
    
    *valor = (int)temp;
    return 1; // Éxito
}

// Lee un número double con validación y limpieza automática
int leer_double(const char *mensaje, double *valor)
{
    printf("%s", mensaje);

    char input[50];
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        return 0; // Error de lectura
    }

    // Verificar si es solo Enter (vacío)
    if (input[0] == '\n')
    {
        return 0;
    }

    char *endptr;
    *valor = strtod(input, &endptr);

    // Verificar si la conversión fue exitosa y no hay caracteres extra
    if (*endptr != '\n' && *endptr != '\0')
    {
        return 0; // Caracteres no numéricos
    }

    return 1; // Éxito
}