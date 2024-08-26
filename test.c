#include <stdio.h>
#include "vec.h"

struct my_struct {
    int a, b;
};

int main() {
    vec_t *vec = vec_init(sizeof(int), -1);
    int val = 200;
    for (int i = 0; i < 10000; i++) {
        vec_push(vec, &val);
    }

    vec_t *vec1 = vec_init(sizeof(struct my_struct), -1);
    struct my_struct val1 = {100, 200};
    for (int i = 0; i < 10000; i++) {
        vec_push(vec1, &val1);
    }

    struct my_struct *retrieved = vec_get(vec1, 0);
    printf("%d %d\n", retrieved->a, retrieved->b);

    struct my_struct val2 = {300, 400};
    vec_push(vec1, &val2);
    int idx = vec_find(vec1, &val2); // returns index 10000 at vec1
    printf("idx: %d\n", idx);

    /* testing pointers */
    
    int a = 10;
    int *tmp = &a;

    vec_t *vec2 = vec_init(sizeof(int *), -1);
    vec_push(vec2, &tmp);
    int *a_ptr = *(int **)vec_get(vec2, 0); // it returns out the memory space 
                                            // of internal arr, so just treat it
                                            // as a int ** 
    printf("a_ptr: %p\n", a_ptr);

    *a_ptr = 20;
    printf("a: %d\n", a);

    vec_free(vec);
    vec_free(vec1);
    vec_free(vec2);
    return 0;
}
