#include <stdlib.h>
#include <stdio.h>

#include "ArvoreBinaria.h"
#include "FilaDinamica.h"
#include "Int.h"

void CriaArvore(Arvore *ptrArvore,
                int  (*ptrFncCompara)(void *ptrElemento, void *ptrChave),
                int  (*ptrFncCopia)  (void *ptrDestino , void *ptrOrigem),
                void (*ptrFncEscreve)(void *ptrElemento))
{
    ptrArvore->ptrRaiz       = NULL;
    ptrArvore->ptrFncCompara = ptrFncCompara;
    ptrArvore->ptrFncCopia   = ptrFncCopia;
    ptrArvore->ptrFncEscreve = ptrFncEscreve;
}
Arvore* CriaArvore2(int  (*ptrFncCompara)(void *ptrElemento, void *ptrChave),
                    int  (*ptrFncCopia)  (void *ptrDestino , void *ptrOrigem),
                    void (*ptrFncEscreve)(void *ptrElemento))
{
    Arvore *ptrArvore = (Arvore *) malloc(sizeof(Arvore));

    if ( !ptrArvore )
        return NULL;

    ptrArvore->ptrRaiz       = NULL;
    ptrArvore->ptrFncCompara = ptrFncCompara;
    ptrArvore->ptrFncCopia   = ptrFncCopia;
    ptrArvore->ptrFncEscreve = ptrFncEscreve;

    return ptrArvore;
}
NoArvore* CriaNoArvore(void *ptrDado)
{
    NoArvore *ptrNo = (NoArvore *) malloc(sizeof(NoArvore));

    if ( ptrNo )
    {
        ptrNo->ptrEsq  = NULL;
        ptrNo->ptrDado = ptrDado;
        ptrNo->ptrDir  = NULL;
        ptrNo->fFB     = 0;
    }

    return ptrNo;
}
NoArvore* ConsultaArvoreLocal(NoArvore *ptrRaiz, void *ptrChave, int (*ptrFncCompara)(void *ptrElemento, void *ptrChave))
{
    NoArvore *ptrNo = NULL;
    if ( ptrRaiz )
    {
        if (ptrFncCompara(ptrRaiz->ptrDado, ptrChave) == 0)
            ptrNo = ptrRaiz;
        else
        {
            ptrNo = ConsultaArvoreLocal(ptrRaiz->ptrEsq, ptrChave, ptrFncCompara);
            if ( !ptrNo )
                ptrNo = ConsultaArvoreLocal(ptrRaiz->ptrDir, ptrChave, ptrFncCompara);
        }
    }
    return ptrNo;
}
int ConsultaArvore(Arvore *ptrArvore, void *ptrChave, void *ptrElementoSaida)
{
    NoArvore *ptrNo = ConsultaArvoreLocal(ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);

    if ( !ptrNo )
        return 0;

    ptrArvore->ptrFncCopia(ptrElementoSaida, ptrNo->ptrDado);
    return 1;
}
int AlteraArvore(Arvore *ptrArvore, void *ptrChave, void *ptrNovo)
{
    NoArvore *ptrNo = ConsultaArvoreLocal(ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);

    if ( !ptrNo )
        return 0;

    ptrArvore->ptrFncCopia(ptrNo->ptrDado, ptrNovo);
    return 1;
}
int InsereArvorePai(Arvore *ptrArvore, void *ptrChavePai, char lado, void *ptrElemento)
{
    // localiza pai do novo no/elemento
    NoArvore *ptrPai = ConsultaArvoreLocal(ptrArvore->ptrRaiz, ptrChavePai, ptrArvore->ptrFncCompara);
    NoArvore *ptrNo  = CriaNoArvore( ptrElemento );
    if ( !ptrNo )
        return -1;

    if ( !ptrArvore->ptrRaiz )  // se a arvore esta vazia, insere na raiz
    {
        ptrArvore->ptrRaiz = ptrNo;
        return 1;
    }

    if ( !ptrPai )  // elemento pai nao encontrado
    {
        free( ptrNo );
        return -2;
    }

    if (lado == 'e')
    {
        ptrNo->ptrEsq  = ptrPai->ptrEsq;
        ptrPai->ptrEsq = ptrNo;
    }
    else
    {
        ptrNo->ptrDir  = ptrPai->ptrDir;
        ptrPai->ptrDir = ptrNo;
    }

    return 1;
}
void CaminhaAmplitudeLocal(Arvore *ptrArvore, void (*ptrFncEscreve)(void *ptrElemento))
{
    NoArvore *ptrNoAux;
    FilaDinamica fila;
    CriaFila(&fila, -1, NULL, NULL);

    Enfileira(&fila, ptrArvore->ptrRaiz);
    while( fila.qtdeElementos )
    {
        ptrNoAux = Desenfileira( &fila );
        ptrFncEscreve( ptrNoAux->ptrDado );

        if ( ptrNoAux->ptrEsq )
            Enfileira(&fila, ptrNoAux->ptrEsq);
        if ( ptrNoAux->ptrDir )
            Enfileira(&fila, ptrNoAux->ptrDir);
    }
}
void CaminhaAmplitude(Arvore *ptrArvore)
{
    CaminhaAmplitudeLocal(ptrArvore, ptrArvore->ptrFncEscreve);
}
void CaminhaPreFixadoLocal(NoArvore *ptrRaiz, void (*ptrFncEscreve)(void *ptrElemento))
{
    if ( !ptrRaiz )
        return;

    printf("\n%d ", ptrRaiz->fFB);
    ptrFncEscreve( ptrRaiz->ptrDado );  // visita nó
    CaminhaPreFixadoLocal(ptrRaiz->ptrEsq, ptrFncEscreve);
    CaminhaPreFixadoLocal(ptrRaiz->ptrDir, ptrFncEscreve);
}
void CaminhaPreFixado(Arvore *ptrArvore)
{
    CaminhaPreFixadoLocal(ptrArvore->ptrRaiz, ptrArvore->ptrFncEscreve);
}
void CaminhaInFixadoLocal(NoArvore *ptrRaiz, void (*ptrFncEscreve)(void *ptrElemento))
{
    if ( !ptrRaiz )
        return;

    CaminhaInFixadoLocal(ptrRaiz->ptrEsq, ptrFncEscreve);
    printf("\n%d ", ptrRaiz->fFB);
    ptrFncEscreve( ptrRaiz->ptrDado );  // visita nó
    CaminhaInFixadoLocal(ptrRaiz->ptrDir, ptrFncEscreve);
}
void CaminhaInFixado(Arvore *ptrArvore)
{
    CaminhaInFixadoLocal(ptrArvore->ptrRaiz, ptrArvore->ptrFncEscreve);
}
void CaminhaPosFixadoLocal(NoArvore *ptrRaiz, void (*ptrFncEscreve)(void *ptrElemento))
{
    if ( !ptrRaiz )
        return;

    CaminhaPosFixadoLocal(ptrRaiz->ptrEsq, ptrFncEscreve);
    CaminhaPosFixadoLocal(ptrRaiz->ptrDir, ptrFncEscreve);
    printf("\n%d ", ptrRaiz->fFB);
    ptrFncEscreve( ptrRaiz->ptrDado );  // visita nó
}
void CaminhaPosFixado(Arvore *ptrArvore)
{
    CaminhaPosFixadoLocal(ptrArvore->ptrRaiz, ptrArvore->ptrFncEscreve);
}
void BuscaSucessorArvoreBinariaLocal(NoArvore *ptrRaiz, NoArvore **ptrSucessor)
{
    if ((*ptrSucessor)->ptrDir != NULL) // caminha recursivamente ate a extrema direita
        BuscaSucessorArvoreBinariaLocal(ptrRaiz, &(*ptrSucessor)->ptrDir);
	else
	{
        NoArvore *ptrNo = *ptrSucessor;   // salva referencia para no sucessor
		*ptrSucessor = (*ptrSucessor)->ptrEsq;

		ptrRaiz->ptrDado  = ptrNo->ptrDado;     // dados do ptrSuscessor tomam lugar no ptrRaiz
		free( ptrNo );
	}
}
void* ExcluiArvoreLocal(NoArvore **ptrRaiz, void *ptrChave, int (*ptrFncCompara)(void *ptrElemento, void *ptrChave))
{
    NoArvore *ptrNoAux = NULL;
    void *ptrElemento  = NULL;

    if ( *ptrRaiz )
    {
        if (ptrFncCompara((*ptrRaiz)->ptrDado, ptrChave) == 0)
        {
            ptrElemento = (*ptrRaiz)->ptrDado;

            // verifica se ha filhos
            if ((*ptrRaiz)->ptrEsq && (*ptrRaiz)->ptrDir) // ha filhos (aa esquerda e aa direta)
                BuscaSucessorArvoreBinariaLocal(*ptrRaiz, &(*ptrRaiz)->ptrEsq);
            else
            {
                ptrNoAux = *ptrRaiz;

                if ((*ptrRaiz)->ptrEsq == NULL) // se nao tem subArvore esquerda
                    *ptrRaiz = (*ptrRaiz)->ptrDir;
                else
                if ((*ptrRaiz)->ptrDir == NULL) // se nao tem subArvore direira
                    *ptrRaiz = (*ptrRaiz)->ptrEsq;

                // libera memoria da estrutura NoArvore
                free( ptrNoAux );
            }
		}
		else
		{
			// elemento encontrado e excluido da subarvore aa esquerda
			ptrElemento = ExcluiArvoreLocal(&(*ptrRaiz)->ptrEsq, ptrChave, ptrFncCompara);
			if ( !ptrElemento )
				ptrElemento = ExcluiArvoreLocal(&(*ptrRaiz)->ptrDir, ptrChave, ptrFncCompara);
		}
    }

    // retorna dado excluido ou NULL
    return ptrElemento;
}
void* ExcluiArvore(Arvore *ptrArvore, void *ptrChave)
{
    return ExcluiArvoreLocal(&ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);
}
void DestroiArvoreLocal(NoArvore **ptrRaiz)
{
    if (*ptrRaiz == NULL)
        return;

    DestroiArvoreLocal( &(*ptrRaiz)->ptrEsq );
    DestroiArvoreLocal( &(*ptrRaiz)->ptrDir );

    free( (*ptrRaiz)->ptrDado );
    free( *ptrRaiz );
    *ptrRaiz = NULL;
}
void DestroiArvore(Arvore *ptrArvore)
{
    DestroiArvoreLocal( &ptrArvore->ptrRaiz );
}
void DestroiArvoreLocal2(NoArvore *ptrRaiz)
{
    if (ptrRaiz == NULL)
        return;

    DestroiArvoreLocal2( ptrRaiz->ptrEsq );
    DestroiArvoreLocal2( ptrRaiz->ptrDir );

    free( ptrRaiz->ptrDado );
    free( ptrRaiz );
}
void DestroiArvore2(Arvore *ptrArvore)
{
    DestroiArvoreLocal2( ptrArvore->ptrRaiz );
    ptrArvore->ptrRaiz = NULL;
}


int ContaNosRec(NoArvore *ptrRaiz)
{
	if(!ptrRaiz) return 0;

	return 1 + ContaNosRec(ptrRaiz->ptrEsq) + ContaNosRec(ptrRaiz->ptrDir);
}
int ContaNos(Arvore *ptrArvore)
{
	return ContaNosRec(ptrArvore->ptrRaiz);
}

int ContaNosFolhaRec(NoArvore *ptrRaiz)
{
    if ( !ptrRaiz )
        return 0;

    if ( !ptrRaiz->ptrEsq &&
         !ptrRaiz->ptrDir   )
            return 1;

    return ContaNosFolhaRec( ptrRaiz->ptrEsq ) + ContaNosFolhaRec( ptrRaiz->ptrDir );
}
int ContaNosFolha(Arvore *ptrArvore)
{
    return ContaNosFolhaRec( ptrArvore->ptrRaiz );
}

int ObtemNivelRec(NoArvore *ptrRaiz, void *ptrChave, int (*ptrFncCompara)(void*, void*))
{
    if(!ptrRaiz)
        return -1;

	if(ptrFncCompara(ptrRaiz->ptrDado, ptrChave)  == 0)
        return 0;

	int res = ObtemNivelRec(ptrRaiz->ptrEsq, ptrChave, ptrFncCompara);
	if(res >= 0)
        return res+1;

	return -1;
}
int ObtemNivel(Arvore *ptrArvore, void *ptrChave)
{
	return ObtemNivelRec(ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);
}

int CalculaAlturaArvoreRec(NoArvore *ptrRaiz)
{
    if( !ptrRaiz )
        return 0;

	int h_esq = CalculaAlturaArvoreRec(ptrRaiz->ptrEsq);
	int h_dir = CalculaAlturaArvoreRec(ptrRaiz->ptrDir);

	return h_esq>h_dir ? h_esq+1 : h_dir+1;
}
int CalculaAlturaArvore(Arvore *ptrArvore)
{
	return CalculaAlturaArvoreRec(ptrArvore->ptrRaiz);
}

int ComparaArovreBinariaRec(NoArvore *ptrRaiz1, NoArvore *ptrRaiz2, int (*ptrFncCompara)(void*, void*))
{
    int res = 0;

    if ( !ptrRaiz1 && !ptrRaiz2 )
        res = 1;
    else
    if ( !ptrRaiz1 )
        res = 0;
    else
    if ( !ptrRaiz2 )
        res = 0;
    else
    if ( !ptrFncCompara(ptrRaiz1->ptrDado, ptrRaiz2->ptrDado) )
    {
        res = ComparaArovreBinariaRec(ptrRaiz1->ptrEsq, ptrRaiz2->ptrEsq, ptrFncCompara);
        if ( res )
            res = ComparaArovreBinariaRec(ptrRaiz1->ptrDir, ptrRaiz2->ptrDir, ptrFncCompara);
    }

    return res;
}
int ComparaArovreBinaria(Arvore *ptrArvore1, Arvore *ptrArvore2)
{
    return ComparaArovreBinariaRec(ptrArvore1->ptrRaiz, ptrArvore2->ptrRaiz, ptrArvore1->ptrFncCompara);
}

void EspelhaArovreBinariaRec(NoArvore *ptrRaiz)
{
    if ( ptrRaiz )
    {
        NoArvore *ptrAux = ptrRaiz->ptrDir;
        ptrRaiz->ptrDir  = ptrRaiz->ptrEsq;
        ptrRaiz->ptrEsq  = ptrAux;

        EspelhaArovreBinariaRec( ptrRaiz->ptrEsq );
        EspelhaArovreBinariaRec( ptrRaiz->ptrDir );
    }
}
void EspelhaArovreBinaria(Arvore *ptrArvore)
{
    EspelhaArovreBinariaRec( ptrArvore->ptrRaiz );
}

/*
05) Implemente a rotina cujo protótipo está definido abaixo e que verifique se a árvore em ptrSubArvore está contida na árvore ptrArvore (retorno 1 – um) ou não (retorno 0 – zero).
int EstaContidaRec(NoArvore *ptrRaiz, NoArvore *ptrSubRaiz , int (*ptrFncCompara)(void*, void*))
{     ????     }
int EstaContida(Arvore *ptrArvore, Arvore *ptrSubArvore)
{     return EstaContidaRec(ptrArvore->ptrRaiz, ptrSubArvore->ptrRaiz, ptrArvore->ptrFncCompara);     }
*/
int EstaContidaRec(NoArvore *ptrRaiz, NoArvore *ptrSubRaiz, int (*ptrFncCompara)(void*, void*))
{
    int res = 0;

    if ( !ptrSubRaiz )
        res = 1;
    else
    if ( !ptrRaiz )
        res = 0;
    else
    if ( !ptrFncCompara(ptrRaiz->ptrDado, ptrSubRaiz->ptrDado) )
    {
        res = EstaContidaRec(ptrRaiz->ptrEsq, ptrSubRaiz->ptrEsq, ptrFncCompara);
        if ( res )
            res = EstaContidaRec(ptrRaiz->ptrDir, ptrSubRaiz->ptrDir, ptrFncCompara);
    }

    return res;
}
int EstaContida(Arvore *ptrArvore, Arvore *ptrSubArvore)
{
    return EstaContidaRec(ptrArvore->ptrRaiz, ptrSubArvore->ptrRaiz, ptrArvore->ptrFncCompara);
}

void EscreveArovreBinariaDuplicadoRec_SubRaiz(NoArvore *ptrRaiz, NoArvore *ptrSubRaiz,
        int (*ptrFncCompara)(void*, void*), void (*ptrFncEscreve)(void *ptrElemento))
{
    if ( !ptrRaiz || !ptrSubRaiz )
        return;

    if (ptrRaiz!=ptrSubRaiz && !ptrFncCompara(ptrRaiz->ptrDado, ptrSubRaiz->ptrDado))
    {
        printf("\nElemento encontrado...");
        ptrFncEscreve( ptrRaiz->ptrDado );
        return;
    }

//    printf("\nElemento:%d - %d", *((int*)ptrRaiz->ptrDado), *((int*)ptrSubRaiz->ptrDado));

    // procura raiz nas subarvores Esq / Dir
    EscreveArovreBinariaDuplicadoRec_SubRaiz(ptrRaiz, ptrSubRaiz->ptrEsq, ptrFncCompara, ptrFncEscreve);
    EscreveArovreBinariaDuplicadoRec_SubRaiz(ptrRaiz, ptrSubRaiz->ptrDir, ptrFncCompara, ptrFncEscreve);
}
void EscreveArovreBinariaDuplicadoRec_Raiz(NoArvore *ptrRaiz, NoArvore *ptrSubRaiz,
        int (*ptrFncCompara)(void*, void*), void (*ptrFncEscreve)(void *ptrElemento))
{
    if ( !ptrRaiz || !ptrSubRaiz )
        return;

    // procura raiz nas subarvores Esq / Dir
    EscreveArovreBinariaDuplicadoRec_SubRaiz(ptrRaiz, ptrSubRaiz, ptrFncCompara, ptrFncEscreve);

    // procura subarvores Esq / Dir
    EscreveArovreBinariaDuplicadoRec_Raiz(ptrRaiz->ptrEsq, ptrSubRaiz, ptrFncCompara, ptrFncEscreve);
    EscreveArovreBinariaDuplicadoRec_Raiz(ptrRaiz->ptrDir, ptrSubRaiz, ptrFncCompara, ptrFncEscreve);
}
void EscreveArovreBinariaDuplicado(Arvore *ptrArvore)
{
    EscreveArovreBinariaDuplicadoRec_Raiz(
        ptrArvore->ptrRaiz, ptrArvore->ptrRaiz, ptrArvore->ptrFncCompara, ptrArvore->ptrFncEscreve);
}

double ResolveExpRec(NoArvore *ptrRaiz, int (*ptrFncCompara)(void *, void *))
{
	if(ptrFncCompara(ptrRaiz->ptrDado, "+") == 0)
		return ResolveExpRec(ptrRaiz->ptrEsq, ptrFncCompara) + ResolveExpRec(ptrRaiz->ptrDir, ptrFncCompara);
    if(ptrFncCompara(ptrRaiz->ptrDado, "-") == 0)
		return ResolveExpRec(ptrRaiz->ptrEsq, ptrFncCompara) - ResolveExpRec(ptrRaiz->ptrDir, ptrFncCompara);
    if(ptrFncCompara(ptrRaiz->ptrDado, "*") == 0)
		return ResolveExpRec(ptrRaiz->ptrEsq, ptrFncCompara) * ResolveExpRec(ptrRaiz->ptrDir, ptrFncCompara);
    if(ptrFncCompara(ptrRaiz->ptrDado, "/") == 0)
		return ResolveExpRec(ptrRaiz->ptrEsq, ptrFncCompara) / ResolveExpRec(ptrRaiz->ptrDir, ptrFncCompara);

	return atof(ptrRaiz->ptrDado);
}
double ResolveExp(Arvore *ptrArvore)
{
	return ResolveExpRec(ptrArvore->ptrRaiz, ptrArvore->ptrFncCompara);
}


// Arvore Binaria de Busca
NoArvore** BuscaBB_NULL_InsereBinariaBusca_Opcao_02(NoArvore *ptrRaiz, void *ptrElemento,
                  int(*ptrFncCompara)(void *ptrElemento1, void *ptrElemento2))
{
    int res = ptrFncCompara(ptrRaiz->ptrDado, ptrElemento);

    if (res < 0)
    {
        if ( !ptrRaiz->ptrDir )
            return &ptrRaiz->ptrDir;

        return BuscaBB_NULL_InsereBinariaBusca_Opcao_02(ptrRaiz->ptrDir, ptrElemento, ptrFncCompara);
    }

    if ( !ptrRaiz->ptrEsq )
        return &ptrRaiz->ptrEsq;

    return BuscaBB_NULL_InsereBinariaBusca_Opcao_02(ptrRaiz->ptrEsq, ptrElemento, ptrFncCompara);
}
int InsereArvoreBinariaBusca_Opcao_02(Arvore *ptrArvore, void *ptrElemento)
{
    NoArvore **ptrPosicao;

    if ( !ptrArvore->ptrRaiz )  // testa se arvore esta vazia
        ptrPosicao = &ptrArvore->ptrRaiz;
    else                        // busca posicao/endereco na arvore
        ptrPosicao = BuscaBB_NULL_InsereBinariaBusca_Opcao_02(ptrArvore->ptrRaiz, ptrElemento, ptrArvore->ptrFncCompara);

    NoArvore *ptrNo = CriaNoArvore( ptrElemento );
    if ( !ptrNo )
        return -1;

    *ptrPosicao = ptrNo;
    return 1;
}
int InsereArvoreBinariaBuscaRec(NoArvore **ptrRaiz, void *ptrElemento,
                  int(*ptrFncCompara)(void *ptrElemento1, void *ptrElemento2))
{
    if (*ptrRaiz == NULL)   // raiz nula, insere na raiz
    {
        *ptrRaiz = CriaNoArvore( ptrElemento );
        if ( *ptrRaiz )
            return 1;
        else
            return 0;
    }

    int res = ptrFncCompara((*ptrRaiz)->ptrDado, ptrElemento);

    if (res < 0)    // chama recursivamente para Direira ou Esquerda
        res = InsereArvoreBinariaBuscaRec(&(*ptrRaiz)->ptrDir, ptrElemento, ptrFncCompara);
    else
        res = InsereArvoreBinariaBuscaRec(&(*ptrRaiz)->ptrEsq, ptrElemento, ptrFncCompara);

    return res;
}
int InsereArvoreBinariaBusca(Arvore *ptrArvore, void *ptrElemento)
{
    return InsereArvoreBinariaBuscaRec(&ptrArvore->ptrRaiz, ptrElemento, ptrArvore->ptrFncCompara);
/*
    InsereArvoreBinariaBuscaRec(&ptrArvore->ptrRaiz, ptrElemento, ptrArvore->ptrFncCompara);
//    system("cls");
    BalanceiaAVL( ptrArvore );
    SetaFB( ptrArvore );
    printf("\n\n");
    CaminhaInFixado( ptrArvore );
*/
    return 1;
}
NoArvore* ConsultaArvoreBinariaBuscaLocal(NoArvore *ptrRaiz, void *ptrChave, int (*ptrFncCompara)(void *ptrElemento, void *ptrChave))
{
    if ( !ptrRaiz )
        return NULL;

    int res = ptrFncCompara(ptrRaiz->ptrDado, ptrChave);
    if (res == 0)
        return ptrRaiz;

    if (res > 0)
        return ConsultaArvoreBinariaBuscaLocal(ptrRaiz->ptrEsq, ptrChave, ptrFncCompara);
    else
        return ConsultaArvoreBinariaBuscaLocal(ptrRaiz->ptrDir, ptrChave, ptrFncCompara);
}
int ConsultaArvoreBinariaBusca(Arvore *ptrArvore, void *ptrChave, void *ptrElementoSaida)
{
    NoArvore *ptrNo = ConsultaArvoreBinariaBuscaLocal(ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);

    if ( !ptrNo )
        return 0;

    ptrArvore->ptrFncCopia(ptrElementoSaida, ptrNo->ptrDado);
    return 1;
}
int ConsultaArvoreBinariaBuscaIterativo(Arvore *ptrArvore, void *ptrChave, void *ptrElementoSaida)
{
    int res;
    NoArvore *ptrNo = ptrArvore->ptrRaiz;

    while( !ptrNo )
    {
        res = ptrArvore->ptrFncCompara(ptrNo->ptrDado, ptrChave);
        if (res == 0)
            break;

        if (res > 0)
            ptrNo = ptrNo->ptrEsq;
        else
            ptrNo = ptrNo->ptrDir;
    }

    if ( !ptrNo )
        return 0;

    ptrArvore->ptrFncCopia(ptrElementoSaida, ptrNo->ptrDado);
    return 1;
}
int AlteraArvoreBinariaBusca(Arvore *ptrArvore, void *ptrChave, void *ptrNovo)
{
    NoArvore *ptrNo = ConsultaArvoreBinariaBuscaLocal(ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);

    if ( !ptrNo )
        return 0;

    ptrArvore->ptrFncCopia(ptrNo->ptrDado, ptrNovo);
    return 1;
}
void* ExcluiArvoreBinariaBuscaLocal(NoArvore **ptrRaiz, void *ptrChave, int (*ptrFncCompara)(void *ptrElemento, void *ptrChave))
{
    int res;
    NoArvore *ptrNoAux = NULL;
    void *ptrElemento  = NULL;

    if ( *ptrRaiz )
    {
        res = ptrFncCompara((*ptrRaiz)->ptrDado, ptrChave);
        if (res == 0)
        {
            ptrElemento = (*ptrRaiz)->ptrDado;

            // verifica se ha filhos
            if ((*ptrRaiz)->ptrEsq && (*ptrRaiz)->ptrDir) // ha filhos (aa esquerda e aa direta)
                BuscaSucessorArvoreBinariaLocal(*ptrRaiz, &(*ptrRaiz)->ptrEsq);
            else
            {
                ptrNoAux = *ptrRaiz;

                if ((*ptrRaiz)->ptrEsq == NULL) // se nao tem subArvore esquerda
                    *ptrRaiz = (*ptrRaiz)->ptrDir;
                else
                if ((*ptrRaiz)->ptrDir == NULL) // se nao tem subArvore direira
                    *ptrRaiz = (*ptrRaiz)->ptrEsq;

                // libera memoria da estrutura NoArvore
                free( ptrNoAux );
            }
        }
        else
        if (res > 0)    // se existir, elemento estara na subArvore direita
            ptrElemento = ExcluiArvoreBinariaBuscaLocal(&(*ptrRaiz)->ptrEsq, ptrChave, ptrFncCompara);
        else    // se existir, elemento estara na subArvore esquerda
            ptrElemento = ExcluiArvoreBinariaBuscaLocal(&(*ptrRaiz)->ptrDir, ptrChave, ptrFncCompara);
    }

    // retorna dado excluido ou NULL
    return ptrElemento;
}
void* ExcluiArvoreBinariaBusca(Arvore *ptrArvore, void *ptrChave)
{
    return ExcluiArvoreBinariaBuscaLocal(&ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);
}
/*
void* BuscaSucessorIterativo(NoArvore *ptrRaiz)
{
    void *ptrElemento  = NULL;
    NoArvore *ptrNoPai = ptrRaiz;

    while( ptrRaiz->ptrDir ) // caminha ate a extrema esquerda
    {
        ptrNoPai = ptrRaiz;
        ptrRaiz  = ptrRaiz->ptrDir;
    }

    ptrNoPai->ptrDir = ptrRaiz->ptrEsq; // exclui no sucessor
    ptrElemento      = ptrRaiz->ptrDado;
    free( ptrRaiz );

    return ptrElemento;
}
void* ExcluiArvoreBinariaBuscaIterativoLocal(NoArvore **ptrRaiz, void *ptrChave, int (*ptrFncCompara)(void *ptrElemento, void *ptrChave))
{
    int res;
    void *ptrElemento       = NULL;
    NoArvore *ptrNo         = *ptrRaiz;
    NoArvore **ptrNoPai     = ptrRaiz;

    while( !ptrNo ) // busca pelo elemento procurado
    {
        res = ptrArvore->ptrFncCompara(ptrNo->ptrDado, ptrChave);
        if (res == 0)
            break;

        ptrNoPai = ptrNo;
        if (res > 0)
            ptrNo = ptrNo->ptrEsq;
        else
            ptrNo = ptrNo->ptrDir;
    }

    if (ptrNo == ptrArvore->ptrRaiz)
    {

    }

    if ( ptrNo )    // se encontrou elemento
    {
        ptrElemento = ptrNo->ptrDado;

        if ( !ptrNo->ptrEsq ) // se nao tem subArvore esquerda
            *ptrRaiz = (*ptrRaiz)->ptrDir;
        else
        if ( !ptrNo->ptrDir ) // se nao tem subArvore direira
            *ptrRaiz = (*ptrRaiz)->ptrEsq;

                // libera memoria da estrutura NoArvore
                free( ptrNoAux );
        ptrNo->ptrDado = BuscaSucessorIterativo( ptrNo->ptrEsq );
    }

    // retorna dado excluido ou NULL
    return ptrElemento;
}
void* ExcluiArvoreBinariaBuscaIterativo(Arvore *ptrArvore, void *ptrChave)
{
    return ExcluiArvoreBinariaBuscaIterativoLocal(&ptrArvore->ptrRaiz, ptrChave, ptrArvore->ptrFncCompara);
}
*/


// Arvore AVL
int CalculaFB_Local(NoArvore* ptrRaiz)
{
    if( !ptrRaiz )
        return 0;

    return CalculaAlturaArvoreRec(ptrRaiz->ptrEsq) - CalculaAlturaArvoreRec(ptrRaiz->ptrDir);
}
int CalculaFB(Arvore* ptrArvore)
{
    return CalculaFB_Local( ptrArvore->ptrRaiz );
}

int SetaFB_Local(NoArvore* ptrRaiz)
{
    if( !ptrRaiz )
        return 0;

	int h_esq = SetaFB_Local( ptrRaiz->ptrEsq );
	int h_dir = SetaFB_Local( ptrRaiz->ptrDir );

	ptrRaiz->fFB = h_esq - h_dir;

	return h_esq>h_dir ? h_esq+1 : h_dir+1;
}
int SetaFB(Arvore* ptrArvore)
{
    return SetaFB_Local( ptrArvore->ptrRaiz );
}

NoArvore* RotacaoDireitaSimples(NoArvore *ptrRaiz)
{
    NoArvore *ptrNoAux = ptrRaiz->ptrEsq;
    ptrRaiz->ptrEsq    = ptrNoAux->ptrDir;
    ptrNoAux->ptrDir   = ptrRaiz;

    return ptrNoAux;
}
NoArvore* RotacaoDireitaDupla(NoArvore *ptrRaiz)
{
    NoArvore *ptrNoAux1 = ptrRaiz->ptrEsq,
             *ptrNoAux2 = ptrNoAux1->ptrDir;

    ptrNoAux1->ptrDir = ptrNoAux2->ptrEsq;
    ptrRaiz->ptrEsq   = ptrNoAux2->ptrDir;

    ptrNoAux2->ptrEsq = ptrNoAux1;
    ptrNoAux2->ptrDir = ptrRaiz;

    return ptrNoAux2;
}
NoArvore* RotacaoEsquerdaSimples(NoArvore *ptrRaiz)
{
    NoArvore *ptrNoAux = ptrRaiz->ptrDir;
    ptrRaiz->ptrDir    = ptrNoAux->ptrEsq;
    ptrNoAux->ptrEsq   = ptrRaiz;

    return ptrNoAux;
}
NoArvore* RotacaoEsquerdaDupla(NoArvore *ptrRaiz)
{
    NoArvore *ptrNoAux1 = ptrRaiz->ptrDir,
             *ptrNoAux2 = ptrNoAux1->ptrEsq;

    ptrRaiz->ptrDir   = ptrNoAux2->ptrEsq;
    ptrNoAux1->ptrEsq = ptrNoAux2->ptrDir;

    ptrNoAux2->ptrEsq = ptrRaiz;
    ptrNoAux2->ptrDir = ptrNoAux1;

    return ptrNoAux2;
}
NoArvore* BalanceiaAVL_Local(NoArvore *ptrRaiz) // igual ao SetaFB...
{
    if ( ptrRaiz )
    {
        ptrRaiz->ptrEsq = BalanceiaAVL_Local( ptrRaiz->ptrEsq );
        ptrRaiz->ptrDir = BalanceiaAVL_Local( ptrRaiz->ptrDir );

        SetaFB_Local( ptrRaiz );
        if (ptrRaiz->fFB == +2)
        {
            if(ptrRaiz->ptrEsq->fFB > 0)
                ptrRaiz = RotacaoDireitaSimples( ptrRaiz );
            else
                ptrRaiz = RotacaoDireitaDupla( ptrRaiz );
        }
        else
            if (ptrRaiz->fFB == -2)
            {
                if(ptrRaiz->ptrDir->fFB < 0)
                    ptrRaiz = RotacaoEsquerdaSimples( ptrRaiz );
                else
                    ptrRaiz = RotacaoEsquerdaDupla( ptrRaiz );
            }

//        ptrRaiz->ptrEsq = BalanceiaAVL_Local( ptrRaiz->ptrEsq );
//        ptrRaiz->ptrDir = BalanceiaAVL_Local( ptrRaiz->ptrDir );
    }

    return ptrRaiz;
}
void BalanceiaAVL(Arvore *ptrArvore)
{
    ptrArvore->ptrRaiz = BalanceiaAVL_Local( ptrArvore->ptrRaiz );
}
