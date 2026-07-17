#include <stdio.h>

void reverse_string(char str[]) {
    int i = 0;
    int j = 0;

    while (str[j] != '\0' && str[j] != '\n') {
        j++;
    }

    j--; 

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    reverse_string(str);

    printf("Reversed string: %s", str);

    return 0;
}
