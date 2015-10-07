#include <stdio.h>

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
    //Percorre o vetor vet até o seu penúltimo elemento
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

int main() {
    /*
     * Variáveis Utilizadas
     * n : Inteiro
     *  - Lado do quadrado.
     * i, j : Inteiro
     *  - Iteradores para receber os elementos do quadrado.
     * l, c : Inteiro
     *  - Armazenam Valores booleanos (0, 1) se atendem aos requisitos.
     *    - l = Linhas
     *    - c = Colunas
     * quad : Array de Inteiro
     *  - Armazena os valores do quadrado latino.
     *  - Tamanho n X n.
    */

    int n, i, j, l, c;

    printf("Tamanho do Quadrado: ");
    scanf("%i", &n);

    //Inicializa o array com o tamanho n X n informado.
    int quad[n][n];

    printf("Digite os elementos do quadrado latino:\n");

    //Lê os elementos do quadrado latino
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%i", &quad[i][j]);

    /* Mostra "E" caso a função latino seja verdadeira (1)
     * Mostra "Nao e" caso seja falsa (0)
     */
    printf("%s um quadrado latino", latino(n, quad) ? "E" : "Nao e");

    return 0;
}
