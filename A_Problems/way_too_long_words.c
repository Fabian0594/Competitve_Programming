#include <stdio.h>
#include <string.h>

int main() {

    int n = 0;
    char long_word[101];
    scanf("%i", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", long_word);

        if (strlen(long_word) > 10) 
            printf("%c%i%c\n", long_word[0], (int)strlen(long_word) - 2, long_word[strlen(long_word) - 1]);
        else
            printf("%s\n", long_word);
    }

    return 0;
}