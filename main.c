#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

#define MAX_INPUT 100

int main() {
    dict *mi_diccionario = dict_new();
    char input[MAX_INPUT];
    object key, value;
    int opcion;

    while (1) {
        printf("Seleccione una opcion:\n");
        printf("1. Anadir clave\n");
        printf("2. Listar diccionario\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        fgets(input, MAX_INPUT, stdin);
        opcion = atoi(input);

        switch (opcion) {
            case 1:
                printf("Ingrese una clave: ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0; 
                str_to_obj(input, &key);

                printf("Ingrese un valor: ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0; 
                str_to_obj(input, &value);

                dict_add(mi_diccionario, key, value);
                break;

            case 2:
                printf("Contenido del diccionario:\n");
                dict_node *nodo = dict_first(mi_diccionario);
                while (nodo != NULL) {
                    obj_to_str(nodo->key, input);
                    printf("Clave: %s, ", input);
                    obj_to_str(nodo->value, input);
                    printf("Valor: %s\n", input);
                    nodo = dict_next(mi_diccionario, nodo);
                }
                break;

            case 3:
                dict_destroy(mi_diccionario);
                return 0;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }
}