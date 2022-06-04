#include <stdlib.h>

#include "FilaDinamica.h"

No* CriaNoFila(void *_ptrElemento)
{
    No *ptrNovo = (No *) malloc(sizeof(No));
    if ( !ptrNovo )
        return NULL;

    ptrNovo->ptrElemento = _ptrElemento;
    ptrNovo->ptrProx     = NULL;

    return ptrNovo;
}

void CriaFila(FilaDinamica *ptrFila, int _maxElementos,
              int (*_ptrFncCompara)(void*, void*),
              int (*_ptrFncCopia)   (void*, void*) )
{
    // inicializa valores da Fila
    ptrFila->qtdeElementos = 0;
    ptrFila->maxElementos  = _maxElementos;

    ptrFila->ptrInicio = NULL;
    ptrFila->ptrFim    = NULL;

    ptrFila->ptrFncCompara = _ptrFncCompara;
    ptrFila->ptrFncCopia   = _ptrFncCopia;
}

FilaDinamica* CriaFila2(int _maxElementos,
            int (*_ptrFncCompara)(void*, void*),
            int (*_ptrFncCopia)  (void*, void*) )
{
    // tenta criar a Fila
    FilaDinamica *ptrFila = (FilaDinamica *) malloc(sizeof(FilaDinamica));

    // testa se a Fila NAO foi criada
    if ( !ptrFila )
        return NULL;

    // inicializa valores da Fila
    ptrFila->qtdeElementos = 0;
    ptrFila->maxElementos  = _maxElementos;

    ptrFila->ptrInicio = NULL;
    ptrFila->ptrFim    = NULL;

    ptrFila->ptrFncCompara = _ptrFncCompara;
    ptrFila->ptrFncCopia   = _ptrFncCopia;

    // retorna Fila construida
    return ptrFila;
}
int Enfileira(FilaDinamica *ptrFila, void *ptrElemento)
{
    // verifica se ha espaco para o novo elemento
    if (ptrFila->maxElementos  != -1 &&
        ptrFila->qtdeElementos == ptrFila->maxElementos)
        return 0;

    // posiciona novo elemento na Fila
    No *ptrNovo = CriaNoFila( ptrElemento );
    if ( !ptrNovo )
        return -1;

    if ( !ptrFila->qtdeElementos )
        ptrFila->ptrInicio = ptrNovo;
    else
        ptrFila->ptrFim->ptrProx = ptrNovo;

    ptrFila->ptrFim = ptrNovo;

    ptrFila->qtdeElementos++;
    return 1;
}
void* Desenfileira(FilaDinamica *ptrFila)
{
    if( !ptrFila->qtdeElementos )
    	return NULL;

    // guarda referencia para elemento excluido
    void *ptrElementoAux = ptrFila->ptrInicio->ptrElemento;
    No   *ptrNoAux       = ptrFila->ptrInicio;

    //realiza ajustes dos ponteiros
  	if (ptrFila->qtdeElementos == 1)
        ptrFila->ptrFim = NULL;

    ptrFila->ptrInicio = ptrFila->ptrInicio->ptrProx;

    free( ptrNoAux );
    ptrFila->qtdeElementos--;
    return ptrElementoAux;
}
int ConsultaFila(FilaDinamica *ptrFila, void *ptrElementoSaida)
{
    // verifica se ha elementos
    if ( ptrFila->qtdeElementos )
        return ptrFila->ptrFncCopia(ptrElementoSaida, ptrFila->ptrInicio->ptrElemento);

    return 0;
}
int AlteraFila(FilaDinamica *ptrFila, void *ptrNovo)
{
    // verifica se ha elementos
    if ( ptrFila->qtdeElementos )
        return ptrFila->ptrFncCopia(ptrFila->ptrInicio->ptrElemento, ptrNovo);

    return 0;
}
