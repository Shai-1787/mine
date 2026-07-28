#include <stdio.h>

int main(void)
{
    int changes;
    do
    {
        printf("Change owed: ");
        if (scanf("%d", &changes) != 1)
        {
            int c;

            // 清除输入缓冲区中的非整数内容
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            changes = -1;
        }
    }
    while (changes < 0 );

    int coins = 0;
    int quarters = changes / 25;
    coins += quarters;
    changes -= quarters * 25;
    int dimes = changes / 10;
    coins += dimes;
    changes -= dimes * 10;
    int nickels = changes / 5;
    coins += nickels;
    changes -= nickels * 5;
    int pennies = changes;
    coins += pennies;

    printf("%d\n", coins);
}