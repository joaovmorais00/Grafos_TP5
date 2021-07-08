#include "tp5.h"

void preencheGrafo(int** matriz, int numArestas, int* origens, int* destinos, int* valores){
    for(int i=0; i<numArestas; i++){
        matriz[origens[i]-1][destinos[i]-1] = valores[i];
    }
}

char* obterSubstring(char* string, int inicio, int fim){
    char *newString = (char*) malloc(((fim - inicio) +1) * sizeof(char));
    strncpy(newString, string + inicio, ((fim - inicio) +1));
    return newString;
}

void dividirString(char* string, int* origem, int* destino, int* valor){
    int espacos=0, iDestino=0, iValor=0, fimString=0;
    for(int i=0; i<20; i++){
        if(string[i]==' ' && espacos==0){
            *origem = atoi(obterSubstring(string, 0, i-1));
            iDestino = i+1;
            espacos++;
        }else if(string[i]==' ' && espacos==1){
            *destino = atoi(obterSubstring(string, iDestino, i-1));
            iValor = i+1;
            espacos++;
        }else if(string[i]=='\0' && espacos==2){
            *valor = atoi(obterSubstring(string, iValor, i-1));
        }
    }
}

void imprimeMatriz(int** matriz, int linhas, int colunas){
    printf("\n");
    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            if(matriz[i][j] == infinito) printf("inf\t");
            else printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void matrizDistancias(int **grafo, int numVertices, int **distancias){
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            if(i!=j){
                if(grafo[i][j]==0) distancias[i][j] = infinito;
                else distancias[i][j] = grafo[i][j];
            }
        }
    }
    for(int k=0; k<numVertices; k++){
        for(int i=0; i<numVertices; i++){
            for(int j=0; j<numVertices; j++){
                if(distancias[i][j]>distancias[i][k] + distancias[k][j]){
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                }
            }
        }
    }
}

void confereCorte(int **grafo, int numVertices, int* origemArestas, int* destinoArestas, int numArestasCorte){
    int raiz, antiRaiz, capacidade=0, aux=0, aux2=0;
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            if(grafo[j][i]==0) aux++;
            if(grafo[i][j]==0) aux2++;
        }
        if(aux==numVertices) raiz= i+1;
        else aux = 0;
        if(aux2==numVertices) antiRaiz= i+1;
        else aux2 = 0;
    }
    for(int i=0; i<numArestasCorte; i++){
        capacidade += grafo[origemArestas[i]-1][destinoArestas[i]-1];
        grafo[origemArestas[i]-1][destinoArestas[i]-1] = 0;
    }
    int **distancias = (int **) calloc(numVertices, sizeof(int*));
    for(int i = 0; i<numVertices; i++) distancias[i] = (int *) calloc(numVertices, sizeof(int));
    matrizDistancias(grafo, numVertices, distancias);
    if(distancias[raiz-1][antiRaiz-1]==infinito){
        printf("\nAs Arestas: ");
        for(int i=0; i<numArestasCorte; i++) printf("%d->%d, ", origemArestas[i], destinoArestas[i]);
        printf("representam um corte de capacidade %d\n\n", capacidade);
    }else{
        printf("\nAs Arestas: ");
        for(int i=0; i<numArestasCorte; i++) printf("%d->%d, ", origemArestas[i], destinoArestas[i]);
        printf("não representam um corte\n");
    }
    for(int i =0; i<numVertices; i++) free(distancias[i]);
    free(distancias);
}



