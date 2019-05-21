#include <stdio.h>

#include "vectors.c"

void main(){
    Vector v1;
    v1.x = 2;
    v1.y = 2;
    v1.z = 2;

    print_vector(&v1);

    printf("%f\n", magnitude(&v1));
}
