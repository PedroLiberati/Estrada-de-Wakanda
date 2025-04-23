#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

int main() {
   
    FILE *Resposta = fopen("Resultado.txt", "w");
    if (!Resposta) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }


    Estrada *T1 = getEstrada("teste01.txt");
    if (T1) {
        fprintf(Resposta, "Comprimento da estrada: %d\n", T1->T);
        fprintf(Resposta, "Número de cidades: %d\n", T1->N);
    } else {
        fprintf(Resposta, "Erro ao obter informações sobre a estrada.\n");
    }

    double D1 = calcularMenorVizinhanca("teste01.txt");
    fprintf(Resposta, "Menor vizinhança: %.2f\n", D1);

    char *C1 = cidadeMenorVizinhanca("teste01.txt");
    if (C1) {
        fprintf(Resposta, "Cidade com a menor vizinhança: %s\n", C1);
    } else {
        fprintf(Resposta, "Erro ao obter cidade com menor vizinhança.\n");
    }

    fclose(Resposta);
    return 0;
}
