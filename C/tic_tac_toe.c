#include <stdio.h>

unsigned int n;

void clr_screen() {
    #if defined WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void deflate_board(char board[n][n]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = ' ';
}

void show_board(char board[n][n]) {
    clr_screen();
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            printf("|  %c %s", board[i][j], (j == n-1) ? " |\n" : " ");
}

int check_winner(int player, char board[n][n]) {
    int magic_sum = (player == 1) ? 'X'*n : 'O'*n;
    int i, j, sum;

    //Soma das linhas
    for (i = 0, sum = 0; i < n; i++, sum = 0) {
        for (j = 0; j < n; j++)
            sum += board[i][j];
        if (sum == magic_sum) return 1;
    }

    //Soma das colunas
    for (j = 0, sum = 0; j < n; j++, sum = 0) {
        for (i = 0; i < n; i++)
            sum += board[i][j];
        if (sum == magic_sum) return 1;
    }

    //Soma da diagonal principal
    for (i = 0, sum = 0; i < n; i++)
        sum += board[i][i];
    if (sum == magic_sum) return 1;

    //Soma da diagonal secundária
    for (i = 0, sum = 0; i < n; i++)
        sum += board[i][n-i-1];
    if (sum == magic_sum) return 1;

    return 0;
}

int check_coord(int x, int y, char board[n][n]) {
    if (x >= n || x < 0 || y >= n || x < 0)
        return 1;
    else if (board[x][y] != ' ')
        return 1;
    else
        return 0;
}

void make_move(int player, int x, int y, char board[n][n]){
    board[x][y] = (player == 1) ? 'X' : 'O';
}

int main() {
    int count = 1, alive = 1, player = 1, x, y;

    printf("Informe o tamanho do tabuleiro: ");
    scanf("%i", &n);

    char board[n][n];

    deflate_board(board);

    do {
        show_board(board);
        printf("\nJogador %i (%c), escolha onde quer jogar\n", player, (player == 1) ? 'X' : 'O');
        do {
            printf("Coordenada X [1 -> %i]: ", n);
            scanf("%i", &x);
            x--;
            printf("Coordenada Y [1 -> %i]: ", n);
            scanf("%i", &y);
            y--;
            if (check_coord(x, y, board))
                printf("A posicao escolhida e invalida. Tente novamente:\n");
        } while(check_coord(x, y, board));

        make_move(player, x, y, board);

        if (check_winner(player, board)) {
            printf("O jogador %i ganhou!\n", player);
            alive = 0;
        }else if (count == n*n) {
            printf("O jogo acabou! Nao ha mais movimentos possiveis\n");
            alive = 0;
        }

        player = (player == 1) ? 2 : 1, count++;
    }while (alive);

    printf("Fim do jogo.\n");

    return 0;
}
