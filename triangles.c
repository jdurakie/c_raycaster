#ifndef TRIANGLES
#define TRIANGLES

#include <stdlib.h>

#include "vectors.c"


typedef struct{
    Vector * v1;
    Vector * v2;
    Vector * v3;
}Triangle;

Triangle * make_triangle(Vector * v1, Vector * v2, Vector * v3){
    Triangle * new_t = malloc(sizeof(Triangle));
    new_t->v1 = v1;
    new_t->v2 = v2;
    new_t->v3 = v3;
    
    return new_t;
}

void print_triangle(Triangle* t){
    printf("Triangle:\n");
    print_vector(t->v1);
    print_vector(t->v2);
    print_vector(t->v3);
    printf("----\n");
}

Vector * triangle_normal(Triangle * t){
    Vector * p1 = subtract_vector(t->v2, t->v1);
    Vector * p2 = subtract_vector(t->v3, t->v2);
    return cross_product(p1, p2);
}

#endif