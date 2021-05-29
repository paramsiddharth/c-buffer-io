#include <stdio.h>
#include <string.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

uint16* vid = (uint16*)0xB8000;

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

uint16 pval(uint8 ch, enum vga_color fore, enum vga_color back) {
    uint16 ax;
    uint8 ah;
    ah = back;
    ah <<= 4;
    ah |= fore;
    ax = ah;
    ax <<= 8;
    ax |= ch;

    return ax;
}

int main() {
    char* str = "Hello World!";
    for (int i = 0; i < strlen(str); i++) {
        *vid++ = pval(str[i], WHITE, BLACK);
    }
    return 0;
}