#include <stdio.h>
#include <math.h>
//Biblioteca utilizada para gerar a raiz quadrada

int latino(int n, int m[n][n]) {
    /*
     * Variáveis Utilizadas
     * i, j, k : Inteiro
     *  - Iteradores para percorrer os elementos da matriz m[n][n].
     * vet[n] : Inteiro
     *  - Vetor para armazenar e comparar a soma de cada linha/coluna.
     */

    int i, j, k, vet[n];

    for (i = 0; i < n; i++) {
        vet[i] = 0;
        //Inicializa (com 0) o vetor na posição i
        for (j = 0; j < n; j++) {
        //Percorre as linhas da matriz
            vet[i] += m[i][j];
            //Soma cada elemento da linha ao vetor na posicão i
            for (k = 0; k < n; k++)
            //Percorre cada elemento da linha i
                if (m[i][j] == m[i][k] && j != k) return 0;
                /* Caso o elemento m[i][j] for igual a algum outro
                 * elemento m[i][k] (com k indo de 0 a n e k != j) da
                 * mesma matriz, ou seja, exista um número repetido,
                 * retorna 0 (Falso) finalizando a execução.
                 */
        }
    }

    for (i = 0; i < n - 1; i++)
    //Percorre o vetor vet até o seu penúltimo elemento
        if (vet[i] != vet[i + 1]) return 0;
        /* Compara o vetor vet na posição i com o seu sucessor.
         * Caso o valor deles seja diferente (linhas com somas
         * diferentes), retorna 0 (Falso) e finaliza execução.
         */

    for (j = 0; j < n; j++) {
        vet[j] = 0;
        //Inicializa (com 0) o vetor na posição j
        for (i = 0; i < n; i++) {
        //Percorre as colunas da matriz
            vet[j] += m[i][j];
            //Soma cada elemento da coluna ao vetor na posicão j
            for (k = 0; k < n; k++)
            //Percorre cada elemento da coluna j
                if (m[i][j] == m[k][j] && i != k) return 0;
                /* Caso o elemento m[i][j] for igual a algum outro
                 * elemento m[k][j] (com k indo de 0 a n e k != i) da
                 * mesma matriz, ou seja, exista um número repetido,
                 * retorna 0 (Falso) finalizando a execução.
                 */
        }
    }

    for (i = 0; i < n - 1; i++)
    //Percorre o vetor v até o seu penúltimo elemento
        if (vet[i] != vet[i + 1]) return 0;
        /* Compara o vetor v na posição i com o seu sucessor.
         * Caso o valor deles seja diferente (colunas com somas
         * diferentes), retorna 0 (Falso) e finaliza execução.
         */

    return 1;
    /* Se não houver nenhum elemento repetido em
     * nenhuma linha e coluna, retorna 1 (Verdadeiro).
     */
}

int soma_matriz(int n, int m[n][n]) {
    /*
     * Variáveis Utilizadas
     * i, j : Inteiro
     *  - Iteradores para percorrer os elementos da matriz m[n][n].
     * s : Inteiro
     *  - Armazena a soma dos elementos da matriz m[n][n].
     */

    int i, j, s = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        //Percorre toda a matriz
            s += m[i][j];
            //Armazena a soma dos elementos em s

    return s;
    //Retorna o valor da soma dos elementos (s)
}

int valida_sudoku(int n, int r, int sud[n][n]) {
    /*
     * Variáveis Utilizadas
     * i, j, x, y : Inteiro
     *  - Iteradores para percorrer os elementos da matriz Sudoku.
     * soma : Inteiro
     *  - Recebe a soma de 1 a n, que cada linha/coluna/mini-matriz deve ter
     * mini : Array de Inteiro
     *  - Armazena os valores das 9 matrizes menores da matriz Sudoku.
     */

    int i, j, x, y, mini[r][r], soma = 0;

    for (i = 1; i <= n; i++)
        soma += i;
        //Cria a soma de 1 a n

    if (!latino(n, sud)) return 0;
    /* Verifica se a matriz Sudoku é latina.
     * Se não for, para a execução do programa
     * e retorna 0 (Falso).
     */

    for (x = 0; x < n; x += r)
        for (y = 0; y < n; y += r) {
        /* Contadores extras para "deslocar" a posicao da matriz (x, y).
         * São incrementados em raiz de n a cada laço para "livrar"
         * os elementos já lidos na iteração anterior.
         */
            for (i = 0; i < r; i++)
                for (j = 0; j < r; j++)
                //Percorre cada uma das n matrizes menores
                    mini[i][j] = sud[i+x][j+y];
                    //Atribui o valor do elemento atual à matriz menor
            if (soma_matriz(r, mini) != soma) return 0;
            /* Verifica se a soma de cada elemento da matriz menor
             * do Sudoku resulta no somatorio de 1 a n.
             * Se não, para a execução do programa e retorna 0 (Falso).
             */
        }

    return 1;
    /* Se a matriz Sudoku é latina e todas as suas matrizes menores forem
     * latinas e com soma igual a soma gerada, retorna 1 (Verdadeiro).
     */
}

int main() {
    /*
     * Variáveis Utilizadas
     * i, j : Inteiro
     *  - Iteradores para receber os elementos da matriz Sudoku.
     * n : Inteiro
     *  - Quadrado Perfeito.
     *  - Recebe o tamanho do lado do Sudoku.
     * raiz : Inteiro
     *  - Recebe a raiz quadrada de n.
     * sud : Array de Inteiro
     *  - Armazena os valores do sudoku.
     */

    int i, j, n, raiz;

    //Lê o tamanho do Sudoku e gera a sua raiz
    printf("Digite o tamanho do sudoku: ");
    scanf("%i", &n);
    raiz = sqrt(n);

    //Repete o procedimento até que n seja um quadrado perfeito
    while(raiz*raiz != n) {
        printf("O lado do sudoku deve ser um quadrado perfeito: ");
        scanf("%i", &n);
        raiz = sqrt(n);
    }

    //Cria a matriz Sudoku
    int sud[n][n];

    printf("Digite os numeros do seu Sudoku:\n");

    //Lê os elementos da matriz Sudoku
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%i", &sud[i][j]);

    /* Mostra "E" caso valida_sudoku seja verdadeiro (1)
     * Mostra "Nao e" caso seja falso (0)
     */
    printf("%s um sudoku valido", valida_sudoku(n, raiz, sud) ? "E" : "Nao e");

    return 0;
}
