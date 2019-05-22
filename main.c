#include <stdio.h>
#include <time.h>

#include <unistd.h>

#include "triangles.c"
#include "video.c"
#include "lines.c"

int main(){
    // Random math tests
    // Vector creation
    Vector * v1 = make_vector(2, 2, 50);
    print_vector(v1);
    // Triangle creation
    Vector * v2 = make_vector(2, 4, 50);
    Vector * v3 = make_vector(4, 3, 50);
    Triangle * t = make_triangle(v1, v2, v3);
    print_triangle(t);
    // // vector subtraction
    // Vector * r = subtract_vector(v3, v1);
    // print_vector(r);
    // // vector normal
    // printf("Normal : ");
    // Vector * normal = triangle_normal(t);
    // print_vector(normal);
    // // line creation
    // Line * l = make_line(v1, v2);
    // print_line(l);
    // // line vectorization
    // printf("Vectorized line : ");
    // Vector * vectorized = vectorize_line(l);
    // print_vector(vectorized);
    // // triangle-line intersection
    Vector * line_start = make_vector(3, 3, 0);
    Vector * line_end = make_vector(3, 3, 100);
    Line * thru_line = make_line(line_start, line_end);
    print_line(thru_line);
    Vector * intersection = triangle_line_intersection(t, thru_line);
    if(intersection != NULL){
        printf("Intersection : \n");
        print_vector(intersection);
    }
    else{
        printf("No intersection!\n");
    }
    // Video test
    initialize_video(1000, 1000);
    for(int j = 0; j < 3; j++){
        for(int i =100; i < 200; i++){
            draw_pixel(i, j, 0, 0, 0);
        }
        flip();
        sleep(1);
    }
    exit_video();
}
