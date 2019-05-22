#ifndef LINES
#define LINES

#include "vectors.c"

typedef struct{
    Vector * start;
    Vector * end;
}Line;

Line * make_line(Vector * start, Vector * end){
    Line * new_l = malloc(sizeof(Line));
    new_l -> start = start;
    new_l -> end = end;
    
    return new_l;
}

void print_line(Line * l){
    printf("Line : \n");
    print_vector(l->start);
    print_vector(l->end);
    printf("---");
}

Vector * vectorize_line(Line * l){
    return subtract_vector(l->end, l->start);
}

#endif