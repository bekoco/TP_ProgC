#include <stdio.h>
#include <stdint.h> 

struct CouleurRGBA {
    uint8_t r;  // Rouge
    uint8_t g;  // Vert
    uint8_t b;  // Bleu
    uint8_t a;  // Alpha
};

int main() {
    struct CouleurRGBA couleurs[10] = {
        {0xef, 0x78, 0x12, 0xff},
        {0x00, 0x00, 0x00, 0xff},  // noir opaque
        {0xff, 0xff, 0xff, 0xff},  // blanc opaque
        {0xff, 0x00, 0x00, 0xff},  // rouge
        {0x00, 0xff, 0x00, 0xff},  // vert
        {0x00, 0x00, 0xff, 0xff},  // bleu
        {0xff, 0xff, 0x00, 0x80},  // jaune translucide
        {0x00, 0xff, 0xff, 0x80},  // cyan translucide
        {0xff, 0x00, 0xff, 0x40},  // magenta semi-transparent
        {0x12, 0x34, 0x56, 0x88}   // couleur personnalisée
    };

    printf("=== Couleurs RGBA ===\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Couleur %d : R = 0x%02x, G = 0x%02x, B = 0x%02x, A = 0x%02x\n",
               i + 1,
               couleurs[i].r,
               couleurs[i].g,
               couleurs[i].b,
               couleurs[i].a);
    }

    return 0;
}
