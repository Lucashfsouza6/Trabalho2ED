#include <stdio.h> // Para incluir as funções de printf

// Função para trocar dois elementos de lugar
void trocar(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função que implementa o Selection Sort
void selectionSort(int vetor[], int n) {
    int i, j, indice_do_menor;

    // Loop principal: percorre todo o vetor, exceto o último
    // 'i' marca o início da parte "não ordenada"
    for (i = 0; i < n - 1; i++) {
        
        // 1. Encontrar o menor:
        // Assume que o primeiro elemento (i) é o menor
        indice_do_menor = i;
        
        // Loop interno: percorre o restante do vetor (a partir de i+1)
        // para encontrar o verdadeiro menor
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[indice_do_menor]) {
                // Se encontrar um menor, atualiza o índice
                indice_do_menor = j;
            }
        }

        // 2. Trocar:
        // Troca o menor elemento encontrado com o elemento da posição 'i'
        // (Usamos uma função auxiliar 'trocar' para isso)
        trocar(&vetor[indice_do_menor], &vetor[i]);
        
        /* // Opcional: descomente este bloco para ver cada passo
        printf("Passo %d: ", i + 1);
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
    
    // 'sizeof(meu_vetor)' dá o tamanho total em bytes
    // 'sizeof(meu_vetor[0])' dá o tamanho de um inteiro em bytes
    // A divisão dá o número de elementos
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original: ");
    imprimirVetor(meu_vetor, n);

    // Chama a função para ordenar o vetor
    selectionSort(meu_vetor, n);

    printf("Vetor ordenado: ");
    imprimirVetor(meu_vetor, n);

    return 0; // Indica que o programa terminou com sucesso
}