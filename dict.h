#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 100

typedef struct {
    int type;           // 0: int, 1: float, 2: string
    char data[MAX_DATA]; // almacenamiento genérico (int, float o string)
} object;

typedef struct st_dict_node {
    object key;
    object value;
    struct st_dict_node *next;
} dict_node;


typedef struct {
    dict_node *first; // Puntero al primer nodo
    int len;          // Longitud del diccionario
} dict;


dict *dict_new(); // Crea un nuevo diccionario
void dict_destroy(dict *dic); // Destruye el diccionario y libera la memoria

int dict_add(dict *dic, object key, object value); // Añade un par clave-valor
int dict_search(dict *dic, object key, object *dst); // Busca una clave
int dict_remove(dict *dic, object key); // Elimina una clave

int dict_len(dict *dic); // Retorna la longitud del diccionario
dict_node *dict_first(dict *dic); // Retorna el primer nodo
dict_node *dict_next(dict *dic, dict_node *current); // Retorna el siguiente nodo

void dict_key(dict_node *pair, object *dst); // Obtiene la clave de un nodo
void dict_value(dict_node *pair, object *dst); // Obtiene el valor de un nodo


void int_to_obj(int src, object *dst);
void float_to_obj(float src, object *dst);
void str_to_obj(char *src, object *dst);

void obj_to_int(object src, int *dst);
void obj_to_float(object src, float *dst);
void obj_to_str(object src, char *dst);
