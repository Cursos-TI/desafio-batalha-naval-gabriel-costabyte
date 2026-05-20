#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int Tabuleiro[10][10] = {0};
    int cruz[5][5] = {0};
    int cone[5][5] = {0};
    int octaedro[5][5] = {0};

    // Navio horizontal
    for (int coluna = 3; coluna <= 5; coluna++) {
        Tabuleiro[3][coluna] = 3;
    }

    // Navio vertical
    for (int linha = 5; linha <= 7; linha++) {
        Tabuleiro[linha][8] = 3;
    }
     // Navio Diagonal1
    for (int coluna = 0; coluna < 3; coluna++) {
        Tabuleiro[3 + coluna][1 + coluna] = 3;
    }

     // Navio Diagonal2
    for (int coluna = 0; coluna < 3; coluna++) {
        Tabuleiro[7 + coluna][5 - coluna] = 3;
    }



    // Letras do topo
    printf("   ");
    for (char i = 'A'; i <= 'J'; i++) {
        printf(" %c ", i);
    }

    printf("\n");


    // Habilidades

    // Cone

    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {

            if (c >= 2 - l && c <= 2 + l && l <= 2) {
                cone[l][c] = 1;
            }
        }
    }

    // Cruz

     for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {

            if (l == 2 || c == 2) {
                cruz[l][c] = 1;
            }
        }
    }

    // Octaedro

     for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {

            int dl = l - 2;
            int dc = c - 2;

            if (dl < 0) dl = -dl;
            if (dc < 0) dc = -dc;

            if (dl + dc <= 2) {
                octaedro[l][c] = 1;
            }
        }
    }

    // Pontos de origem

    int origemConeL = 0, origemConeC = 0;
    int origemCruzL = 2, origemCruzC = 5;
    int origemOctL = 5, origemOctC = 0;

    // Sobreposição

     // Cone
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {

            int tl = origemConeL + l;
            int tc = origemConeC + c;

            if (tl < 10 && tc < 10 &&
                cone[l][c] == 1 &&
                Tabuleiro[tl][tc] == 0) {

                Tabuleiro[tl][tc] = 1;
            }
        }
    }

    // Cruz
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {

            int tl = origemCruzL + l;
            int tc = origemCruzC + c;

            if (tl < 10 && tc < 10 &&
                cruz[l][c] == 1 &&
                Tabuleiro[tl][tc] == 0) {

                Tabuleiro[tl][tc] = 1;
            }
        }
    }

    // Octaedro
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {

            int tl = origemOctL + l;
            int tc = origemOctC + c;

            if (tl < 10 && tc < 10 &&
                octaedro[l][c] == 1 &&
                Tabuleiro[tl][tc] == 0) {

                Tabuleiro[tl][tc] = 1;
            }
        }
    }

    // Exibição do tabuleiro
    for (int linha = 0; linha < 10; linha++) {

        printf("%2d ", linha);

        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d ", Tabuleiro[linha][coluna]);
        }

        printf("\n");
    }



    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
