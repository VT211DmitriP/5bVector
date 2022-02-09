#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>

#include "vectorVoid.h"

static void badAllocV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *v = malloc(baseTypeSize * n);
    if (v == NULL) {
        badAllocV();
    }
    return (vectorVoid) {v, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        return;
    }
    else if (newCapacity < v->size) {
        v->size = newCapacity;
    }
    v->data = (int *) realloc(v->data, v->baseTypeSize * newCapacity);
    v->capacity = newCapacity;
    if (v->data == NULL) {
        badAllocV();
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    reserveV(v, 0);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t i, void *source) {
    char *destination = (char *) v->data + i * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        badAllocV();
    }
    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);
    setVectorValueV(v, v->size++, source);
}
