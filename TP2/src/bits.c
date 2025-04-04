#include <stdio.h>

int main() {
    unsigned int c = 0x00100008; 

  
    int a = (c >> (32 - 4)) & 1;
    int b = (c >> (32 - 20)) & 1;

  
    printf("%d\n", (a & b));
    
    return 0;
}
