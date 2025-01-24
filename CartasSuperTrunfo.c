#include <stdio.h> // Biblioteca padrão para entrada e saída de dados.
#include <stdbool.h> // Biblioteca para utilizar o tipo booleano e validações.

// Definindo o número de estados e cidades por estado
#define NUM_ESTADOS 8 // Oito estados representados pelas letras de A a H.
#define CIDADES_POR_ESTADO 4 // Cada estado contém exatamente quatro cidades.

// Estrutura para representar uma carta de cidade
typedef struct {
    char codigo[4]; // Código da carta no formato "A01", "B02", etc., representando o estado e a cidade.
    int populacao; // População total da cidade.
    float area; // Área da cidade em quilômetros quadrados.
    double pib; // Produto Interno Bruto (PIB) da cidade em milhões.
    int pontos_turisticos; // Número de pontos turísticos na cidade.
} Carta;

// Função para validar se um valor é positivo.
bool validarValorPositivo(double valor) {
    return valor > 0;
}

void cadastrarCartas(Carta cartas[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    char estado;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        estado = 'A' + i; // Estados de A a H
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            Carta *carta = &cartas[i][j];
            sprintf(carta->codigo, "%c%02d", estado, j + 1);

            printf("\nCadastro da cidade %s:\n", carta->codigo);

            do {
                printf("Populacao: ");
                scanf("%d", &carta->populacao);
                if (!validarValorPositivo(carta->populacao)) {
                    printf("Erro: A populacao deve ser um valor positivo.\n");
                }
            } while (!validarValorPositivo(carta->populacao));

            do {
                printf("Area (km^2): ");
                scanf("%f", &carta->area);
                if (!validarValorPositivo(carta->area)) {
                    printf("Erro: A area deve ser um valor positivo.\n");
                }
            } while (!validarValorPositivo(carta->area));

            do {
                printf("PIB (em milhoes): ");
                scanf("%lf", &carta->pib);
                if (!validarValorPositivo(carta->pib)) {
                    printf("Erro: O PIB deve ser um valor positivo.\n");
                }
            } while (!validarValorPositivo(carta->pib));

            do {
                printf("Numero de pontos turisticos: ");
                scanf("%d", &carta->pontos_turisticos);
                if (!validarValorPositivo(carta->pontos_turisticos)) {
                    printf("Erro: O numero de pontos turisticos deve ser positivo.\n");
                }
            } while (!validarValorPositivo(carta->pontos_turisticos));
        }
    }
}

void exibirCartas(Carta cartas[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("\n---- Cartas cadastradas ----\n");
    printf("%-8s %-12s %-10s %-14s %-20s\n", "Codigo", "Populacao", "Area", "PIB (milhoes)", "Pontos Turisticos");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            Carta *carta = &cartas[i][j];
            printf("%-8s %-12d %-10.2f %-14.2f %-20d\n", 
                   carta->codigo, carta->populacao, carta->area, carta->pib, carta->pontos_turisticos);
        }
    }
}

int main() {
    // Ponto de entrada do programa.
    // O fluxo principal do programa segue os seguintes passos:
    // 1. Declaração da matriz de cartas que armazenará os dados de todas as cidades.
    // 2. Solicitação ao usuário para cadastrar os dados das cidades via terminal.
    // 3. Exibição das cartas cadastradas de forma organizada e formatada.

    Carta cartas[NUM_ESTADOS][CIDADES_POR_ESTADO];

    printf("--- Cadastro de Cartas: Super Trunfo - Paises ---\n");

    // Chamada da função para realizar o cadastro das cartas.
    cadastrarCartas(cartas);

    // Chamada da função para exibir as cartas cadastradas.
    exibirCartas(cartas);

    return 0; // Indica que o programa foi executado com sucesso.
}
