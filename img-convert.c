#include <imago2.h>

/*
gcc -I$HOME/local/include -L$HOME/local/lib  -Wall -limago -lpng -ljpeg -o a img-convert.c
gcc -L$HOME/local/lib -I$HOME/local/include -Wall  -o a img-convert.c
 */ 

int main(int argc, char *argv[])
{
    struct img_pixmap *img = img_create(); 
    if(img==NULL)
    {
        return -1;
    }
    
    if(img_load(img, argv[1]) < 0)
    {
        return -1;
    }

    if(img_save(img, argv[2]) < 0)
    {
        return -1;
    }

    img_free(img);
    img = NULL;

    return 0;
}