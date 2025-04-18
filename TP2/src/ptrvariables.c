#include <stdio.h>

int main() {
    char c = 0x01;
    short s = 0x0203;
    int i = 0x04050607;
    long int li = 0x08090A0B;
    long long int lli = 0x0C0D0E0F10111213;
    float f = 1.23f;
    double d = 4.56;
    long double ld = 7.89;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pli = &li;
    long long int *plli = &lli;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    printf("=== Avant manipulation ===\n");
    printf("char        : adresse = %p, valeur = 0x%02x\n", (void*)pc, *pc);
    printf("short       : adresse = %p, valeur = 0x%04x\n", (void*)ps, *ps);
    printf("int         : adresse = %p, valeur = 0x%08x\n", (void*)pi, *pi);
    printf("long int    : adresse = %p, valeur = 0x%08lx\n", (void*)pli, *pli);
    printf("long long   : adresse = %p, valeur = 0x%016llx\n", (void*)plli, *plli);
    printf("float       : adresse = %p, valeur = %a\n", (void*)pf, *pf);
    printf("double      : adresse = %p, valeur = %a\n", (void*)pd, *pd);
    printf("long double : adresse = %p, valeur = %La\n", (void*)pld, *pld);

    *pc = 0xAA;
    *ps = 0xBBBB;
    *pi = 0xCCCCCCCC;
    *pli = 0xDDDDDDDD;
    *plli = 0xEEEEEEEEEEEEEEEE;
    *pf = 9.87f;
    *pd = 6.54;
    *pld = 3.21;

    printf("\n=== Après manipulation ===\n");
    printf("char        : adresse = %p, valeur = 0x%02x\n", (void*)pc, *pc);
    printf("short       : adresse = %p, valeur = 0x%04x\n", (void*)ps, *ps);
    printf("int         : adresse = %p, valeur = 0x%08x\n", (void*)pi, *pi);
    printf("long int    : adresse = %p, valeur = 0x%08lx\n", (void*)pli, *pli);
    printf("long long   : adresse = %p, valeur = 0x%016llx\n", (void*)plli, *plli);
    printf("float       : adresse = %p, valeur = %a\n", (void*)pf, *pf);
    printf("double      : adresse = %p, valeur = %a\n", (void*)pd, *pd);
    printf("long double : adresse = %p, valeur = %La\n", (void*)pld, *pld);

    return 0;
}
