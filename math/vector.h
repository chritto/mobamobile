#ifndef _VECTOR_VECTOR_H
#define _VECTOR_VECTOR_H

typedef struct vector_impl {
    float x;
    float y;
    float z;
} vector;

vector vector_create(float x, float y, float z) {
    vector v = {x, y, z};
    return v;
}

#endif
