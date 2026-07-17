#include <stdio.h>

int find_substring(char str[], char sub[]) {
    int i, j;

    for (i = 0; str[i] != '\0'; i++) {

        j = 0;

        while (sub[j] != '\0' && str[i + j] == sub[j]) {
            j++;
        }

        if (sub[j] == '\0') {
            return i;
        }
    }

    return -1;
}

int main() {
    char str[100];
    char sub[100];

    printf("Enter main string: ");
    scanf(" %[^\n]", str);

    printf("Enter substring: ");
    scanf(" %[^\n]", sub);

    int index = find_substring(str, sub);

    if (index == -1)
        printf("Substring not found");
    else
        printf("Substring found at index %d", index);

    return 0;
}
