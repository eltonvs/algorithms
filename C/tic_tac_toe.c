#include <stdio.h>

int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

void show_board() {
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            printf("%i%c", board[i][j], j == 2 ? '\n' : ' ');
}

int check_winner(int player) {
    int magic_sum = (player == 1) ? 3 : -3;
    int i, j, sum;

    //Soma das linhas
    for (i = 0, sum = 0; i < 3; i++, sum = 0) {
        for (j = 0; j < 3; j++)
            sum += board[i][j];
        if (sum == magic_sum) return 1;
    }

    //Soma das colunas
    for (j = 0, sum = 0; j < 3; j++, sum = 0) {
        for (i = 0; i < 3; i++)
            sum += board[i][j];
        if (sum == magic_sum) return 1;
    }

    //Soma da diagonal principal
    for (i = 0, sum = 0; i < 3; i++)
        sum += board[i][i];
    if (sum == magic_sum) return 1;

    //Soma da diagonal secundária
    for (i = 0, sum = 0; i < 3; i++)
        sum += board[i][2-i];
    if (sum == magic_sum) return 1;

    return 0;
}

int check_coord(int x, int y) {
    if (x > 2 || x < 0 || y > 2 || x < 0)
        return 1;
    else if (board[x][y] != 0)
        return 1;
    else
        return 0;
}

void set_value(int player, int x, int y){
    board[x][y] = (player == 1) ? 1 : -1;
}

int main() {
    int count = 1, alive = 1, player = 1, c_x, c_y;

    printf("Jogo da Velha 2000\n");

    do {
        printf("Jogador %i, escolha onde quer jogar\n", player);
        do {
            printf("Coordenada X [1 -> 3]: ");
            scanf("%i", &c_x);
            c_x--;
            printf("Coordenada Y [1 -> 3]: ");
            scanf("%i", &c_y);
            c_y--;
            if (check_coord(c_x, c_y))
                printf("A posicao escolhida e invalida. Tente novamente:\n");
        } while(check_coord(c_x, c_y));

        set_value(player, c_x, c_y);

        show_board();

        if (check_winner(player)) {
            printf("O jogador %i ganhou!\n", player);
            alive = 0;
        }else if (count == 9) {
            printf("O jogo acabou! Não há mais movimentos possíveis\n");
            alive = 0;
        }

        player = (player == 1) ? 2 : 1, count++;
    }while (alive);

    printf("Fim do jogo.\n");

    return 0;
}
