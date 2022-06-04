#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct NoArvore
{
    void *ptrDado;
    int fFB;
    struct NoArvore   *ptrEsq;
    struct NoArvore   *ptrDir;
//    NoArvore   *vetorSubArvores[50]; arvore/no com 50 subArvores
} NoArvore;

typedef struct
{
    NoArvore *ptrRaiz;
    int  (*ptrFncCompara)(void *ptrElemento, void *ptrChave);
    int  (*ptrFncCopia)  (void *ptrDestino , void *ptrOrigem);
    void (*ptrFncEscreve)(void *ptrElemento);
} Arvore;

void CriaArvore(Arvore *ptrArvore,
                int  (*ptrFncCompara)(void *ptrElemento, void *ptrChave),
                int  (*ptrFncCopia)  (void *ptrDestino , void *ptrOrigem),
                void (*ptrFncEscreve)(void *ptrElemento));
Arvore* CriaArvore2(int  (*ptrFncCompara)(void *ptrElemento, void *ptrChave),
                    int  (*ptrFncCopia)  (void *ptrDestino , void *ptrOrigem),
                    void (*ptrFncEscreve)(void *ptrElemento));

int InsereArvorePai(Arvore *ptrArvore, void *ptrChavePai, char lado, void *ptrElemento);
int ConsultaArvore(Arvore *ptrArvore, void *ptrChave, void *ptrElementoSaida);
int AlteraArvore(Arvore *ptrArvore, void *ptrChave, void *ptrNovo);
void* ExcluiArvore(Arvore *ptrArvore, void *ptrChave);
void DestroiArvore(Arvore *ptrArvore);

void CaminhaPreFixado(Arvore *ptrArvore);
void CaminhaInFixado (Arvore *ptrArvore);
void CaminhaPosFixado(Arvore *ptrArvore);
void CaminhaAmplitude(Arvore *ptrArvore);

int ContaNos(Arvore *ptrArvore);
int ContaNosFolha(Arvore *ptrArvore);
void EspelhaArovreBinaria(Arvore *ptrArvore);
int ComparaArovreBinaria(Arvore *ptrArvore1, Arvore *ptrArvore2);
void EscreveArovreBinariaDuplicado(Arvore *ptrArvore);
int EstaContida(Arvore *ptrArvore1, Arvore *ptrArvore2);
int ObtemNivel(Arvore *ptrArvore, void *ptrChave);
int CalculaAlturaArvore(Arvore *ptrArvore);


// Arvore Binaria de Busca
int InsereArvoreBinariaBusca(Arvore *ptrArvore, void *ptrElemento);
int InsereArvoreBinariaBusca_Opcao_02(Arvore *ptrArvore, void *ptrElemento);
int ConsultaArvoreBinariaBusca(Arvore *ptrArvore, void *ptrChave, void *ptrElementoSaida);
int AlteraArvoreBinariaBusca(Arvore *ptrArvore, void *ptrChave, void *ptrNovo);
void* ExcluiArvoreBinariaBusca(Arvore *ptrArvore, void *ptrChave);

// Arvore AVL
int CalculaFB(Arvore* ptrArvore);
int SetaFB(Arvore* ptrArvore);
void BalanceiaAVL(Arvore *ptrArvore);

#endif // ARVOREBINARIA_H_INCLUDED
