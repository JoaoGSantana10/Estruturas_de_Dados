#include <stdio.h>

int compara(char *s1, char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main() {
    char *a = "banana";
    char *b = "banana";
    char *c = "abacaxi";
    char *d = "zebra";

    printf("compara(\"%s\", \"%s\") = %d\n", a, b, compara(a, b)); // 0
    printf("compara(\"%s\", \"%s\") = %d\n", a, c, compara(a, c)); // > 0 (b > a)
    printf("compara(\"%s\", \"%s\") = %d\n", a, d, compara(a, d)); // < 0 (b < z)

    return 0;
}