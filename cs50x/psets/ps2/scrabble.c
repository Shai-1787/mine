#include <stdio.h>

int main(void)
{
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    char word[32];
    int player_score[2] = {0, 0};

    for (int player = 0; player < 2; player++)
    {      
        printf("Player %d: ", player + 1);
        if (scanf("%31s", word) != 1)
        {
            return 1;
        }
    
        for (int i = 0; word[i] != '\0'; i++)
        {
            char c = word[i];
            if (c >= 'A' && c <= 'Z')
            {
                player_score[player] += scores[c - 'A'];
            }
            else if (c >= 'a' && c <= 'z')
            {
                player_score[player] += scores[c - 'a'];
            }
        }
    }
    
    if (player_score[0] > player_score[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (player_score[1] > player_score[0])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}