#include <stdio.h>

// Função para trocar dois elementos em um array
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que seleciona o pivô e rearranja os elementos menores à esquerda e os maiores à direita
int particionar(int arr[], int inicio, int fim) {
    int pivô = arr[fim]; // Escolhe o último elemento como pivô
    int i = (inicio - 1);  // Índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivô) {
            i++; // Incrementa o índice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[fim]);

    printf("Pivô: %d, Início: %d, Fim: %d\n", pivô, inicio, fim);
    printf("Array: ");
    for (int k = inicio; k <= fim; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    return (i + 1);
}

// Função principal do QuickSort
void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra o pivô, rearranja os elementos e obtém o índice do pivô
        int pi = particionar(arr, inicio, fim);

        // Ordena os elementos antes e depois do pivô
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fim);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
