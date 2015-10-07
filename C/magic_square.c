#include <stdio.h>

/*
 * Variáveis Globais Utilizadas
 * cm : Inteiro
 *  - Constante Mágica, o valor da soma que cada linha/coluna/diagonal deve ter.
 *  - Dada pela fórmula: N*(N*N+1)/2.
 */

int cm;

int linhas(int n, int m[n][n]) {
    /*
     * Variáveis Utilizadas
     * i, j : Inteiro
     *  - Iteradores para percorrer os elementos da matriz m[n][n].
     * s : Inteiro
     *  - Variável para armazenar a soma de cada linha.
     */

    int i, j, s = 0;

    for (i = 0; i < n; i++, s = 0) {
    //Percorre as linhas e zera s (soma) a cada execução
        for (j = 0; j < n; j++)
            s += m[i][j];
            //Soma cada elemento da linha i
        if (s != cm) return 0;
        /* Retorna 0 (Falso) e finaliza funcão caso o valor
         * da soma seja diferente da constante mágica (cm).
         */
    }

    return 1;
    /* Se todas as linhas tiverem a soma igual a
     * constante mágica, retorna 1 (Verdadeiro).
     */
}

int colunas(int n, int m[n][n]) {
    /*
     * Variáveis Utilizadas
     * i, j : Inteiro
     *  - Iteradores para percorrer os elementos da matriz m[n][n].
     * s : Inteiro
     *  - Variável para armazenar a soma de cada coluna.
     */

    int i, j, s = 0;

    for (j = 0; j < n; j++, s = 0) {
    //Percorre as colunas e zera s (soma) a cada execução
        for (i = 0; i < n; i++)
            s += m[i][j];
            //Soma cada elemento da coluna j
        if (s != cm) return 0;
        /* Retorna 0 (Falso) e finaliza funcão caso o valor
         * da soma seja diferente da constante mágica (cm).
         */
    }

    return 1;
    /* Se todas as colunas tiverem a soma igual
     * a constante mágica, retorna 1 (Verdadeiro).
     */
}

int diagonais(int n, int m[n][n]) {
    /*
     * Variáveis Utilizadas
     * i, j : Inteiro
     *  - Iteradores para percorrer os elementos da matriz m[n][n].
     * s : Inteiro
     *  - Variável para armazenar a soma das diagonais.
     */

    int i, j, s = 0;

    for (i = 0; i < n; i++)
        s += m[i][i];
        /* Soma cada elemento da diagonal principal.
         * Faz parte da diagonal principal quando i é igual a j.
         */

    if(s != cm) return 0;
    /* Retorna 0 (Falso) e finaliza funcão caso o valor
     * da soma seja diferente da constante mágica (cm).
     */

    for (i = 0, s = 0; i < n; i++)
    //Percorre as linhas e inicializa s (soma) com 0.
        for (j = 0; j < n; j++)
            if (i + j == n - 1) s += m[i][j];
            /* Soma cada elemento da diagonal secundaria.
             * Faz parte da diagonal secundária quando i + j são iguais a n.
             * Como o primeiro elemento da matriz é 0, deve subtrair 1 de n.
             */

    return (s == cm) ? 1 : 0;
    /* Se as diagonais forem iguais entre si e a
     * constante mágica, retorna 1 (Verdadeiro).
     */
}

int quad_magico(int n, int m[n][n]) {
    /*
     * Depende das funções linhas(), colunas() e diagonais()
     * para funcionar corretamente
     */

    return (linhas(n, m) && colunas(n, m) && diagonais(n, m)) ? 1 : 0;
}

int main() {
    /*
     * Variáveis Utilizadas
     * n : Inteiro
     *  - Lado do quadrado.
     * i, j : Inteiro
     *  - Iteradores para receber os elementos do quadrado.
     * quad : Array de Inteiro
     *  - Armazena os valores do quadrado mágico.
     *  - Tamanho n X n.
     */

    int n, i, j;

    printf("Tamanho do Quadrado: ");
    scanf("%i", &n);

    cm = n*(n*n+1)/2;

    //Inicializa o array com o tamanho n X n informado.
    int quad[n][n];

    printf("Digite os elementos do quadrado magico:\n");

    //Lê os elementos do quadrado magico
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%i", &quad[i][j]);

    /* Mostra "E" caso a funçao quad_magico seja verdadeira (1)
     * Mostra "Nao e" caso seja falsa (0)
     */
    printf("%s um quadrado magico", quad_magico(n, quad) ? "E" : "Nao e");

    return 0;
}

