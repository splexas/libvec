#include <stdlib.h>
#include <string.h>
#include "vec.h"

vec_t *vec_init(int elem_size, int reserved_elements)
{
    vec_t *vec = malloc(sizeof(vec_t));
    if (vec == NULL)
        return NULL;
    vec->arr = NULL;
    vec->elem_size = elem_size;
    vec->elem_count = 0;
    vec->reserved = reserved_elements != -1 ? vec->elem_size * reserved_elements : vec->elem_size * VEC_RESERVED_ELEMENTS;
    vec->allocated = 0;
    return vec;
}

int vec_push(vec_t *vec, void *val)
{
    char *new_arr;
    if (vec->arr == NULL) {
        new_arr = malloc(vec->reserved);
        if (new_arr == NULL)
            return 1;
        vec->arr = new_arr;
        vec->allocated = vec->reserved;
    }
    // check if we actually need to resize
    if (vec->allocated == vec->elem_count * vec->elem_size) {
        int allocated = vec->allocated + vec->reserved;
        new_arr = realloc(vec->arr, allocated);
        if (new_arr == NULL)
            return 1;
        vec->arr = new_arr;
        vec->allocated = allocated;
    }
    memcpy(vec->arr + vec->elem_count * vec->elem_size, val, vec->elem_size);
    vec->elem_count++;
    return 0;
}

void *vec_get(vec_t *vec, unsigned int index)
{
    return vec->elem_count < index ? NULL : vec->arr + vec->elem_size * index;
}

void vec_remove(vec_t *vec, unsigned int index)
{
    if (vec->elem_count - 1 == index) {
        vec->elem_count--;
        return;
    }
    for (int i = index; i < vec->elem_count; i++)
        vec->arr[i] = vec->arr[i + 1];
    vec->elem_count--;
}

void vec_free(vec_t **vec)
{
    if (vec != NULL && *vec != NULL) {
        if ((*vec)->arr != NULL)
            free((*vec)->arr);
        free(*vec);
        *vec = NULL;
    }
}
