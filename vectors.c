#include <math.h>

typedef struct{
    double x, y, z;
}Vector;


void print_vector(Vector* v){
    printf("(%f, %f, %f)\n", v->x, v->y, v->z);
}

double magnitude(Vector *v){
    double inner = (v->x * v->x) + (v->y * v->y) + (v->z * v->z);
    return sqrt(inner);
}
