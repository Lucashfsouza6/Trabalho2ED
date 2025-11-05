#include <stdio.h>
#include <stdbool.h> // Necessário para usar 'bool' (true/false)

/**
 * Função auxiliar para imprimir os elementos de um vetor.
 */
void imprimirVetor(int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

/**
 * Função que realiza a troca (swap) de dois elementos.
 */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Implementação do Bubble Sort Otimizado (Adaptativo).
 * * Ele usa uma flag 'trocou' para parar mais cedo
 * se o vetor já estiver ordenado.
 */
void bubbleSort(int vetor[], int n) {
    // Loop externo: controla o número de passagens
    for (int i = 0; i < n - 1; i++) {
        
        // --- Início da Otimização Adaptativa ---
        // Assumimos que nenhuma troca será feita nesta passagem
        bool trocou = false;
        // --- Fim da Otimização ---

        // Loop interno: "borbulha" o maior elemento da seção não ordenada
        // O '- i' é porque os 'i' últimos elementos já estão corretos.
        for (int j = 0; j < n - i - 1; j++) {
            
            // Compara elementos adjacentes
            if (vetor[j] > vetor[j + 1]) {
                // Realiza a troca
                trocar(&vetor[j], &vetor[j + 1]);
                
                // Marca que uma troca ocorreu nesta passagem
                trocou = true;
            }
        }

        // --- Verificação da Otimização ---
        // Se nenhuma troca ocorreu nesta passagem (trocou == false),
        // significa que o vetor JÁ ESTÁ ORDENADO.
        // Podemos parar o algoritmo mais cedo.
        if (trocou == false) {
            printf("\n(Parada otimizada: Vetor ordenado na passagem %d)\n", i + 1);
            break;
        }
    }
}

int main() {
    // 1. O vetor fornecido no exemplo
    int vetor[] = {11, 14, 24, 18, 20, 1};
    
    // Calcula o tamanho do vetor (n)
    int n = sizeof(vetor) / sizeof(vetor[0]);

    // 2. Mostra o vetor original
    printf("Vetor Original (Antes):\n");
    imprimirVetor(vetor, n);

    // 3. Chama a função de ordenação
    bubbleSort(vetor, n);

    // 4. Mostra o vetor ordenado
    printf("\nVetor Ordenado (Depois):\n");
    imprimirVetor(vetor, n);

    return 0;
}