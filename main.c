#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 64

typedef struct
{
    int n;
    int adj[MAX][MAX];
} Grafo;

int QuantidadeVertices(const char *nome_arquivo);
void inicializaGrafo(Grafo *g, int n);
void lerConexoes(const char *filename, Grafo *g);
void criaConexao(Grafo *g, int u, int v);
void encontraCliqueMaximo(Grafo *g, int clique[], int *maxCliqueSize);
void resultado(int maxCliqueSize, int clique[], int i);

int main(void)
{
    Grafo g;
    int numVertices;

    numVertices = QuantidadeVertices("conexoes.txt");
    inicializaGrafo(&g, numVertices);

    lerConexoes("conexoes.txt", &g);

    int clique[MAX];
    int maxCliqueSize;

    encontraCliqueMaximo(&g, clique, &maxCliqueSize);
  
    resultado(maxCliqueSize, clique, 0);
  
    return 0;
}

int QuantidadeVertices(const char *nome_arquivo)
{
    int numVertices;
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro no arquivo %s.\n", nome_arquivo);
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);
    fclose(arquivo);

    return numVertices;
}

void inicializaGrafo(Grafo *g, int n)
{
    g->n = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g->adj[i][j] = 0;
        }
    }
}

void lerConexoes(const char *nome_arquivo, Grafo *g)
{

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", nome_arquivo);
    }

    else
    {
        char buffer[100];
        fgets(buffer, sizeof(buffer), arquivo);

        int u, v;
        while (fscanf(arquivo, " %*c %d %d", &u, &v) == 2)
        {
            criaConexao(g, u - 1, v - 1);
        }

        fclose(arquivo);
    }
}

void criaConexao(Grafo *g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void encontraCliqueMaximo(Grafo *g, int clique[], int *maxCliqueSize)
{
    int n = g->n;
    int maxClique = 0;
    int cliqueTemp[MAX];

    for (int i = 0; i < pow(2, n); i++)
    {
        int cliqueSize = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (int)(pow(2, j)))
            {
                int conectado = 1;
                for (int k = 0; k < cliqueSize; k++)
                {
                    if (!g->adj[j][cliqueTemp[k]])
                    {
                        conectado = 0;
                        break;
                    }
                }
                if (conectado)
                {
                    cliqueTemp[cliqueSize++] = j;
                }
            }
        }
        if (cliqueSize > maxClique)
        {
            maxClique = cliqueSize;
            for (int j = 0; j < maxClique; j++)
            {
                clique[j] = cliqueTemp[j];
            }
        }
    }
    *maxCliqueSize = maxClique;
}

void resultado(int maxCliqueSize, int clique[], int i) {
    if (i == 0) {
        printf("Maior comunidade conectada tem %d membros e é: (", maxCliqueSize);
    }
    if (i < maxCliqueSize) {
        printf("%d", clique[i] + 1);
        if (i < maxCliqueSize - 1) {
            printf(", ");
        }
      
        resultado(maxCliqueSize, clique, i + 1);
    } else if (i == maxCliqueSize) {
        printf(")\n");
    }
}
