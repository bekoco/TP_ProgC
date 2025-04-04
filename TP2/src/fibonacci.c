#include <stdio.h>

void main() {
    int n = 7;
    int val[] = {0,1};
    printf("%d %d ", val[0], val[1]);
    for(int i = 2; i < n; i++) {
        printf("%d ", val[0]+val[1]);
        val[1]+=val[0];
        val[0] = val[1]-val[0];     
    }
}
