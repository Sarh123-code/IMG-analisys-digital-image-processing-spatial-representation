#include <imago2.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float f(float a, float x) 
{
    return a * x + ((1 - a) * 2 * x * x) / (1 + x * x);
}


int scale(float x, int width) {
    float h = width / 2 - 1; 
    int ix = (x + 1.0) * h;

    if (ix < 0) ix = 0;
    if (ix >= width) ix = width - 1;

    return ix;
}

int main(int argc, char *argv[]) {

    int width = atoi(argv[1]);
    float A = strtod(argv[2], NULL);
    float B = strtod(argv[3], NULL);
    float X_0 = strtod(argv[4], NULL);
    float Y_0 = strtod(argv[5], NULL);
    int N = atoi(argv[6]);

    float *tab_X = malloc(N * sizeof(float));
    float *tab_Y = malloc(N * sizeof(float));

    float alpha;

    struct img_pixmap *img = img_create(); 
    if(img==NULL)
    {
        return -1;
    }

    if(img_set_pixels(img, width, width, IMG_FMT_RGBA32, NULL) == -1) return -1;

    tab_X[0] = X_0;
    tab_Y[0] = Y_0;
    float global_max = 0.01; // attention division par 0

    // calcul max global
    for (int i = 1; i < N; i++) {
        tab_X[i] = B * tab_Y[i-1] + f(A, tab_X[i-1]);
        tab_Y[i] = -tab_X[i-1] + f(A, tab_X[i]);
        
        
        if (fabs(tab_X[i]) > global_max) global_max = fabs(tab_X[i]);
        if (fabs(tab_Y[i]) > global_max) global_max = fabs(tab_Y[i]);
    }

    // dessin points
    for(int i=0; i < N; i++) {
        // normaliser
        float nx = tab_X[i] / global_max;
        float ny = tab_Y[i] / global_max;

        // calcul de alpha
        float dist = sqrt(nx*nx + ny*ny);
        alpha = 1.0 - (dist / sqrt(2.0)); 
        if (alpha < 0) alpha = 0;

        int ix = scale(nx, width);
        int iy = scale(ny, width);

        unsigned char pixel[] = { 255, (unsigned char)(255*alpha), (unsigned char)(255*alpha*alpha), 255 };

        img_setpixel(img, ix, iy, pixel);
    }


    if (img_save(img, argv[7]) < 0)
    {
        img_free(img);
        img = NULL;
        return -1;
    }

    free(tab_X);
    free(tab_Y);
    tab_X = NULL;
    tab_Y = NULL;

    img_free(img);
    img = NULL;
    return 0;

}