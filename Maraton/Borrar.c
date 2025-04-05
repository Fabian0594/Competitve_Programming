#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100000

void borrar(const char *cadena, const char *eliminar, char *resultado) {
    bool eliminar_set[256] = {false};
    int i, j = 0;

    for (i = 0; eliminar[i] != '\0'; i++) {
        if (eliminar[i] != '[' && eliminar[i] != ']') {
            eliminar_set[(unsigned char)eliminar[i]] = true;
        }
    }

    for (i = 0; cadena[i] != '\0'; i++) {
        if (!eliminar_set[(unsigned char)cadena[i]]) {
            if (j == 0 || resultado[j - 1] != cadena[i]) {
                resultado[j++] = cadena[i];
            }
        }
    }
    resultado[j] = '\0';
}

int main() {
    char cadena[MAX_LEN + 1];
    char eliminar[MAX_LEN + 1];
    char resultado[MAX_LEN + 1];

    scanf("%s", cadena);
    scanf("%s", eliminar);asd

    borrar(cadena, eliminar, resultado);

    printf("%s\n", resultado);

    return 0;
}