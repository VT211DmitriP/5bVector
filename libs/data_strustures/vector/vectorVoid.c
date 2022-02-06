#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *v = malloc(baseTypeSize * n);
    if (v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {v, 0, n};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else {
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
        v->capacity = newCapacity;
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}


