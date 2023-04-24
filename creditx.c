#include <cs50.h>
#include <stdio.h>

long get_number(void);
void print_type(long cardNumber);

// This is an extension on problem set (week 1) on Credit from Harvard cs50.
// Adds Discover credit network.

// MASTERCARD: 16-Digits, begins with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digits, begins with: 4
// AMEX: 15-Digits, begins with: 34 or 37
// DISCOVER: 16-Digits, begins with 6

// Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the second number to the last
// 2. Add the sum of those digits
// 3. Add the sum of the other digits
// 4. If the total sum ends with a 0, it is valid!

int main(void)
{
    // Prompt user for credit card number
    long cardNumber = get_number();

    // Print out type of credit card or whether invalid
    print_type(cardNumber);
}


long get_number(void)
{
    long cardNumber;

    cardNumber = get_long("Number: ");

    return cardNumber;

}


void print_type(long cardNumber)
{
    // Check for credit card type
    long a = cardNumber;
    int len = 0;
    do
    {
        a = a / 10;
        len++;
    }
    while (a > 0);

    // if (len != 13 && len != 15 && len != 16)
    // {
    //     printf("INVALID\n");
    // }


    long b = cardNumber;
    int last; // Last digit of the card number and every other digit after that. From right to left.
    int prod; // Computes step 1 of the Luhn's Algorithm outlined above.
    int second2last; // Second to last digit and every other digit after the second to last digit. From right to left.
    int sum = 0; // Computes step 3 of the Luhn's Algorithm outlined above.
    int prod_sum = 0; // Computes step 2 of the Luhn's Algorithm outlined above.
    int total; // Computes sum of sum and prod_sum

    do
    {
        // Last digit
        last = b % 10;
        sum += last;

        // Move to next digit to the left
        b = b / 10;

        second2last = b % 10;

        // Move to next digit to the left
        b = b / 10;

        prod = 2 * second2last;

        // This loop splits a number into digits and sums the digits. e.g 12 = 1+2 = 3
        int digit, digitSum = 0;
        while (prod > 0)
        {
            digit = prod % 10;
            digitSum += digit;

            prod = prod / 10;
        }

        prod_sum += digitSum;

    }
    while (b > 0);

    total = prod_sum + sum;



    // This part of code is used when length is odd.
    // And classifies the credit card type


    long c = cardNumber;
    int second2last_odd; // Second2last for cardnumber of odd length.

    // Divide number by 10 to find second to last digit

    do
    {
        c = c / 10;

        second2last_odd = c % 10;

    }
    while (c > 99);


    if ((total % 10) != 0)
    {
        printf("INVALID\n");
    }

    else
    {
        // case 1
        if (len == 13 && last == 4) // because len is odd
        {
            printf("VISA\n");
        }

        else if (len == 16 && second2last == 4)
        {
            printf("VISA\n");
        }

        // case 2
        else if (len == 15 && last == 3) // because len is odd
        {
            if (second2last_odd == 4 || second2last_odd == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // case 3
        else if (len == 16 && second2last == 5)
        {
            if (last == 1 || last == 2 || last == 3 || last == 4 || last == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // case 4
        else if (len == 16 && second2last == 6)
        {
            printf("DISCOVER\n");
        }

        else
        {
            printf("INVALID\n");
        }

    }


}
