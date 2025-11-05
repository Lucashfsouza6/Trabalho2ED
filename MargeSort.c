#include <stdio.h>
#include <stdlib.h> // Para alocação de memória (malloc), se necessário

/**
 * @brief Função principal de intercalação (Merge).
 * Junta dois sub-vetores ordenados em um único vetor ordenado.
 *
 * @param vetor O vetor principal que contém os dados.
 * @param esq O índice inicial (esquerda).
 * @param meio O índice do meio (que divide os dois sub-vetores).
 * @param dir O índice final (direita).
 */
void merge(int vetor[], int esq, int meio, int dir) {
    int i, j, k;
    
    // 1. Calcular os tamanhos dos dois sub-vetores temporários
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    // 2. Criar os vetores temporários (L = Left/Esquerda, R = Right/Direita)
    // Usamos VLA (Variable Length Arrays), que é padrão do C99
    int L[n1], R[n2];

    // 3. Copiar os dados do vetor principal para os temporários
    for (i = 0; i < n1; i++)
        L[i] = vetor[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    // --- Início da Intercalação (Merge) ---
    
    // Índices para percorrer os vetores L (i), R (j) e o principal (k)
    i = 0; // Índice inicial do sub-vetor L
    j = 0; // Índice inicial do sub-vetor R
    k = esq; // Índice inicial do sub-vetor principal (onde vamos reinserir)

    // 4. Intercalar L e R de volta no vetor principal
    // Compara L[i] e R[j] e insere o menor em vetor[k]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    // 5. Copiar os elementos restantes de L (se houver)
    // (Isso só acontece se o sub-vetor R terminar primeiro)
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // 6. Copiar os elementos restantes de R (se houver)
    // (Isso só acontece se o sub-vetor L terminar primeiro)
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief A função principal que implementa o MergeSort (recursiva).
 *
 * @param vetor O vetor a ser ordenado.
 * @param esq O índice inicial da sub-lista (esquerda).
 * @param dir O índice final da sub-lista (direita).
 */
void mergeSort(int vetor[], int esq, int dir) {
    // Condição de parada (caso base):
    // Se esq >= dir, o sub-vetor tem 0 ou 1 elemento,
    // então já está ordenado.
    if (esq < dir) {
        
        // 1. Dividir: Acha o ponto do meio
        // (esq + (dir - esq) / 2) é mais seguro contra overflow
        // do que (esq + dir) / 2
        int meio = esq + (dir - esq) / 2;

        // 2. Conquistar: Ordena as duas metades recursivamente
        mergeSort(vetor, esq, meio);       // Ordena a metade da esquerda
        mergeSort(vetor, meio + 1, dir); // Ordena a metade da direita

        // 3. Combinar: Intercala as duas metades ordenadas
        merge(vetor, esq, meio, dir);
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
    int meu_vetor[] = {6, 3, 8, 2, 9, 1};
    
    // Calcula o número de elementos no vetor
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original: ");
    imprimirVetor(meu_vetor, n);

    // Chama a função MergeSort
    // Queremos ordenar do índice 0 até o índice n-1
    mergeSort(meu_vetor, 0, n - 1);

    printf("Vetor ordenado: ");
    imprimirVetor(meu_vetor, n);

    return 0;
}