#include <stdio.h>

int my_strlen(char str[]) {
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n' )  {
        i++;
    }

    return i;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    //scanf("%s", str);
    fgets(str,100,stdin);

    printf("Length = %d\n", my_strlen(str));

    return 0;
}
