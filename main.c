#include <stdio.h>
#include <time.h>

#include <unistd.h>

#include "vectors.c"
#include "video.c"

int main(){
    Vector v1;
    v1.x = 2;
    v1.y = 2;
    v1.z = 2;

    print_vector(&v1);

    printf("%f\n", magnitude(&v1));

    initialize_video(800, 600);
    for(int i =0; i < 100; i++){
        int location = (int)time(NULL) % 800;
        draw_pixel(location, 100, 0, 0, 0);
        printf("Drew a pixel!");
    }
    flip();
    sleep(10);
    exit_video();
}
