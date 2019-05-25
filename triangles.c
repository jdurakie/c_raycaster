#ifndef TRIANGLES
#define TRIANGLES

#include <stdlib.h>

#include "vectors.c"
#include "lines.c"


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
    Vector * cp = cross_product(p1, p2);
    free(p2);
    free(p1);
    return cp;
}

Vector * triangle_line_intersection(Triangle * triangle, Line * line){
    // Based on handout by Brian Curless:
    // https://courses.cs.washington.edu/courses/csep557/10au/lectures/triangle_intersection.pdf

    // figure out the normal of the triangle's plane
    Vector * n = normalized_vector(triangle_normal(triangle));
    Vector * dirv = normalized_vector(subtract_vector(line->start, line->end));
    // solve for d (righthand of plane equation)
    double d = dot_product(n, triangle->v1);
    // solve for t : vector magnitude coeficcient in ray equation
    //              R(t) = line->start + t * dirv
    double top = d - dot_product(n, line->start);
    double bottom = dot_product(n, dirv);
    // if the bottom is 0, the line is parallel to the triangle
    // (triangle normal and dirv are perpendicular)
    // assuming anything < 10e-8 is == to 0
    if(fabs(bottom) < 10e-8){
        free(n);
        free(dirv);
        return NULL;
    }
    double t = top / bottom;
    // plug T into the equation for the ray to get ray-plane intersection
    Vector * Q = add_vector(line->start, multiply_vector_by_scalar(dirv, t));
    free(dirv);
    // figure out whether the point is inside the triangle or not
    // by checking if it's 'to the right' of all the triangle's edges
    Vector * AB = subtract_vector(triangle->v2, triangle->v1);
    Vector * AQ = subtract_vector(Q, triangle->v1);
    double ABcross = dot_product(cross_product(AB, AQ), n);
    free(AB);
    free(AQ);
    if(ABcross < 0){
        free(Q);
        free(n);
        return NULL;
    }

    Vector * BC = subtract_vector(triangle->v3, triangle->v2);
    Vector * BQ = subtract_vector(Q, triangle->v2);
    double BCcross = dot_product(cross_product(BC, BQ), n);
    free(BC);
    free(BQ);
    if(BCcross < 0){
        free(Q);
        free(n);
        return NULL;
    }
    
    Vector * CA = subtract_vector(triangle->v1, triangle->v3);
    Vector * CQ = subtract_vector(Q, triangle->v3);
    double CAcross = dot_product(cross_product(CA, CQ), n);
    free(CA);
    free(CQ);
    free(n);
    if(CAcross < 0){
        free(Q);
        return NULL;
    }
    return Q;

}



#endif
