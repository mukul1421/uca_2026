#include <stdio.h>

void url_encode(char str[], int len)
{
    int space = 0;

    // Count spaces
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
            space++;
    }

    int index = len + (2 * space);

    str[index] = '\0';

    for(int i = len - 1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        }
        else
        {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main()
{
    char str[100] = "Hello World";

    url_encode(str, 11);

    printf("%s", str);

    return 0;
}
