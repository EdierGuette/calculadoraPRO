#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "utilidades.h"

/**
 * Suma de dos numeros
 */
int operacion_suma(void)
{
    double a, b, resultado;
    char resultado_str[100];

    limpiar_pantalla();
    imprimir_titulo("SUMA DE NUMEROS");

    // Obtener primer numero usando funcion robusta
    if (!leer_double("Ingrese el primer numero: ", &a))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    // Obtener segundo numero usando funcion robusta
    if (!leer_double("Ingrese el segundo numero: ", &b))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    // Calcular resultado
    resultado = a + b;

    // Mostrar operacion paso a paso
    printf("\n");
    imprimir_color("Operacion realizada:\n", COLOR_AZUL);
    printf("  %8.4lf\n", a);
    printf("+ %8.4lf\n", b);

    // Línea divisoria con guiones
    for (int i = 0; i < 12; i++)
        printf("-");
    printf("\n");

    imprimir_color_f("  %8.4lf\n", COLOR_VERDE, resultado);

    // Formatear para log
    snprintf(resultado_str, sizeof(resultado_str),
             "%.4lf + %.4lf = %.4lf", a, b, resultado);

    // Registrar en log
    registrar_log("Suma", resultado_str);

    pausar_pantalla();
    return 0;
}

/**
 * Resta de dos numeros
 */
int operacion_resta(void)
{
    double a, b, resultado;
    char resultado_str[100];

    limpiar_pantalla();
    imprimir_titulo("RESTA DE NUMEROS");

    // Obtener numeros usando funcion robusta
    if (!leer_double("Ingrese el minuendo: ", &a))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    if (!leer_double("Ingrese el sustraendo: ", &b))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    resultado = a - b;

    printf("\n");
    imprimir_color("Operacion realizada:\n", COLOR_AZUL);
    printf("  %8.4lf\n", a);
    printf("- %8.4lf\n", b);

    for (int i = 0; i < 12; i++)
        printf("-");
    printf("\n");

    imprimir_color_f("  %8.4lf\n", COLOR_VERDE, resultado);

    snprintf(resultado_str, sizeof(resultado_str),
             "%.4lf - %.4lf = %.4lf", a, b, resultado);
    registrar_log("Resta", resultado_str);

    pausar_pantalla();
    return 0;
}

/**
 * Multiplicacion de dos numeros
 */
int operacion_multiplicacion(void)
{
    double a, b, resultado;
    char resultado_str[100];

    limpiar_pantalla();
    imprimir_titulo("MULTIPLICACION DE NUMEROS");

    // Obtener numeros usando funcion robusta
    if (!leer_double("Ingrese el primer factor: ", &a))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    if (!leer_double("Ingrese el segundo factor: ", &b))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    resultado = a * b;

    printf("\n");
    imprimir_color("Operacion realizada:\n", COLOR_AZUL);
    printf("  %8.4lf\n", a);
    printf("x %8.4lf\n", b);

    for (int i = 0; i < 12; i++)
        printf("-");
    printf("\n");

    imprimir_color_f("  %8.4lf\n", COLOR_VERDE, resultado);

    snprintf(resultado_str, sizeof(resultado_str),
             "%.4lf x %.4lf = %.4lf", a, b, resultado);
    registrar_log("Multiplicacion", resultado_str);

    pausar_pantalla();
    return 0;
}

/**
 * Division de dos numeros
 */
int operacion_division(void)
{
    double a, b, resultado;
    char resultado_str[100];

    limpiar_pantalla();
    imprimir_titulo("DIVISION DE NUMEROS");

    // Obtener dividendo usando funcion robusta
    if (!leer_double("Ingrese el dividendo: ", &a))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    // Obtener divisor usando funcion robusta
    if (!leer_double("Ingrese el divisor: ", &b))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    // Verificar division por cero
    if (b == 0.0)
    {
        imprimir_color("\nError: No se puede dividir entre cero\n", COLOR_ROJO);
        printf("La operacion %.4lf / 0 no esta definida\n", a);
        pausar_pantalla();
        return 1;
    }

    resultado = a / b;

    printf("\n");
    imprimir_color("Operacion realizada:\n", COLOR_AZUL);
    printf("  %8.4lf\n", a);
    printf("/ %8.4lf\n", b);

    for (int i = 0; i < 12; i++)
        printf("-");
    printf("\n");

    imprimir_color_f("  %8.4lf\n", COLOR_VERDE, resultado);

    snprintf(resultado_str, sizeof(resultado_str),
             "%.4lf / %.4lf = %.4lf", a, b, resultado);
    registrar_log("Division", resultado_str);

    pausar_pantalla();
    return 0;
}

/**
 * Potencia de un numero
 */
int operacion_potencia(void)
{
    double base, exponente, resultado;
    char resultado_str[100];

    limpiar_pantalla();
    imprimir_titulo("CALCULO DE POTENCIA");

    // Obtener base usando funcion robusta
    if (!leer_double("Ingrese la base: ", &base))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    // Obtener exponente usando funcion robusta
    if (!leer_double("Ingrese el exponente: ", &exponente))
    {
        printf("Error: Entrada no valida\n");
        pausar_pantalla();
        return 1;
    }

    // Calcular potencia
    errno = 0;
    resultado = pow(base, exponente);

    // Verificar errores matematicos
    if (errno == ERANGE)
    {
        printf("\n");
        imprimir_color("Advertencia: Resultado fuera de rango\n", COLOR_AMARILLO);
    }

    // Casos especiales
    if (base == 0.0 && exponente < 0)
    {
        imprimir_color("\nError: Indeterminacion 0^negativo\n", COLOR_ROJO);
        pausar_pantalla();
        return 1;
    }

    // Mostrar resultado
    printf("\n");
    imprimir_color("Operacion realizada:\n", COLOR_AZUL);
    printf("  %.4lf ^ %.4lf = ", base, exponente);
    imprimir_color_f("%.4lf\n", COLOR_VERDE, resultado);

    snprintf(resultado_str, sizeof(resultado_str),
             "%.4lf ^ %.4lf = %.4lf", base, exponente, resultado);
    registrar_log("Potencia", resultado_str);

    pausar_pantalla();
    return 0;
}