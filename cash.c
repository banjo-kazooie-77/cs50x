#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    //ask the user for the change owed

    float c;
    do
    {
        c = get_float("Change owed: ");
    }
    while (c < 0);

    //calculate the cents in the customer's change
    int cents = round(c * 100);

    //calculate the coins in a customer's change

        // first divide by 25
            int quarters = (cents / 25);
            int quarters_remainder = (cents % 25);

        // then by 10

            int dimes = (quarters_remainder / 10);
            int dimes_remainder = (quarters_remainder % 10);

        // then by 5

            int nickels = (dimes_remainder / 5);

        // the rest are pennies

            int pennies = (dimes_remainder % 5);

        //now add the coins together

            int coins = (quarters + dimes + nickels + pennies);

    printf("%i", coins);
    printf("\n");

}

