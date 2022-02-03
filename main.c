#include "libs/data_strustures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 3);

    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack_fullVector1() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);

    assert(v.size == 2);
    assert(v.capacity == 2);
}

void test_pushBack_fullVector2() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_popBack_notEmptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_popBack_notEmptyVector2() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 24);
    pushBack(&v, 58);

    assert(v.size == 3);

    popBack(&v);
    assert(v.size == 2);
    assert(v.capacity == 3);
}

void test_popBack_notEmptyVector3() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 24);
    pushBack(&v, 58);

    assert(v.size == 3);

    popBack(&v);
    popBack(&v);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 3);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();

    test_popBack_notEmptyVector1();
    test_popBack_notEmptyVector2();
    test_popBack_notEmptyVector3();
}


int main() {
    test();

    return 0;
}
