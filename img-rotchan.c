#include <imago2.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x_size;
    int y_size;
    void *pixel = img_load_pixels(argv[1], &x_size, &y_size, IMG_FMT_RGB24);
    
    if (pixel == NULL)
        return -1;
    
    char *pix = pixel;

    char r,g,b;
    // On multiplie par 3 car un pixel occupe 3 octets dans le format IMG_FMT_RGB24
    for (int i = 0; i < x_size * y_size * 3; i+=3) 
    {
        r = pix[i];
        g = pix[i+1];
        b = pix[i+2];

        pix[i] = b;
        pix[i+1] = r;
        pix[i+2] = g;
    }

    if (img_save_pixels(argv[2], pix, x_size, y_size, IMG_FMT_RGB24) < 0)
    {
        free(pix);
        pix = NULL;
        return -1;
    }

    free(pix);
    pix = NULL;
    return 0;
}