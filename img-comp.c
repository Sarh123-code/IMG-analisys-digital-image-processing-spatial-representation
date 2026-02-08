#include <imago2.h>
#include <stdlib.h>
#include <string.h>

char *channel_compose(char *r_chan, char *g_chan, char *b_chan, size_t size)
{
    char *pixels = malloc(3 * size * sizeof(char));
    
    for (int i = 0; i < size * 3; i+=3)
    {
        pixels[i] = r_chan[i];
        pixels[i+1] = g_chan[i+1];
        pixels[i+2] = b_chan[i+2];
    }

    return pixels;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    struct img_pixmap *red = img_create(); 
    struct img_pixmap *green = img_create(); 
    struct img_pixmap *blue = img_create(); 

    if(red == NULL || green == NULL || blue == NULL) 
    {
        ret = -1;
        goto cleanup;
    }

    if(img_load(red, argv[1]) < 0)
    {
        ret = -1;
        goto cleanup;
    }
    if(img_load(green, argv[2]) < 0)
    {
        ret = -1;
        goto cleanup;
    }
    if(img_load(blue, argv[3]) < 0)
    {
        ret = -1;
        goto cleanup;
    }

    char *result = channel_compose(red->pixels, green->pixels, blue->pixels, red->width * red->height);
    if (img_save_pixels(argv[4], result, red->width, red->height, IMG_FMT_RGB24) < 0)
    {
        ret = -1;
        goto cleanup;
    }


    goto cleanup;

    cleanup:
        if(red != NULL)
        {
            img_free(red);
            red = NULL;
        }
        if(green != NULL)
        {
            img_free(green);
            green = NULL;
        }
        if(blue != NULL)
        {
            img_free(blue);
            blue = NULL;
        }
        if(result != NULL)
        {
            free(result);
            result = NULL;
        }
        return ret;
}

