#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int p[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int visiting[n + 1];
    for (int i = 1; i <= n; i++) {
        visiting[i] = 0;
    }
    int count = 0;
    int actual = 1;
    while (!visiting[actual]) {
        visiting[actual] = 1;
        count++;
        actual = p[actual];
    }

    printf("%d\n", count);
    return 0;
}
