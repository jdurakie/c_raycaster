#ifndef VECTORS
#define VECTORS

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    double x, y, z;
}Vector;

Vector * make_vector(double x, double y, double z){
    Vector * new_v = malloc(sizeof(Vector));
    new_v -> x = x;
    new_v -> y = y;
    new_v -> z = z;

    return new_v;
}

void print_vector(Vector* v){
    printf("(%f, %f, %f)\n", v->x, v->y, v->z);
}

double vector_magnitude(Vector *v){
    double inner = (v->x * v->x) + (v->y * v->y) + (v->z * v->z);
    return sqrt(inner);
}

Vector * normalized_vector(Vector * v){
    double m = vector_magnitude(v);
    return make_vector(v->x / m,
                       v->y / m,
                       v->z / m);
}

Vector * add_vector(Vector *v1, Vector *v2){
    double x = v1->x + v2->x;
    double y = v1->y + v2->y;
    double z = v1->z + v2->z;

    return make_vector(x, y, z);
}

Vector * subtract_vector(Vector *v1, Vector *v2){
    double x = v1->x - v2->x;
    double y = v1->y - v2->y;
    double z = v1->z - v2->z;

    return make_vector(x, y, z);
}

Vector * cross_product(Vector * v1, Vector * v2){
    double x1 = v1->x;
    double y1 = v1->y;
    double z1 = v1->z;

    double x2 = v2->x;
    double y2 = v2->y;
    double z2 = v2->z;

    double x = (y1 * z2) - (z1 * y2);
    double y = (z1 * x2) - (x1 * z2);
    double z = (x1 * y2) - (y1 * x2);

    return make_vector(x, y, z);
}

double dot_product(Vector * v1, Vector * v2){
    return (v1->x * v2->x) +
           (v1->y * v2->y) +
           (v1->z * v2->z);
}

Vector * multiply_vector_by_scalar(Vector * v, double s){
    Vector * out_v = make_vector(v->x, v->y, v->z);
    out_v->x = out_v->x * s;
    out_v->y = out_v->y * s;
    out_v->z = out_v->z * s;

    return out_v;
}

#endif
