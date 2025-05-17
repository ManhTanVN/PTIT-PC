#include <stdio.h>

int main() {
    unsigned int dong, cot, n, m;
    scanf("%d%d", &n, &m);
    
    for (dong = 0; dong < n; dong++) {
        printf("\n");
        for (cot = 1; cot <= m; cot++) {
            printf("%d\t", dong + cot);
        }
    }
    
    return 0;
}
