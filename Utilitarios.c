#include <stdio.h>

#include "Utilitarios.h"

void limpaBufferTeclado()
{
    int ch = ' ';

    while(ch != EOF && ch != '\n' )
        ch = fgetc(stdin);
}
