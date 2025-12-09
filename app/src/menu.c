#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "utilidades.h"

/**
 * Muestra el encabezado del programa
 */
void mostrar_encabezado(void)
{
    limpiar_pantalla();

    printf("\n");
    imprimir_color("==================================================\n", COLOR_CYAN);
    imprimir_color("            CALCULADORA PROFESIONAL              \n", COLOR_CYAN);
    imprimir_color("          Sistema Modular en C v2.0              \n", COLOR_CYAN);
    imprimir_color("==================================================\n", COLOR_CYAN);
    printf("\n");
}

/**
 * Muestra el menu principal (VERSIÓN SIMPLIFICADA)
 */
void mostrar_menu(OpcionMenu *opciones, int cantidad)
{
    int opcion = -1;

    while (opcion != 0)
    {
        mostrar_encabezado();

        imprimir_color("=== MENU PRINCIPAL ===\n", COLOR_VERDE);
        printf("\n");

        // Mostrar todas las opciones
        for (int i = 0; i < cantidad; i++)
        {
            if (i == 0)
            {
                printf("  ");
                imprimir_color("[0]", COLOR_ROJO);
                printf(" %s\n", opciones[i].nombre);
            }
            else
            {
                printf("  [%d] %s\n", i, opciones[i].nombre);
            }
        }

        printf("\n");
        for (int i = 0; i < 30; i++)
            printf("-");
        printf("\n");

        // Mostrar mensaje por separado
        printf("Seleccione una opcion (0-%d): ", cantidad - 1);

        // Llamar a leer_entero con cadena vacía
        if (!leer_entero("", &opcion))
        {
            printf("\n");
            imprimir_color("Error: Debe ingresar un numero\n", COLOR_ROJO);
            pausar_pantalla();
            continue;
        }

        // Validar rango
        if (opcion < 0 || opcion >= cantidad)
        {
            printf("\n");
            imprimir_color("Error: Opcion fuera de rango\n", COLOR_ROJO);
            printf("Las opciones validas son de 0 a %d\n", cantidad - 1);
            pausar_pantalla();
            continue;
        }

        // Ejecutar funcion seleccionada
        int resultado = opciones[opcion].funcion();

        // Si la funcion devuelve 1, significa que no se quiere salir
        if (opcion == 0 && resultado == 1)
        {
            opcion = -1; // Volver al menu
        }
    }
}