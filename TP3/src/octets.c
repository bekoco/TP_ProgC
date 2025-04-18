
#include <stdio.h>

void afficher_octets(void *ptr, size_t taille) {
    unsigned char *octet = (unsigned char *)ptr;
    for (size_t i = 0; i < taille; i++) {
        printf("0x%02x ", octet[i]);
    }
    printf("\n");
}

int main() {
    short s = 0x1234;
    int i = 0x12345678;
    long int li = 0x1234567890AB;
    float f = 123.456f;
    double d = 123.456789;
    long double ld = 123.456789123456789L;

    printf("=== Représentation en octets ===\n\n");

    printf("short        (%zu octets) : ", sizeof(s));
    afficher_octets(&s, sizeof(s));

    printf("int          (%zu octets) : ", sizeof(i));
    afficher_octets(&i, sizeof(i));

    printf("long int     (%zu octets) : ", sizeof(li));
    afficher_octets(&li, sizeof(li));

    printf("float        (%zu octets) : ", sizeof(f));
    afficher_octets(&f, sizeof(f));

    printf("double       (%zu octets) : ", sizeof(d));
    afficher_octets(&d, sizeof(d));

    printf("long double  (%zu octets) : ", sizeof(ld));
    afficher_octets(&ld, sizeof(ld));

    return 0;
}
