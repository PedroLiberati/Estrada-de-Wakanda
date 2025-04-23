#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

double calcularVizinhanca(int cidade1, int cidade2, int T) {
    return (cidade2 - cidade1) / 2.0;
}

Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        return NULL; 
    }
    
    Estrada *estrada = malloc(sizeof(Estrada));
    if (!estrada) {
        fclose(arquivo);
        return NULL; 
    }
    
    fscanf(arquivo, "%d", &estrada->T);  
    fscanf(arquivo, "%d", &estrada->N);
    
    estrada->C = malloc(estrada->N * sizeof(Cidade));
    if (!estrada->C) {
        fclose(arquivo);
        free(estrada);
        return NULL;
    }
  
    for (int i = 0; i < estrada->N; i++) {
        fscanf(arquivo, "%d %s", &estrada->C[i].Posicao, estrada->C[i].Nome);
    }
    
    fclose(arquivo);
    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return -1.0;  
    }
    
    double menorVizinhanca = estrada->T; 
    for (int i = 1; i < estrada->N; i++) {
        double vizinhanca = calcularVizinhanca(estrada->C[i - 1].Posicao, estrada->C[i].Posicao, estrada->T);
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }
    
    free(estrada->C);
    free(estrada);
    
    return menorVizinhanca;
}


char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return NULL;  
    }
    
    double menorVizinhanca = estrada->T;
    char *cidade = NULL;
    
    for (int i = 1; i < estrada->N; i++) {
        double vizinhanca = calcularVizinhanca(estrada->C[i - 1].Posicao, estrada->C[i].Posicao, estrada->T);
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            cidade = estrada->C[i].Nome;
        }
    }
    
    free(estrada->C);
    free(estrada);
    
    return cidade;
}
