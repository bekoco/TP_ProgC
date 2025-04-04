#include <stdio.h>

int main() {
    int n = 7;
   
    unsigned long long int U0 = 0, U1 = 1, Un;

    printf("Suite de Fibonacci jusqu'à U%d : ", n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%llu", U0);
        } else if (i == 1) {
            printf(", %llu", U1);
        } else {
            Un = U0 + U1;
            printf(", %llu", Un);
            U0 = U1;
            U1 = Un;
        }
    }
    
    printf("\n");
    return 0;
}
