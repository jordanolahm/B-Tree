#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

typedef struct No
{
    void      *ptrElemento;
    struct No *ptrProx;
}No;

typedef struct
{
    int qtdeElementos;
    int maxElementos;
    No  *ptrInicio,
        *ptrFim;

    int (*ptrFncCompara)(void *ptrElemento, void *ptrChave);
    int (*ptrFncCopia)  (void *ptrDestino , void *ptrOrigem);
} FilaDinamica;

void CriaFila(FilaDinamica *ptrFila, int _maxElementos,
               int (*_ptrFncCompara)(void*, void*),
               int (*_ptrFncCopia)   (void*, void*) );
FilaDinamica* CriaFila2(int _maxElementos,
            int (*_ptrFncCompara)(void*, void*),
            int (*_ptrFncCopia)  (void*, void*) );

int Enfileira     (FilaDinamica *ptrFila, void *ptrElemento);
void* Desenfileira(FilaDinamica *ptrFila);
int ConsultaFila  (FilaDinamica *ptrFila, void *ptrElementoSaida);
int AlteraFila    (FilaDinamica *ptrFila, void *ptrNovo);

#endif // FILADINAMICA_H_INCLUDED
