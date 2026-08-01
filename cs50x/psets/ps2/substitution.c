#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_is_valid(const char *str);

int main(int argc, char *argv)
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (validate_is_valid(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char plaintext[1000];
    printf("plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    char *key = argv[1];
    char ciphertext[1000];
    int i;
    for (i = 0; plaintext[i]!= '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }    
    }
    ciphertext[i] = '\0';
    printf("ciphertext: %s", ciphertext);
    return 0;
}

int validate_is_valid(const char *str)
{
    if (strlen(str) != 26)
    {
        return 1;
    }

    int seen[26] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (! isalpha(str[i]))
        {
           return 1;
        }

        int index = toupper(str[i]) - 'A';
        if (seen[index])
        {
            return 1;
        }
        
        seen[index] = 1;       
    }
    return 0;
}