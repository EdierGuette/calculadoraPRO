#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculadora_basica.h"
#include "utilidades.h"

/**
 * Funcion para salir del programa con confirmacion
 */
int salir_programa(void)
{
    char confirmacion;

    printf("\n");
    imprimir_color("Esta seguro que desea salir? (s/n): ", COLOR_ROJO);
    scanf(" %c", &confirmacion);
    while (getchar() != '\n')
        ; // Limpiar buffer

    if (confirmacion == 's' || confirmacion == 'S')
    {
        limpiar_pantalla();
        printf("\n");
        imprimir_color("==================================================\n", COLOR_VERDE);
        imprimir_color("        Gracias por usar Calculadora Pro!        \n", COLOR_VERDE);
        imprimir_color("              Hasta pronto                        \n", COLOR_VERDE);
        imprimir_color("==================================================\n", COLOR_VERDE);
        printf("\n");
        return 0; // Salir
    }

    return 1; // Continuar en el programa
}

/**
 * Funcion principal
 */
int main(void)
{
    // Registrar inicio del programa
    registrar_log("PROGRAMA", "Calculadora Pro iniciada");

    // Mensaje de bienvenida
    limpiar_pantalla();
    printf("\n");
    imprimir_color("==================================================\n", COLOR_CYAN);
    imprimir_color("     BIENVENIDO A CALCULADORA PRO v2.0           \n", COLOR_CYAN);
    printf("\n");
    imprimir_color("  Sistema modular con operaciones basicas        \n", COLOR_AMARILLO);
    imprimir_color("==================================================\n", COLOR_CYAN);
    printf("\n");

    pausar_pantalla();

    // Configurar menu principal
    OpcionMenu menu_principal[] = {
        {"Salir del programa", salir_programa},
        {"Suma de numeros", operacion_suma},
        {"Resta de numeros", operacion_resta},
        {"Multiplicacion de numeros", operacion_multiplicacion},
        {"Division de numeros", operacion_division},
        {"Potencia de un numero", operacion_potencia}};

    int total_opciones = sizeof(menu_principal) / sizeof(menu_principal[0]);

    // Mostrar menu principal
    mostrar_menu(menu_principal, total_opciones);

    // Registrar fin del programa
    registrar_log("PROGRAMA", "Calculadora Pro finalizada");

    return 0;
}