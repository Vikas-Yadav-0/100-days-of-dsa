#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    // Input
    scanf("%s", str);

    // Find length
    len = strlen(str);

    // Reverse print
    for(i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
