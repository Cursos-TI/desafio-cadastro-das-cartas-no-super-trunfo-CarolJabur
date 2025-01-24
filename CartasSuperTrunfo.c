#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional e PIB per capita
void calcularPropriedades(Carta *carta) {
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }
    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado (letra): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    calcularPropriedades(carta);

    printf("\nCarta cadastrada com sucesso!\n");
}

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("\n--- Carta: %s ---\n", carta.codigo);
    printf("Estado: %c\n", carta.estado);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
}

int main() {
    Carta cartas[32]; // Total de 8 estados x 4 cidades = 32 cartas
    int quantidade = 0;
    char opcao;

    printf("Bem-vindo ao sistema de cadastro do Super Trunfo!\n");

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar uma carta\n");
        printf("2. Exibir cartas cadastradas\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                if (quantidade < 32) {
                    cadastrarCarta(&cartas[quantidade]);
                    quantidade++;
                } else {
                    printf("Limite de cartas atingido!\n");
                }
                break;
            case '2':
                for (int i = 0; i < quantidade; i++) {
                    exibirCarta(cartas[i]);
                }
                break;
            case '3':
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != '3');

    return 0;
}
