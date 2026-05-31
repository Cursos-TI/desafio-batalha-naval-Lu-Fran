// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int i, j, sobreposicao;

    // =====================================
    // COORDENADAS DOS 4 NAVIOS
    // =====================================

    // Horizontal
    int linhaH = 1;
    int colunaH = 1;

    // Vertical
    int linhaV = 5;
    int colunaV = 8;

    // Diagonal principal (\)
    int linhaDP = 0;
    int colunaDP = 5;

    // Diagonal secundária (/)
    int linhaDS = 4;
    int colunaDS = 2;

    // =====================================
    // NAVIO HORIZONTAL
    // =====================================

    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {

        sobreposicao = 0;

        for(i = 0; i < TAM_NAVIO; i++) {
            if(tabuleiro[linhaH][colunaH + i] != AGUA) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // =====================================
    // NAVIO VERTICAL
    // =====================================

    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {

        sobreposicao = 0;

        for(i = 0; i < TAM_NAVIO; i++) {
            if(tabuleiro[linhaV + i][colunaV] != AGUA) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // =====================================
    // NAVIO DIAGONAL PRINCIPAL (\)
    // =====================================

    if ((linhaDP + TAM_NAVIO <= TAM_TABULEIRO) &&
        (colunaDP + TAM_NAVIO <= TAM_TABULEIRO)) {

        sobreposicao = 0;

        for(i = 0; i < TAM_NAVIO; i++) {
            if(tabuleiro[linhaDP+i][colunaDP+i] != AGUA) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaDP+i][colunaDP+i] = NAVIO;
            }
        }
    }

    // =====================================
    // NAVIO DIAGONAL SECUNDÁRIA (/)
    // =====================================

    if ((linhaDS + TAM_NAVIO <= TAM_TABULEIRO) &&
        (colunaDS - (TAM_NAVIO-1) >= 0)) {

        sobreposicao = 0;

        for(i = 0; i < TAM_NAVIO; i++) {
            if(tabuleiro[linhaDS+i][colunaDS-i] != AGUA) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaDS+i][colunaDS-i] = NAVIO;
            }
        }
    }

    // =====================================
    // EXIBIÇÃO TABULEIRO
    // =====================================

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for(i = 0; i < TAM_TABULEIRO; i++) {

        for(j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
