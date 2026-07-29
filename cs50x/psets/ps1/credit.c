#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long card_number;
    char card_number_str[32]; // Buffer to hold the card number as a string
    do
    {
        printf("Card Number: ");

        if (scanf("%31s", card_number_str) != 1)
        {
            return 1; // Exit if input is not a valid long long
        }
        card_number = strtoll(card_number_str, NULL, 10); // Convert string to long long
    }
    while (card_number < 0);

    //implement Luhn's algorithm to validate the credit card number
    int sum = 0;
    int position = 0;

    for (int i = strlen(card_number_str) - 1; i >= 0; i--)
    {
        int digit = card_number_str[i] - '0'; // Convert char to int
        if (position % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9; // Sum the digits of the product
            }
        }
        sum += digit;
        position++;
    }
    
    if (sum % 10 == 0)
    {
        // Valid credit card number
        if (strlen(card_number_str) == 15 && (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else if (strlen(card_number_str) == 16 && (card_number / 100000000000000 >= 51 && card_number / 100000000000000 <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((strlen(card_number_str) == 13 || strlen(card_number_str) == 16) && (card_number / 1000000000000 == 4 || card_number / 1000000000000000 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            // Invalid credit card number
            printf("INVALID\n");
        }
    }
    else
    {
        // Invalid credit card number
        printf("INVALID\n");
    }
} 