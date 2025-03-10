#include <stdio.h>
#include <string.h>

// Estrutura para representar um país
typedef struct {
    char nome[50];
    float territorio;
    float populacao;
    float pib;
    float densidade;
} Pais;

// Função para exibir menu de atributos
int exibirMenu(int atributoExcluido) {
    printf("\nEscolha o atributo para comparação:\n");
    if (atributoExcluido != 1) printf("1 - Território\n");
    if (atributoExcluido != 2) printf("2 - População\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Densidade Demográfica\n");
    
    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

// Função para obter valor do atributo baseado na escolha
float obterValorAtributo(Pais pais, int escolha) {
    switch(escolha) {
        case 1: return pais.territorio;
        case 2: return pais.populacao;
        case 3: return pais.pib;
        case 4: return pais.densidade;
        default: return 0;
    }
}

// Função para obter nome do atributo
const char* obterNomeAtributo(int escolha) {
    switch(escolha) {
        case 1: return "Território";
        case 2: return "População";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

// Função para comparar atributos
int compararAtributo(float valor1, float valor2, int atributo) {
    // Para densidade, menor valor ganha
    if (atributo == 4) {
        return valor1 < valor2 ? 1 : (valor1 > valor2 ? -1 : 0);
    }
    // Para outros atributos, maior valor ganha
    return valor1 > valor2 ? 1 : (valor1 < valor2 ? -1 : 0);
}

int main() {
    // Pré-cadastro de países
    Pais pais1 = {"Brasil", 8516000, 214300000, 1608000, 25.16};
    Pais pais2 = {"Canadá", 9985000, 38250000, 1643000, 3.83};

    printf("=== Super Trunfo dos Países ===\n");
    
    // Escolha dos atributos
    int escolha1 = exibirMenu(0);
    int escolha2 = exibirMenu(escolha1);

    // Obter valores dos atributos
    float valor1_atr1 = obterValorAtributo(pais1, escolha1);
    float valor1_atr2 = obterValorAtributo(pais1, escolha2);
    float valor2_atr1 = obterValorAtributo(pais2, escolha1);
    float valor2_atr2 = obterValorAtributo(pais2, escolha2);

    // Calcular somas
    float soma1 = valor1_atr1 + valor1_atr2;
    float soma2 = valor2_atr1 + valor2_atr2;

    // Exibir resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("\n%s vs %s\n", pais1.nome, pais2.nome);
    printf("\nAtributo 1 - %s:\n", obterNomeAtributo(escolha1));
    printf("%s: %.2f\n", pais1.nome, valor1_atr1);
    printf("%s: %.2f\n", pais2.nome, valor2_atr1);
    
    printf("\nAtributo 2 - %s:\n", obterNomeAtributo(escolha2));
    printf("%s: %.2f\n", pais1.nome, valor1_atr2);
    printf("%s: %.2f\n", pais2.nome, valor2_atr2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", pais1.nome, soma1);
    printf("%s: %.2f\n", pais2.nome, soma2);

    // Determinar vencedor
    if (soma1 > soma2) {
        printf("\nVencedor: %s!\n", pais1.nome);
    } else if (soma2 > soma1) {
        printf("\nVencedor: %s!\n", pais2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
