#include <imago2.h>

// /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i08_glv-.png /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i08_glva.png /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i08_rgb-.jpg /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i08_rgba.png /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i16_glv-.ppm /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i16_glva.png /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i16_rgb-.png /net/cremi/framananaher/espaces/travail/ti/ACT01_ressources/Img-format-tests/damier_i16_rgba.png

int main(int argc, char *argv[])
{
    int is_float, has_alpha, is_greyscale;

    for (int i = 1 ; i < argc ; i++)
    {
        struct img_pixmap *img = img_create(); 
        if(img==NULL)
        {
            return -1;
        }
    
        if(img_load(img, argv[i]) < 0)
        {
            printf("img-format: cannot load '%s'\n", argv[i]);
            img_free(img);
            img = NULL;
            continue;
        }

        is_float = img_is_float(img);
        has_alpha = img_has_alpha(img);
        is_greyscale = img_is_greyscale(img);
        img_free(img);
        img = NULL;

        if(is_greyscale)
            printf("'%s': grayscale ", argv[i]);
        else 
            printf("'%s': RGB ", argv[i]);

        if(is_float)
            printf("16 bits ");
        else 
            printf("8 bits ");

        if(is_greyscale)
        {
            printf("\n");
            continue;
        }
            

        if(has_alpha)
            printf("with alpha channel\n");
        else 
            printf("without alpha channel\n");
    }

    return 0;
}