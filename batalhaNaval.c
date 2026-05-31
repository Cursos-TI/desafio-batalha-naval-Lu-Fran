    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void aplicarHabilidade(
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
    int origemLinha,
    int origemColuna)
{
    int i, j;

    int centro = TAM_HABILIDADE / 2;

    for(i = 0; i < TAM_HABILIDADE; i++) {
        for(j = 0; j < TAM_HABILIDADE; j++) {

            if(habilidade[i][j] == 1) {

                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                if(linhaTab >= 0 &&
                   linhaTab < TAM_TABULEIRO &&
                   colunaTab >= 0 &&
                   colunaTab < TAM_TABULEIRO)
                {
                    if(tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

//Saída visual amigável
//~ → Água
//N → Navio
//* → Área da habilidade
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    int i, j;

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for(i = 0; i < TAM_TABULEIRO; i++) {

        for(j = 0; j < TAM_TABULEIRO; j++) {

            switch(tabuleiro[i][j]) {

                case AGUA:
                    printf("~ ");
                    break;

                case NAVIO:
                    printf("N ");
                    break;

                case HABILIDADE:
                    printf("* ");
                    break;
            }
        }

        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    int i, j;

    /* =====================================================
       POSICIONAMENTO DOS 4 NAVIOS
    ====================================================== */

    /* Horizontal */
    for(i=0;i<TAM_NAVIO;i++)
        tabuleiro[1][1+i] = NAVIO;

    /* Vertical */
    for(i=0;i<TAM_NAVIO;i++)
        tabuleiro[5+i][8] = NAVIO;

    /* Diagonal principal (\) */
    for(i=0;i<TAM_NAVIO;i++)
        tabuleiro[0+i][5+i] = NAVIO;

    /* Diagonal secundária (/) */
    for(i=0;i<TAM_NAVIO;i++)
        tabuleiro[4+i][2-i] = NAVIO;


    /* =====================================================
       MATRIZ HABILIDADE — CONE
    ====================================================== */

    for(i=0;i<TAM_HABILIDADE;i++) {

        int inicio = TAM_HABILIDADE/2 - i;
        int fim = TAM_HABILIDADE/2 + i;

        for(j=0;j<TAM_HABILIDADE;j++) {

            if(j >= inicio && j <= fim) {
                cone[i][j] = 1;
            }
        }
    }


    /* =====================================================
       MATRIZ HABILIDADE — CRUZ
    ====================================================== */

    for(i=0;i<TAM_HABILIDADE;i++) {
        for(j=0;j<TAM_HABILIDADE;j++) {

            if(i == TAM_HABILIDADE/2 ||
               j == TAM_HABILIDADE/2)
            {
                cruz[i][j] = 1;
            }
        }
    }


    /* =====================================================
       MATRIZ HABILIDADE — OCTAEDRO (LOSANGO)
    ====================================================== */

    int centro = TAM_HABILIDADE/2;

    for(i=0;i<TAM_HABILIDADE;i++) {
        for(j=0;j<TAM_HABILIDADE;j++) {

            int distancia =
                (i > centro ? i-centro : centro-i) +
                (j > centro ? j-centro : centro-j);

            if(distancia <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }


    /* =====================================================
       SOBREPOSIÇÃO DAS HABILIDADES
    ====================================================== */

    aplicarHabilidade(tabuleiro, cone, 2, 7);

    aplicarHabilidade(tabuleiro, cruz, 7, 3);

    aplicarHabilidade(tabuleiro, octaedro, 5, 5);


    /* =====================================================
       EXIBIÇÃO FINAL
    ====================================================== */

    imprimirTabuleiro(tabuleiro);

    return 0;
}
