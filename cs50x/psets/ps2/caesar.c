#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(char *str);

int main(int arvc, char *argv[])
{
    if (arvc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (! only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    char plaintext[1000];
    printf("plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);

    char ciphertext[1000];
    int i;
    for (i = 0; i < plaintext[i] != 0; i++)
    {
        //ciphertext[i] = (plaintext[i] + key) % 26
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i + 1] = '\0';
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int only_digits(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (! isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;   
}