#ifndef VEC_H
#define VEC_H

#define VEC_RESERVED_ELEMENTS 50

typedef struct vec {
    char *arr;
    int elem_size;
    int elem_count;
    int reserved; // const value
    int allocated;
} vec_t;

vec_t *vec_init(int elem_size, int reserved_elements);
int vec_push(vec_t *vec, void *val);
void *vec_get(vec_t *vec, unsigned int index);
void vec_remove(vec_t *vec, unsigned int index);
void vec_free(vec_t **vec);

#endif
