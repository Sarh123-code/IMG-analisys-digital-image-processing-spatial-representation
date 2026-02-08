#include <imago2.h>
#include <stdlib.h>
#include <string.h>

char *channel_extract(char *pixels, int size, int channel_number)
{
    char *mono = malloc(3 * size * sizeof(char));
    memcpy(mono,pixels,size * 3);
    for (int i = 0; i < size * 3; i+=3)
    {
        switch (channel_number)
        {
        case 0:
            mono[i+1] = 0;
            mono[i+2] = 0;
            break;
        case 1:
            mono[i] = 0;
            mono[i+2] = 0;
            break;
        case 2:
            mono[i] = 0;
            mono[i+1] = 0;
            break;
        default:
            break;
        }
    }
    return mono;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    struct img_pixmap *img = img_create(); 
    if(img==NULL)
    {
        return -1;
    }

    if(img_load(img, argv[1]) < 0)
    {
        ret = -1;
        goto cleanup;
    }

    char *red = channel_extract(img->pixels,img->width * img->height, 0);
    char *green = channel_extract(img->pixels,img->width * img->height, 1);
    char *blue = channel_extract(img->pixels,img->width * img->height, 2);

    if (img_save_pixels(argv[2], red, img->width, img->height, IMG_FMT_RGB24) < 0)
    {
        ret = -1;
        goto cleanup;
    }

    if (img_save_pixels(argv[3], green, img->width, img->height, IMG_FMT_RGB24) < 0)
    {
        ret = -1;
        goto cleanup;
    }

    if (img_save_pixels(argv[4], blue, img->width, img->height, IMG_FMT_RGB24) < 0)
    {
        ret = -1;
        goto cleanup;
    }

    goto cleanup;

    cleanup:
        if(img != NULL)
        {
            img_free(img);
            img = NULL;
        }
        if(red != NULL)
        {
            free(red);
            red = NULL;
        }
        if(green != NULL)
        {
            free(green);
            green = NULL;
        }
        if(blue != NULL)
        {
            free(blue);
            blue = NULL;
        }
        return ret;
}

