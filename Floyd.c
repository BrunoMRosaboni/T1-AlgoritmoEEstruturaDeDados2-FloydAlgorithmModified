#include <stdio.h>
#include <stdlib.h>
#include "Floyd.h"

void floyd(int **MatrizAdj, int N)
{
    int v, w, k, aux;

    for (k = 1; k < N+1; ++k)
    {
        for (v = 1; v < N+1; ++v)
        {
            for (w = 1; w < N+1; ++w)
            {
                //Verifica menor elemento
                aux = MatrizAdj[v][k] + MatrizAdj[k][w];
                if (MatrizAdj[v][w] > aux)
                {
                    MatrizAdj[v][w] = aux;
                }
            }
        }
    }
}

int *MaxColuna(int **MatrizAdj, int N)
{
    int *MaximaColuna=NULL, i, j;

    MaximaColuna=(int*)calloc((N+1), sizeof(int));

    for (i = 1; i < N+1; ++i)
    {
        MaximaColuna[i]=MatrizAdj[1][i];
        for (j = 1; j < N+1; ++j)
        {
            if (MaximaColuna[i] < MatrizAdj[j][i])
            {
                MaximaColuna[i]=MatrizAdj[j][i];
            }
        }
    }
    return MaximaColuna;
}

int VerticeCentral(int *VetMax, int N)
{
    int CentroVet, i, aux;

    aux=VetMax[1];
    for (i = 1; i < N+1; i++)
    {
        if(VetMax[i] < aux)
        {
            aux=VetMax[i];
            CentroVet = i;
        }
        else if (i == 1 && VetMax[i] <= aux)
        {
            CentroVet = 1;
        }
    }
    return CentroVet;
}

void Analisar(int **MatrizAdj, int CentroVet, int *VetorPessoasAnalisadas, int L)
{
    int i;

    for (i = 0; i < L; ++i)
    {
        if (MatrizAdj[CentroVet][VetorPessoasAnalisadas[i]] == INF)
        {
           printf("\nINF");
        }
        else
        {
            printf("\n%d", MatrizAdj[CentroVet][VetorPessoasAnalisadas[i]]);
        }
    }
    printf("\n");
}