#include <stdio.h>

int main(void)
{
    int Height;
    do
    {
        printf("Height: ");
        scanf("%d", &Height); 
    }
    while (Height < 1 || Height > 8);

    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Height - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}    