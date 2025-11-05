#include <stdio.h>

// Função auxiliar para trocar dois elementos de posição
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Função principal de partição (Esquema de Lomuto).
 *
 * Esta função pega o último elemento como pivô, coloca o pivô
 * em sua posição correta no vetor ordenado, e coloca todos os
 * elementos menores que o pivô à sua esquerda, e os maiores à sua direita.
 *
 * @param vetor O vetor a ser particionado.
 * @param baixo O índice inicial (low).
 * @param alto O índice final (high).
 * @return O índice onde o pivô foi colocado.
 */
int particionar(int vetor[], int baixo, int alto) {
    // 1. Escolher o pivô (aqui, escolhemos o último elemento)
    int pivo = vetor[alto];
    
    // 'i' será o índice do "último elemento menor que o pivô"
    // Começa antes do primeiro elemento
    int i = (baixo - 1);

    // 2. Percorrer o vetor (exceto o pivô)
    for (int j = baixo; j <= alto - 1; j++) {
        
        // Se o elemento atual (j) for menor que o pivô...
        if (vetor[j] < pivo) {
            i++; // ...move a "fronteira" dos menores...
            trocar(&vetor[i], &vetor[j]); // ...e joga o elemento 'j' para dentro dela.
        }
    }
    
    // 3. Colocar o pivô no lugar certo
    // No final, 'i+1' é a posição correta do pivô.
    // Trocamos o pivô (vetor[alto]) com o elemento em 'i+1'.
    trocar(&vetor[i + 1], &vetor[alto]);
    
    // Retorna o índice onde o pivô agora está
    return (i + 1);
}

/**
 * @brief A função principal que implementa o QuickSort.
 *
 * @param vetor O vetor a ser ordenado.
 * @param baixo O índice inicial da sub-lista.
 * @param alto O índice final da sub-lista.
 */
void quickSort(int vetor[], int baixo, int alto) {
    // Condição de parada (caso base da recursão):
    // Se 'baixo' for maior ou igual a 'alto', o segmento tem 0 ou 1 elemento,
    // então já está ordenado.
    if (baixo < alto) {
        
        // 1. Particionar:
        // 'ip' é o índice do pivô, que já está na posição correta.
        int ip = particionar(vetor, baixo, alto);

        // 2. Conquistar (chamar recursivamente):
        // Ordena a sub-lista à esquerda do pivô
        quickSort(vetor, baixo, ip - 1);
        
        // Ordena a sub-lista à direita do pivô
        quickSort(vetor, ip + 1, alto);
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
    int meu_vetor[] = {5, 1, 9, 3, 7, 2};
    
    // Calcula o número de elementos no vetor
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original: ");
    imprimirVetor(meu_vetor, n);

    // Chama a função QuickSort
    // Queremos ordenar do índice 0 até o índice n-1
    quickSort(meu_vetor, 0, n - 1);

    printf("Vetor ordenado: ");
    imprimirVetor(meu_vetor, n);

    return 0;
}