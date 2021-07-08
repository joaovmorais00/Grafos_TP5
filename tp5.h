#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define infinito 999999999

void preencheGrafo(int** matriz, int numArestas, int* origens, int* destinos, int* valores);
char* obterSubstring(char* string, int inicio, int fim);
void dividirString(char* string, int* origem, int* destino, int* valor);
void imprimeMatriz(int** matriz, int linhas, int colunas);
void matrizDistancias(int **grafo, int numVertices, int **distancias);
void confereCorte(int **grafo, int numVertices, int* origemArestas, int* destinoArestas, int numArestasCorte);