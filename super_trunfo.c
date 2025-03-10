#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PAISES 8
#define NUM_ATRIBUTOS 4

// Estrutura para representar um país
typedef struct {
    char nome[50];
    float populacao;    // em milhões
    float pib;          // em bilhões de dólares
    float area;         // em km²
    float populacao;
    float pib;
    float area;
    float idh;
} Pais;

// Estrutura para representar um jogador
typedef struct {
    Pais *cartas;
    int num_cartas;
    int pontos;
} Jogador;

// Função para inicializar o baralho de países
void inicializar_paises(Pais paises[]) {
    // Brasil
    strcpy(paises[0].nome, "Brasil");
    paises[0].populacao = 214.3;
    paises[0].pib = 1608.1;
    paises[0].area = 8515770;
    paises[0].idh = 0.754;

    // EUA
    strcpy(paises[1].nome, "Estados Unidos");
    paises[1].populacao = 331.9;
    paises[1].pib = 20940.0;
    paises[1].area = 9833517;
    paises[1].idh = 0.921;

    // China
    strcpy(paises[2].nome, "China");
    paises[2].populacao = 1402.1;
    paises[2].pib = 14722.8;
    paises[2].area = 9596961;
    paises[2].idh = 0.768;

    // Alemanha
    strcpy(paises[3].nome, "Alemanha");
    paises[3].populacao = 83.2;
    paises[3].pib = 4223.1;
    paises[3].area = 357022;
    paises[3].idh = 0.942;

    // Japão
    strcpy(paises[4].nome, "Japao");
    paises[4].populacao = 125.7;
    paises[4].pib = 5058.2;
    paises[4].area = 377975;
    paises[4].idh = 0.919;

    // Índia
    strcpy(paises[5].nome, "India");
    paises[5].populacao = 1380.0;
    paises[5].pib = 2875.1;
    paises[5].area = 3287263;
    paises[5].idh = 0.645;

    // Rússia
    strcpy(paises[6].nome, "Russia");
    paises[6].populacao = 144.1;
    paises[6].pib = 1483.5;
    paises[6].area = 17098246;
    paises[6].idh = 0.824;

    // Canadá
    strcpy(paises[7].nome, "Canada");
    paises[7].populacao = 38.0;
    paises[7].pib = 1643.1;
    paises[7].area = 9984670;
    paises[7].idh = 0.929;
}

// Função para embaralhar o baralho
void embaralhar(Pais paises[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Pais temp = paises[i];
        paises[i] = paises[j];
        paises[j] = temp;
    }
}

// Função para distribuir as cartas
void distribuir_cartas(Pais paises[], Jogador *jogador, Jogador *computador) {
    jogador->cartas = (Pais*)malloc((NUM_PAISES/2) * sizeof(Pais));
    computador->cartas = (Pais*)malloc((NUM_PAISES/2) * sizeof(Pais));

    jogador->num_cartas = NUM_PAISES/2;
    computador->num_cartas = NUM_PAISES/2;

    for (int i = 0; i < NUM_PAISES/2; i++) {
        jogador->cartas[i] = paises[i];
        computador->cartas[i] = paises[i + NUM_PAISES/2];
    }
}

// Função para mostrar a carta do jogador
void mostrar_carta(Pais carta) {
    printf("\n=================================\n");
    printf("País: %s\n", carta.nome);
    printf("1. População: %.1f milhões\n", carta.populacao);
    printf("2. PIB: %.1f bilhões USD\n", carta.pib);
    printf("3. Área: %.0f km²\n", carta.area);
    printf("4. IDH: %.3f\n", carta.idh);
    printf("=================================\n");
}

// Função para comparar atributos
int comparar_atributo(Pais carta1, Pais carta2, int atributo) {
    float valor1, valor2;

    switch(atributo) {
        case 1: // População
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2: // PIB
        case 2:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 3: // Área
        case 3:
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 4: // IDH
        case 4:
            valor1 = carta1.idh;
            valor2 = carta2.idh;
            break;
        default:
            return 0;
    }

    if (valor1 > valor2) return 1;
    if (valor1 < valor2) return -1;
    return 0;
}

int main() {
    srand(time(NULL));

    Pais paises[NUM_PAISES];
    Jogador jogador = {NULL, 0, 0};
    Jogador computador = {NULL, 0, 0};

    inicializar_paises(paises);
    embaralhar(paises, NUM_PAISES);
    distribuir_cartas(paises, &jogador, &computador);

    printf("
   _     _+     _     _   
  (c).-.(c)    (c).-.(c)  
   / ._. \      / ._. \   
 __\( Y )/__  __\( Y )/__ 
(_.-/'-'\-._)(_.-/'-'\-._)
   || L ||      || M ||   
 _.' `-' '._  _.' `-' '._ 
(.-./`-'\.-.)(.-./`-'\.-.)
 `-'     `-'  `-'     `-' 
\n");

    while (jogador.num_cartas > 0 && computador.num_cartas > 0) {
        printf("\nSua carta atual:");
        mostrar_carta(jogador.cartas[0]);

        int escolha;
        do {
            printf("\nEscolha um atributo (1-4): ");
            scanf("%d", &escolha);
        } while (escolha < 1 || escolha > 4);

        printf("\nCarta do computador:");
        mostrar_carta(computador.cartas[0]);

        int resultado = comparar_atributo(jogador.cartas[0], computador.cartas[0], escolha);

        if (resultado > 0) {
            printf("\nVocê venceu esta rodada!\n");
            jogador.pontos++;
        } else if (resultado < 0) {
            printf("\nComputador venceu esta rodada!\n");
            computador.pontos++;
        } else {
            printf("\nEmpate!\n");
        }

        printf("\nPlacar: Você %d x %d Computador\n", jogador.pontos, computador.pontos);

        // Remove as cartas usadas
        for (int i = 0; i < jogador.num_cartas - 1; i++) {
            jogador.cartas[i] = jogador.cartas[i + 1];
        }
        for (int i = 0; i < computador.num_cartas - 1; i++) {
            computador.cartas[i] = computador.cartas[i + 1];
        }

        jogador.num_cartas--;
        computador.num_cartas--;
    }

    printf("\n=== FIM DE JOGO ===\n");
    if (jogador.pontos > computador.pontos)
        printf("Parabéns! Você venceu o jogo!\n");
    else if (jogador.pontos < computador.pontos)
        printf("O computador venceu o jogo!\n");
    else
        printf("O jogo terminou empatado!\n");

    printf("Placar final: Você %d x %d Computador\n", jogador.pontos, computador.pontos);

    // Libera a memória alocada
    free(jogador.cartas);
    free(computador.cartas);

    return 0;
}
