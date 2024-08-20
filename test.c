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

    vec_free(&vec);
    vec_free(&vec1);
    return 0;
}
