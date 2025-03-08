#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    long long h = 0;
    long long sum = 0;
    while (sum <= n) {
        h++;
        sum += h;
    }
    printf("%lld\n", h - 1);
    return 0;
}