#include "dict.h"
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

dict *dict_new() {
    dict *new_dict = (dict *)malloc(sizeof(dict));
    new_dict->first = NULL;
    new_dict->len = 0;
    return new_dict;
}

/*  
dict *dict_new({
    dict* d =malloc(sizeof *d);
    if (d! = NULL){
    d->len = 0;
    d->first = NULL;
    }
    return d;
})
*/

void dict_destroy(dict *dic) {
    dict_node *current = dic->first;
    dict_node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(dic);
}

int compare_keys(object key1, object key2) {
    if (key1.type != key2.type) {
        return 0; // Diferentes tipos no son iguales
    }
    switch (key1.type) {
        case 0: // int
            return atoi(key1.data) == atoi(key2.data);
        case 1: // float
            return atof(key1.data) == atof(key2.data);
        case 2: // string
            return strcmp(key1.data, key2.data) == 0;
        default:
            return 0;
    }
}

int dict_add(dict *dic, object key, object value) {
    dict_node *current = dic->first;

    // Verificar si la clave ya existe
    while (current != NULL) {
        if (compare_keys(current->key, key)) {
            // Clave encontrada, actualizar valor
            current->value = value;
            return 0;
        }
        current = current->next;
    }

    // Clave no encontrada, añadir nuevo nodo
    dict_node *new_node = (dict_node *)malloc(sizeof(dict_node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = dic->first;
    dic->first = new_node;
    dic->len++;
    return 0;
}

int dict_search(dict *dic, object key, object *dst) {
    dict_node *current = dic->first;
    while (current != NULL) {
        if (compare_keys(current->key, key)) {
            *dst = current->value;
            return 0;
        }
        current = current->next;
    }
    return -1; // Clave no encontrada
}

int dict_remove(dict *dic, object key) {
    dict_node *current = dic->first;
    dict_node *previous = NULL;

    while (current != NULL) {
        if (compare_keys(current->key, key)) {
            if (previous == NULL) {
                dic->first = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            dic->len--;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1; // Clave no encontrada
}

int dict_len(dict *dic) {
    return dic->len;
}

dict_node *dict_first(dict *dic) {
    return dic->first;
}

dict_node *dict_next(dict *dic, dict_node *current) {
    return current->next;
}

void dict_key(dict_node *pair, object *dst) {
    *dst = pair->key;
}

void dict_value(dict_node *pair, object *dst) {
    *dst = pair->value;
}

void int_to_obj(int src, object *dst) {
    dst->type = 0;
    sprintf(dst->data, "%d", src); // convertir int a string y almacenarlo
}

void float_to_obj(float src, object *dst) {
    dst->type = 1;
    sprintf(dst->data, "%f", src); // convertir float a string
}

void str_to_obj(char *src, object *dst) {
    dst->type = 2;
    strcpy(dst->data, src); // copiar string al object
}

void obj_to_int(object src, int *dst) {
    if (src.type == 0) {
        *dst = atoi(src.data); // convertir string a int
    }
}

void obj_to_float(object src, float *dst) {
    if (src.type == 1) {
        *dst = atof(src.data); // convertir string a float
    }
}

void obj_to_str(object src, char *dst) {
    if (src.type == 2) {
        strcpy(dst, src.data); // copiar string desde object
    }
}