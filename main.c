#include <stdio.h>
#include <time.h>

#include <unistd.h>

#include "triangles.c"
#include "video.c"
#include "lines.c"

int main(){
    // Random math tests
    Vector * v1 = make_vector(2, 2, 2);
    print_vector(v1);
    Vector * v2 = make_vector(2, 3, 2);
    Vector * v3 = make_vector(3, 2, 2);
    Triangle * t = make_triangle(v1, v2, v3);
    print_triangle(t);
    Vector * r = subtract_vector(v3, v1);
    print_vector(r);
    printf("Normal : ");
    Vector * normal = triangle_normal(t);
    print_vector(normal);
    Line * l = make_line(v1, v2);
    print_line(l);
    printf("Vectorized line : ");
    Vector * vectorized = vectorize_line(l);
    print_vector(vectorized);
    
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
