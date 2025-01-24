#include <stdio.h>
#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para representar uma carta de cidade
typedef struct {
    char codigo[4]; // Código no formato "A01", "B02", etc.
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
} Carta;

void cadastrarCartas(Carta cartas[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    char estado;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        estado = 'A' + i; // Estados de A a H
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            Carta *carta = &cartas[i][j];
            sprintf(carta->codigo, "%c%02d", estado, j + 1);

            printf("\nCadastro da cidade %s:\n", carta->codigo);
            printf("Populacao: ");
            scanf("%d", &carta->populacao);
            printf("Area (km^2): ");
            scanf("%f", &carta->area);
            printf("PIB (em milhoes): ");
            scanf("%lf", &carta->pib);
            printf("Numero de pontos turisticos: ");
            scanf("%d", &carta->pontos_turisticos);
        }
    }
}

void exibirCartas(Carta cartas[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("\n---- Cartas cadastradas ----\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            Carta *carta = &cartas[i][j];
            printf("\nCidade %s:\n", carta->codigo);
            printf("Populacao: %d\n", carta->populacao);
            printf("Area: %.2f km^2\n", carta->area);
            printf("PIB: %.2f milhoes\n", carta->pib);
            printf("Pontos turisticos: %d\n", carta->pontos_turisticos);
        }
    }
}

int main() {
    Carta cartas[NUM_ESTADOS][CIDADES_POR_ESTADO];

    printf("--- Cadastro de Cartas: Super Trunfo - Paises ---\n");
    cadastrarCartas(cartas);

    exibirCartas(cartas);

    return 0;
}
