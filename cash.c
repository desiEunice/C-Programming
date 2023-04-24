#include <cs50.h>
#include <stdio.h>

# Problem set from week 1 of Harvard's CS50 class
# Uses the greedy algorithm
# We want to minimize the number of coins that are dispensed when making a change.
# Think of a “greedy” cashier as one who wants to take the biggest bite out of this problem as possible with each coin they take out of the drawer. 
# For instance, if some customer is owed 31¢, the biggest first (i.e., best immediate, or local) bite that can be taken is 25¢. Remainder: 31-25 = 6.
# The greedy cashier would move on to a bite of size 5¢, leaving him or her with a 1¢ problem. 
# At that point, greed calls for 1¢ bite and the problem is solved. 

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);

}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // This function finds the whole number of any change (in cents) divided by
    // the quarter amount which is 25 cents.

    int num_quarters = cents / 25;

    return num_quarters;
}

int calculate_dimes(int cents)
{
    // The remaining change (in cents) divided by 10 cents

    int num_dimes = cents / 10;
    return num_dimes;
}

int calculate_nickels(int cents)
{
    // The remaining change (in cents) divided by 5 cents

    int num_nickles = cents / 5;
    return num_nickles;
}

int calculate_pennies(int cents)
{
    // The remaining change (in cents) divided by 1 cent

    int num_pennies = cents / 1;
    return num_pennies;
}
