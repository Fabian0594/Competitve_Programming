#include <stdio.h>

int main() {

    int watermelon_weigh = 0;
    scanf("%i", &watermelon_weigh);
    if (watermelon_weigh % 2 == 0 && watermelon_weigh > 0)
        printf("YES\n");
    else 
        printf("NO\n");


}