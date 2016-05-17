#include <stdio.h>
#include <stdlib.h>
#include "Floyd.h"

int main(void)
{
    int CasosTeste, N, M, p1, p2, L, j, CentroVet;
    int **MatrizAdj=NULL, i, k, *VetorPessoasAnalisadas=NULL, *VetMax=NULL;

    //Ler o Número de casos de teste
    scanf("%d", &CasosTeste);

    //Loop que executa os casos testes
    for (k = 0; k < CasosTeste; ++k)
    {
        //fflush(stdin);
        //Ler o Número de Pessoas no Facebook e o número de relações existentes, respectivamente
        scanf("%d %d", &N, &M);

        //Criando Matriz de Adjacência
        MatrizAdj=(int**)calloc((N+1), sizeof(int*));
        for (i = 0; i < (N+1); ++i)
        {
            MatrizAdj[i]=(int*)calloc((N+1), sizeof(int));
        }

        //Inicializando a matriz com valor "infinito"
        for (i = 1; i < N+1; ++i)
        {
            for (j = 1; j < N+1; ++j)
            {
                if (i != j)
                {
                    MatrizAdj[i][j] = INF;
                }
            }
        }

        //Inserindo as Relações na Matriz de Adjacência
        for (i = 0; i < M; ++i)
        {
            scanf("%d %d", &p1, &p2);
            MatrizAdj[p1][p2] = 1;
            MatrizAdj[p2][p1] = 1;
        }

        //Ler número de Pessoas que Zequinha quer analisar
        scanf("%d", &L);

        //Alocar vetor para pessoas a serem analisadas
        VetorPessoasAnalisadas=(int*)calloc(L, sizeof(int));
        //Ler as Pessoas que Zequinha quer analisar
        for (i = 0; i < L; ++i)
        {
            scanf("%d", &VetorPessoasAnalisadas[i]);
        }
        
        //Algoritmo Floyd
        floyd(MatrizAdj, N);
        //Retorna um vetor com os valores máximos de cada coluna da Matriz de Adjacência após a execução do Algoritmo Floyd
        VetMax=MaxColuna(MatrizAdj, N);
        //Encontra o vértice Central
        CentroVet=VerticeCentral(VetMax, N);
        printf("%d", CentroVet);

        //Analisar os outros pontos em relação ao termo central
        Analisar(MatrizAdj, CentroVet, VetorPessoasAnalisadas, L);

        //Desalocar o Vetor de pessoas
        free(VetorPessoasAnalisadas);

        //Desalocando a matriz de Adjacencia
        for (j = 0; j < (N+1); j++)
        {
            free(MatrizAdj[j]);
        }

        free(MatrizAdj);

        free(VetMax);
    }

    return 0;
}