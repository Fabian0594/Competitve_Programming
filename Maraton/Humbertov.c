#include <stdio.h>
#include <stdlib.h>

// Función para calcular el MCD usando el algoritmo de Euclides
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para resolver un caso de prueba
int find_winner(int n) {
    int *circle = (int *)malloc((n - 1) * sizeof(int));
    int size = n - 1;

    // Inicializar el círculo de estudiantes (2, 3, ..., n)
    for (int i = 0; i < size; i++) {
        circle[i] = i + 2;
    }

    int current_index = 0; // El índice del estudiante que comienza
    while (size > 1) {
        int current_student = circle[current_index];
        int next_index = (current_index + 1) % size;
        int next_student = circle[next_index];

        // Calcular el MCD entre el estudiante actual y el siguiente
        if (gcd(current_student, next_student) > 1) {
            // Eliminar al estudiante siguiente
            for (int i = next_index; i < size - 1; i++) {
                circle[i] = circle[i + 1];
            }
            size--;
            if (next_index < size) {
                current_index = next_index % size;
            } else {
                current_index = 0;
            }
        } else {
            // Continuar con el siguiente estudiante
            current_index = next_index;
        }
    }

    int winner = circle[0];
    free(circle);
    return winner;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", find_winner(n));
    }

    return 0;
}