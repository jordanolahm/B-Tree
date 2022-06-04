#include <stdio.h>

int ComparaInt(void *ptrElemento1, void *ptrElemento2)
{
    int *ptrE1 = (int *) ptrElemento1;
    int *ptrE2 = (int *) ptrElemento2;

    return *ptrE1 - *ptrE2;
}
int CopiaInt(void *ptrDestino, void *ptrOrigem)
{
    int *ptrED = (int *) ptrDestino;
    int *ptrEO = (int *) ptrOrigem;

    *ptrED = *ptrEO;
    return 1;
}
void EscreveInt(void *ptrDado)
{
    int *p = (int *) ptrDado;
    printf("%d ", *p);
}
