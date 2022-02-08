#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "../../algorithms/array/array.h"

#ifndef INC_5B_VECTOR_VECTORVOID_H
#define INC_5B_VECTOR_VECTORVOID_H

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                         // например, если вектор хранит int -
                         // то поле baseTypeSize = sizeof(int)
                         // если вектор хранит float -
                         // то поле baseTypeSize = sizeof(float)
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений типа baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти на newCapacity,
// выделенное под хранение элементов вектора v типа baseTypeSize
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// удаляет элементы из вектора v,
// но не освобождает выделенную память
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору v
void deleteVectorV(vectorVoid *v);

// возвращает 'истина', если вектор v пуст, иначе 'ложь'
bool isEmptyV(vectorVoid *v);

// возвращает 'истина', если вектор v полон, иначе 'ложь'
bool isFullV(vectorVoid *v);

//записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v);

// добавляет элемент x в конец вектора v
void pushBackV(vectorVoid *v, void *source);

#endif
