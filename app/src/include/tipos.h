#ifndef TIPOS_H
#define TIPOS_H

// Tipo para funciones de operación
typedef int (*FuncionOperacion)(void);

// Estructura para opciones del menú
typedef struct
{
    char nombre[50];
    FuncionOperacion funcion;
} OpcionMenu;


#endif