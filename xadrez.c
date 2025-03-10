/**
 * Programa de Movimentação de Peças de Xadrez
 * 
 * Este programa demonstra o movimento das peças de xadrez (Torre, Bispo, Rainha e Cavalo)
 * utilizando técnicas de recursividade e loops complexos.
 * - Torre, Bispo e Rainha: movimentos implementados usando recursividade
 * - Cavalo: movimento em L (duas casas para cima e uma para a direita) implementado com loops complexos
 * - Bispo: implementado com recursividade e também com loops aninhados
 */

#include <stdio.h>

// Constantes para definir o número de casas a mover
#define NUM_CASAS_TORRE 4    // Número de casas que a Torre se move
#define NUM_CASAS_BISPO 4    // Número de casas que o Bispo se move
#define NUM_CASAS_RAINHA 4   // Número de casas que a Rainha se move
#define NUM_CASAS_CAVALO 3   // Número de movimentos que o Cavalo faz

/**
 * Função recursiva para mover a Torre nas quatro direções
 * 
 * @param direcao: A direção do movimento (0: cima, 1: baixo, 2: esquerda, 3: direita)
 * @param casas_restantes: Número de casas restantes para mover nessa direção
 */
void moverTorreRecursivo(int direcao, int casas_restantes) {
    // Caso base: não há mais casas para mover
    if (casas_restantes <= 0) {
        return;
    }
    
    // Move a Torre na direção especificada
    switch (direcao) {
        case 0:
            printf("Cima\n");
            break;
        case 1:
            printf("Baixo\n");
            break;
        case 2:
            printf("Esquerda\n");
            break;
        case 3:
            printf("Direita\n");
            break;
    }
    
    // Chamada recursiva para continuar o movimento
    moverTorreRecursivo(direcao, casas_restantes - 1);
}

/**
 * Função para demonstrar os movimentos da Torre em todas as direções
 */
void moverTorre() {
    printf("Movimento da Torre:\n");
    printf("====================\n");
    
    // Move a Torre para cima
    printf("Movimento para cima:\n");
    moverTorreRecursivo(0, NUM_CASAS_TORRE);
    printf("\n");
    
    // Move a Torre para baixo
    printf("Movimento para baixo:\n");
    moverTorreRecursivo(1, NUM_CASAS_TORRE);
    printf("\n");
    
    // Move a Torre para a esquerda
    printf("Movimento para a esquerda:\n");
    moverTorreRecursivo(2, NUM_CASAS_TORRE);
    printf("\n");
    
    // Move a Torre para a direita
    printf("Movimento para a direita:\n");
    moverTorreRecursivo(3, NUM_CASAS_TORRE);
    printf("\n");
}

/**
 * Função recursiva para mover o Bispo nas diagonais
 * 
 * @param direcao: A direção do movimento (0: cima-direita, 1: cima-esquerda, 
 *                                         2: baixo-direita, 3: baixo-esquerda)
 * @param casas_restantes: Número de casas restantes para mover nessa direção
 */
void moverBispoRecursivo(int direcao, int casas_restantes) {
    // Caso base: não há mais casas para mover
    if (casas_restantes <= 0) {
        return;
    }
    
    // Move o Bispo na direção especificada
    switch (direcao) {
        case 0:
            printf("Cima-Direita\n");
            break;
        case 1:
            printf("Cima-Esquerda\n");
            break;
        case 2:
            printf("Baixo-Direita\n");
            break;
        case 3:
            printf("Baixo-Esquerda\n");
            break;
    }
    
    // Chamada recursiva para continuar o movimento
    moverBispoRecursivo(direcao, casas_restantes - 1);
}

/**
 * Função para demonstrar os movimentos do Bispo com loops aninhados
 * O loop mais externo controla o movimento vertical e o loop mais interno o movimento horizontal
 * Esta implementação atende ao requisito de ter o loop mais externo para movimento vertical
 * e o mais interno para horizontal.
 */
void moverBispoComLoops() {
    printf("Movimento do Bispo com Loops Aninhados:\n");
    printf("=======================================\n");
    
    // Movimento diagonal cima-direita
    printf("Movimento diagonal cima-direita:\n");
    // O loop externo controla o movimento vertical (para cima)
    for (int vertical = 1; vertical <= NUM_CASAS_BISPO; vertical++) {
        // O loop interno controla o movimento horizontal (para a direita)
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Cima-Direita\n");
        }
    }
    printf("\n");
    
    // Movimento diagonal cima-esquerda
    printf("Movimento diagonal cima-esquerda:\n");
    // O loop externo controla o movimento vertical (para cima)
    for (int vertical = 1; vertical <= NUM_CASAS_BISPO; vertical++) {
        // O loop interno controla o movimento horizontal (para a esquerda)
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Cima-Esquerda\n");
        }
    }
    printf("\n");
    
    // Movimento diagonal baixo-direita
    printf("Movimento diagonal baixo-direita:\n");
    // O loop externo controla o movimento vertical (para baixo)
    for (int vertical = 1; vertical <= NUM_CASAS_BISPO; vertical++) {
        // O loop interno controla o movimento horizontal (para a direita)
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Baixo-Direita\n");
        }
    }
    printf("\n");
    
    // Movimento diagonal baixo-esquerda
    printf("Movimento diagonal baixo-esquerda:\n");
    // O loop externo controla o movimento vertical (para baixo)
    for (int vertical = 1; vertical <= NUM_CASAS_BISPO; vertical++) {
        // O loop interno controla o movimento horizontal (para a esquerda)
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Baixo-Esquerda\n");
        }
    }
    printf("\n");
}

/**
 * Função para demonstrar os movimentos do Bispo em todas as direções diagonais
 */
void moverBispo() {
    printf("Movimento do Bispo com Recursividade:\n");
    printf("=====================================\n");
    
    // Move o Bispo na diagonal cima-direita
    printf("Movimento na diagonal cima-direita:\n");
    moverBispoRecursivo(0, NUM_CASAS_BISPO);
    printf("\n");
    
    // Move o Bispo na diagonal cima-esquerda
    printf("Movimento na diagonal cima-esquerda:\n");
    moverBispoRecursivo(1, NUM_CASAS_BISPO);
    printf("\n");
    
    // Move o Bispo na diagonal baixo-direita
    printf("Movimento na diagonal baixo-direita:\n");
    moverBispoRecursivo(2, NUM_CASAS_BISPO);
    printf("\n");
    
    // Move o Bispo na diagonal baixo-esquerda
    printf("Movimento na diagonal baixo-esquerda:\n");
    moverBispoRecursivo(3, NUM_CASAS_BISPO);
    printf("\n");
    
    // Demonstra o movimento do Bispo com loops aninhados
    moverBispoComLoops();
}

/**
 * Função recursiva para mover a Rainha em todas as direções (combinando movimentos da Torre e do Bispo)
 * 
 * @param direcao: A direção do movimento (0: cima, 1: baixo, 2: esquerda, 3: direita,
 *                                        4: cima-direita, 5: cima-esquerda, 6: baixo-direita, 7: baixo-esquerda)
 * @param casas_restantes: Número de casas restantes para mover nessa direção
 */
void moverRainhaRecursivo(int direcao, int casas_restantes) {
    // Caso base: não há mais casas para mover
    if (casas_restantes <= 0) {
        return;
    }
    
    // Move a Rainha na direção especificada
    switch (direcao) {
        case 0:
            printf("Cima\n");
            break;
        case 1:
            printf("Baixo\n");
            break;
        case 2:
            printf("Esquerda\n");
            break;
        case 3:
            printf("Direita\n");
            break;
        case 4:
            printf("Cima-Direita\n");
            break;
        case 5:
            printf("Cima-Esquerda\n");
            break;
        case 6:
            printf("Baixo-Direita\n");
            break;
        case 7:
            printf("Baixo-Esquerda\n");
            break;
    }
    
    // Chamada recursiva para continuar o movimento
    moverRainhaRecursivo(direcao, casas_restantes - 1);
}

/**
 * Função para demonstrar os movimentos da Rainha em todas as direções
 */
void moverRainha() {
    printf("Movimento da Rainha:\n");
    printf("====================\n");
    
    // Move a Rainha para cima
    printf("Movimento para cima:\n");
    moverRainhaRecursivo(0, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha para baixo
    printf("Movimento para baixo:\n");
    moverRainhaRecursivo(1, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha para a esquerda
    printf("Movimento para a esquerda:\n");
    moverRainhaRecursivo(2, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha para a direita
    printf("Movimento para a direita:\n");
    moverRainhaRecursivo(3, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha na diagonal cima-direita
    printf("Movimento na diagonal cima-direita:\n");
    moverRainhaRecursivo(4, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha na diagonal cima-esquerda
    printf("Movimento na diagonal cima-esquerda:\n");
    moverRainhaRecursivo(5, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha na diagonal baixo-direita
    printf("Movimento na diagonal baixo-direita:\n");
    moverRainhaRecursivo(6, NUM_CASAS_RAINHA);
    printf("\n");
    
    // Move a Rainha na diagonal baixo-esquerda
    printf("Movimento na diagonal baixo-esquerda:\n");
    moverRainhaRecursivo(7, NUM_CASAS_RAINHA);
    printf("\n");
}

/**
 * Função para demonstrar o movimento do Cavalo (em L, duas casas para cima e uma para a direita)
 * usando loops aninhados complexos com múltiplas variáveis e condições
 * Implementação aprimorada com break e continue para controle de fluxo mais preciso
 */
void moverCavalo() {
    printf("Movimento do Cavalo:\n");
    printf("====================\n");
    
    // Contador para acompanhar o número total de movimentos feitos
    int movimentos_realizados = 0;
    int vertical = 0;
    int horizontal = 0;
    
    // Loop externo para controlar a sequência de movimentos
    for (int sequencia = 0; sequencia < NUM_CASAS_CAVALO; sequencia++) {
        // Variáveis de controle para o loop aninhado
        int cima_completo = 0;
        int direita_completo = 0;
        
        // Loop aninhado com múltiplas variáveis e condições
        for (int passo = 0; passo < 3; passo++) {
            // Verifica se precisa pular esta iteração
            if (movimentos_realizados >= NUM_CASAS_CAVALO * 3) {
                continue; // Demonstração do uso do continue
            }
            
            // Verifica se já completou o movimento para cima (2 casas)
            if (passo < 2 && !cima_completo) {
                vertical++;
                printf("Cima\n");
                
                // Marca como completo se já moveu 2 casas para cima
                if (passo == 1) {
                    cima_completo = 1;
                }
            } 
            // Verifica se já completou o movimento para a direita (1 casa)
            else if (passo == 2 && !direita_completo) {
                horizontal++;
                printf("Direita\n");
                direita_completo = 1;
            }
            
            movimentos_realizados++;
            
            // Se já realizamos todos os movimentos previstos, saímos do loop
            if (movimentos_realizados >= NUM_CASAS_CAVALO * 3) {
                break; // Demonstração do uso do break
            }
        }
        
        // Inserimos uma pausa entre os movimentos em "L" completos
        if (sequencia < NUM_CASAS_CAVALO - 1 && movimentos_realizados < NUM_CASAS_CAVALO * 3) {
            printf("---\n");
        }
    }
    printf("\n");
    
    // Demonstração do movimento do Cavalo com uso avançado de break e continue
    printf("Movimento do Cavalo com break/continue avançado:\n");
    printf("================================================\n");
    
    int movimento = 0;
    int pos_x = 0, pos_y = 0; // Posição atual do cavalo
    
    // Loop com múltiplas variáveis e condições
    for (int i = 0; i < NUM_CASAS_CAVALO * 2; i++) {
        // Pula algumas iterações para demonstrar o uso do continue
        if (i % 2 == 0 && i > 0) {
            continue; // Pula iterações pares exceto a primeira
        }
        
        // Loop aninhado para o movimento em "L"
        for (int j = 0; j < 3; j++) {
            // Verifica se já completou todos os movimentos necessários
            if (movimento >= NUM_CASAS_CAVALO * 3) {
                break; // Sai do loop se já realizou todos os movimentos
            }
            
            movimento++;
            
            // Loop interno para demonstrar aninhamento mais complexo
            for (int k = 0; k < 1; k++) { // Executa apenas uma vez, demonstrando loop aninhado
                // Os dois primeiros passos são para cima
                if (j < 2) {
                    pos_y++; // Incrementa a posição vertical
                    printf("Cima\n");
                } 
                // O terceiro passo é para a direita
                else {
                    pos_x++; // Incrementa a posição horizontal
                    printf("Direita\n");
                }
            }
        }
        
        // Verifica se já completou todos os movimentos
        if (movimento >= NUM_CASAS_CAVALO * 3) {
            break; // Sai do loop externo
        }
        
        printf("---\n");
    }
    printf("\n");
}

/**
 * Função principal que demonstra o movimento de todas as peças
 */
int main() {
    // Movimenta a Torre (usando recursividade)
    moverTorre();
    printf("\n\n");
    
    // Movimenta o Bispo (usando recursividade e loops aninhados)
    moverBispo();
    printf("\n\n");
    
    // Movimenta a Rainha (usando recursividade)
    moverRainha();
    printf("\n\n");
    
    // Movimenta o Cavalo (usando loops complexos)
    moverCavalo();
    
    return 0;
}
