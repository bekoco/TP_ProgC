#include <stdio.h>

int main() {
    // Types char
    char c = 'A';
    signed char sc = -65;
    unsigned char uc = 200;

    // Types short
    short s = -12345;
    signed short ss = -12345;
    unsigned short us = 54321;

    // Types int
    int i = -100000;
    signed int si = -100000;
    unsigned int ui = 100000;

    // Types long int
    long int li = -123456789;
    signed long int sli = -123456789;
    unsigned long int uli = 123456789;

    // Types long long int
    long long int lli = -1234567890123;
    signed long long int slli = -1234567890123;
    unsigned long long int ulli = 1234567890123;

    // Types flottants
    float f = 3.14f;
    double d = 3.1415926535;
    long double ld = 3.141592653589793238L;

    // Affichage des valeurs
    printf("char : %c\n", c);
    printf("signed char : %d\n", sc);
    printf("unsigned char : %u\n", uc);

    printf("short : %hd\n", s);
    printf("signed short : %hd\n", ss);
    printf("unsigned short : %hu\n", us);

    printf("int : %d\n", i);
    printf("signed int : %d\n", si);
    printf("unsigned int : %u\n", ui);

    printf("long int : %ld\n", li);
    printf("signed long int : %ld\n", sli);
    printf("unsigned long int : %lu\n", uli);

    printf("long long int : %lld\n", lli);
    printf("signed long long int : %lld\n", slli);
    printf("unsigned long long int : %llu\n", ulli);

    printf("float : %.2f\n", f);
    printf("double : %.10f\n", d);
    printf("long double : %.15Lf\n", ld);

    return 0;
}
