#include <stdio.h>

int main(void)
{
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    char word[32];

    do
    {
        printf("Player 1: ");
        if (scanf("%31s", word) != 1)
        {
            return 1; // Exit if input is not a valid string
        }
    }
    while (word[0] == '\0'); // Repeat until a non-empty word is entered

    // Calculate score for Player 1
    int score_1 = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char letter = word[i];
        if (letter >= 'A' && letter <= 'Z')
        {
            score_1 += scores[letter - 'A'];
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            score_1 += scores[letter - 'a'];
        }
    }

    do
    {
        printf("Player 2: ");
        if (scanf("%31s", word) != 1)
        {
            return 1; // Exit if input is not a valid string
        }
    }
    while (word[0] == '\0'); // Repeat until a non-empty word is entered
    
    int score_2 = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char letter = word[i];
        if (letter >= 'A' && letter <= 'Z')
        {
            score_2 += scores[letter - 'A'];
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            score_2 += scores[letter - 'a'];
        }
    }
    
    // Determine the winner
    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_2 > score_1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}