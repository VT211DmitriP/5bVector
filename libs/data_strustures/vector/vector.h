#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "../../algorithms/array/array.h"

#ifndef INC_5B_VECTOR_VECTOR_H
#define INC_5B_VECTOR_VECTOR_H

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти на newCapacity,
// выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из вектора v,
// но не освобождает выделенную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);

// возвращает 'истина', если вектор v пуст, иначе 'ложь'
bool isEmpty(vector *v);

// возвращает 'истина', если вектор v полон, иначе 'ложь'
bool isFull(vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора v
void popBack(vector *v);

//
int* atVector(vector *v, size_t index);

//
int* back(vector *v);

//
int* front(vector *v);

// вывод вектора v
void vector_print(vector v);

#endif
