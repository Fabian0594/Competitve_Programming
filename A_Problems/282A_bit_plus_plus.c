#include <stdio.h>
#include <string.h>

int main() {

    int n, x;
    char operation[3];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", operation);
        int len = (int)strlen(operation);
        char last_two_chars[3];
        strncpy(last_two_chars, operation + len - 2, 2);
        last_two_chars[2] = '\0';
        if(!(strncmp(operation, "++", 2)) || !strcmp(last_two_chars, "++"))
        {
            x++;
        }
        if(!(strncmp(operation, "--", 2)) || !strcmp(last_two_chars, "--"))
        {
            x--;
        }
    }
    printf("%d", x);
    return 0;

}