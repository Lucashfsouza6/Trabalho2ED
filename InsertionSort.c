#include <stdio.h>


void insertionSort(int vetor[], int n) {
    int i, chave, j;

    // O loop principal começa no segundo elemento (índice 1),
    // pois consideramos o primeiro elemento (índice 0) como
    // a "parte ordenada" inicial.
    for (i = 1; i < n; i++) {
        
        // 1. "Pegar a carta":
        // 'chave' é o elemento que vamos inserir no lugar certo.
        chave = vetor[i];
        
        // 'j' aponta para o último elemento da parte ordenada.
        j = i - 1;

        // 2. "Encontrar o lugar":
        // Move os elementos da parte ordenada (vetor[0...i-1])
        // que são maiores que a 'chave' para uma posição à frente
        // da sua posição atual.
        // Isso "abre espaço" para a 'chave'.
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j]; // Desloca o elemento maior para a direita
            j = j - 1;               // Continua comparando para a esquerda
        }
        
        // 3. "Inserir a carta":
        // Após o 'while', 'j+1' é a posição correta onde a
        // 'chave' deve ser inserida.
        vetor[j + 1] = chave;

        /* // Opcional: descomente este bloco para ver cada passo
        printf("Passo %d (inseriu %d): ", i, chave);
        for (int k = 0; k < n; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");
        */
    }
}

// Função auxiliar para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// --- Execução do Código ---
int main() {
    int meu_vetor[] = {8, 5, 1, 9, 3, 6};
    
    // Calcula o número de elementos no vetor
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original: ");
    imprimirVetor(meu_vetor, n);

    // Chama a função InsertionSort
    insertionSort(meu_vetor, n);

    printf("Vetor ordenado: ");
    imprimirVetor(meu_vetor, n);

    return 0;
}