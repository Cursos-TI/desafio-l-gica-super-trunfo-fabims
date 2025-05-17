#include <stdio.h>
#include <string.h>
#include <stdlib.h> // para usar malloc

// Definição da estrutura para representar uma carta
typedef struct {
    char estado[2]; // Estado (por exemplo, "SP")
    char codigo[5]; // Código da carta (por exemplo, "1234")
    char cidade[50]; // Nome da cidade
    int populacao;   // População da cidade
    double pib;      // PIB da cidade
    double area;     // Área da cidade em km²
    int pontosTuristicos; // Número de pontos turísticos
    double densidadePopulacional; // Densidade populacional (população/área)
    double pibPerCapita;  // PIB per capita (PIB/população)
} CartaCidade;

// Função para ler os dados de uma carta
void lerDadosCarta(CartaCidade *carta) {
    printf("\nDigite o estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf("%s", carta->cidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite o PIB da cidade: ");
    scanf("%lf", &carta->pib);

    printf("Digite a área da cidade (km²): ");
    scanf("%lf", &carta->area);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo das propriedades derivadas
    if (carta->area > 0) {
        carta->densidadePopulacional = (double)carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0.0; // ou outro valor apropriado
    }
    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0.0; // ou outro valor apropriado
    }
}

// Função para imprimir os dados de uma carta
void imprimirDadosCarta(const CartaCidade *carta) {
    printf("\nEstado: %s\n", carta->estado);
    printf("Código da carta: %s\n", carta->codigo);
    printf("Cidade: %s\n", carta->cidade);
    printf("População: %d\n", carta->populacao);
    printf("PIB: %.2lf\n", carta->pib);
    printf("Área (km²): %.2lf\n", carta->area);
    printf("Número de pontos turísticos: %d\n", carta->pontosTuristicos);
    printf("Densidade populacional: %.2lf hab/km²\n", carta->densidadePopulacional);
    printf("PIB per capita: %.2lf\n", carta->pibPerCapita);
}

int main() {
    int numCartas;

    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &numCartas);

    // Alocando memória dinâmica para as cartas
    CartaCidade *cartas = (CartaCidade *)malloc(numCartas * sizeof(CartaCidade));

    if (cartas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Lendo os dados de cada carta
    for (int i = 0; i < numCartas; i++) {
        printf("\nDigite os dados da carta %d:\n", i + 1);
        lerDadosCarta(&cartas[i]);
    }

    // Imprimindo os dados de cada carta
    printf("\nDados das cartas:\n");
    for (int i = 0; i < numCartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        imprimirDadosCarta(&cartas[i]);
    }

    // Liberando a memória alocada
    free(cartas);

    return 0;
}
