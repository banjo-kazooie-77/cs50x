#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

//draw a super mario staircase out of hash signs #

int main (void)
{

    //ask user for number n for height of staircase
    int n;
    do
    {
    n = get_int("Enter number of stairs to display: ");
    }
    while ( n < 1 || n > 8);

    //make the spaces and hashes
    for (int i = 0; i < n; i++)
    {
        //spaces
        for (int k = n - 1; k > i; k--)
        {
            printf(" ");
        }
        //hashes
        for (int j = 0; j <= i; j++)
        {
        printf("#");
        }
        printf("\n");
    }




}