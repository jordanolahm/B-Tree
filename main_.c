#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArvoreBinaria.h"
#include "Int.h"

#include "Utilitarios.h"

void MontaArvoreBinaria(Arvore *ptrArvore)
{
    int *ptrDado, pai;

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 0;
    *ptrDado = 1;
    InsereArvorePai(ptrArvore, &pai, 'e', ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 1;
    *ptrDado = 2;
    InsereArvorePai(ptrArvore, &pai, 'e', ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 1;
    *ptrDado = 3;
    InsereArvorePai(ptrArvore, &pai, 'd', ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 2;
    *ptrDado = 4;
    InsereArvorePai(ptrArvore, &pai, 'e', ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 2;
    *ptrDado = 5;
    InsereArvorePai(ptrArvore, &pai, 'd', ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 3;
    *ptrDado = 6;
    InsereArvorePai(ptrArvore, &pai, 'e', ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    pai      = 3;
    *ptrDado = 7;
    InsereArvorePai(ptrArvore, &pai, 'd', ptrDado);
}

void MontaArvoreBinariaBusca(Arvore *ptrArvore)
{
    int *ptrDado;

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 50;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 25;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 75;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 10;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 40;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 60;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 90;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 1;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 15;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 30;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 45;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 55;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 70;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 80;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 100;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);
}

void MontaArvoreBinariaBusca2(Arvore *ptrArvore)
{
    int *ptrDado;

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 50;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 25;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 10;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 40;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 1;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 15;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 30;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 45;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);
}

void MontaArvoreBinariaBuscaDuplicado(Arvore *ptrArvore)
{
    int *ptrDado;

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 50;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 25;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 75;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 10;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 50;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 10;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 90;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 1;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 25;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 30;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 75;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 55;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 75;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 1;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 10;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);
}

void Monta_Balanceia_AVL(Arvore *ptrArvore)
{
    int *ptrDado;

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 1;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 10;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 25;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 90;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 80;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 100;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 15;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 40;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 60;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 75;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 55;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 30;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 45;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 70;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 50;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);
}

void Monta_Balanceia_AVL2(Arvore *ptrArvore)
{
    int *ptrDado;

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 50;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 20;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 70;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 60;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 90;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);

    ptrDado  = (int *) malloc(sizeof(int));
    *ptrDado = 95;
    InsereArvoreBinariaBusca(ptrArvore, ptrDado);
}

int main()
{
    Arvore arv, arv2;
    int *ptrDado, pai, aux;
    char lado, opcao;

//    Arvore arv, *ptrArv;
//    ptrArv = CriaArvore2(ComparaInt, CopiaInt, EscreveInt);
//    ptrArv = (Arvore *) malloc(sizeof(Arvore));
//    CriaArvore(ptrArv, ComparaInt, CopiaInt, EscreveInt);


    CriaArvore(&arv, ComparaInt, CopiaInt, EscreveInt);
    CriaArvore(&arv2, ComparaInt, CopiaInt, EscreveInt);

    MontaArvoreBinariaBusca( &arv );
    printf("%d", ContaNosFolha( &arv ) );

/*
    MontaArvoreBinariaBuscaDuplicado( &arv );
    MontaArvoreBinariaBusca( &arv );
    MontaArvoreBinariaBusca( &arv2 );
    Monta_Balanceia_AVL( &arv );
    printf("%d", ContaNos( &arv ) );
    printf("%d", ContaNosFolha( &arv ) );
    CaminhaPreFixado( &arv );
    EspelhaArovreBinaria( &arv );
    CaminhaPreFixado( &arv );
    printf("%d", ComparaArovreBinaria(&arv, &arv2));
*/
    EscreveArovreBinariaDuplicado( &arv );

    do
    {
        system("cls");
        printf("\nB - Inserir Arvore Binaria de Busca");
        printf("\nI - Inserir");
        printf("\nC - Consultar");
        printf("\nE - Excluir");
        printf("\nA - Alterar");
        printf("\nR - Caminhamento prefixado");
        printf("\nO - Caminhamento posfixado");
        printf("\nM - Caminhamento infixado");
        printf("\nL - Caminhamento em Amplitude");
        printf("\nS - Sair");

        limpaBufferTeclado();
        opcao = toupper(getch());
        switch( opcao )
        {
            case 'B':
            {
                ptrDado  = (int *) malloc(sizeof(int));

                if ( !ptrDado )
                {
                    printf("\nNao ha memoria suficiente...");
                    break;
                }

                printf("\nEntre com o valor a ser inserido na arvore...");
                limpaBufferTeclado();
                scanf("%d", ptrDado);

                if (InsereArvoreBinariaBusca(&arv, ptrDado))
                    printf("\nInsercao realizada com sucesso...");
                else
                    printf("\nProblemas na insercao...");
            }
            break;
            case 'I':
            {
                ptrDado  = (int *) malloc(sizeof(int));

                if ( !ptrDado )
                {
                    printf("\nNao ha memoria suficiente...");
                    break;
                }

                printf("\nEntre com o valor a ser inserido na arvore...");
                limpaBufferTeclado();
                scanf("%d", ptrDado);

                printf("\nEntre com a chave do pai...");
                limpaBufferTeclado();
                scanf("%d", &pai);

                printf("\nEntre com o lado da insercao...");
                limpaBufferTeclado();
                scanf("%c", &lado);

                if (InsereArvorePai(&arv, &pai, lado, ptrDado))
                    printf("\nInsercao realizada com sucesso...");
                else
                    printf("\nProblemas na insercao...");
            }
            break;
            case 'C':
            {
                printf("\nEntre com a chave a ser consultada...");
                limpaBufferTeclado();
                scanf("%d", &pai);

                if (ConsultaArvore(&arv, &pai, &aux))
                    printf("\nValor encontrado...");
                else
                    printf("\nValor nao encontrado...");
            }
            break;
            case 'E':
            {
                printf("\nEntre com a chave a ser excluida");
                limpaBufferTeclado();
                scanf("%d", &pai);

                ptrDado = ExcluiArvoreBinariaBusca(&arv, &pai);
                if ( ptrDado )
                {
                    printf("\nValor encontrado e excluido...");
                    free( ptrDado );
                }
                else
                    printf("\nValor nao encontrado...");
            }
            break;
            case 'A':
            {
                printf("\nEntre com a chave a ser alterada");
                limpaBufferTeclado();
                scanf("%d", &pai);

                printf("\nEntre com o novo valor");
                limpaBufferTeclado();
                scanf("%d", &aux);

                if ( AlteraArvore(&arv, &pai, &aux) )
                {
                    printf("\nValor encontrado e alterado...");
                }
                else
                    printf("\nValor nao encontrado...");
            }
            break;
            case 'R':
            {
                printf("\n\nPrefixado: ");
                CaminhaPreFixado( &arv );
            }
            break;
            case 'O':
            {
                printf("\n\nPosfixado: ");
                CaminhaPosFixado( &arv );
            }
            break;
            case 'M':
            {
                printf("\n\nInfixado: ");
                CaminhaInFixado ( &arv );
            }
            break;
            case 'L':
            {
                printf("\n\nAmplitude: ");
                CaminhaAmplitude( &arv );
            }
            break;
        }

        getch();

    }while(opcao != 'S');

    return 0;
}
