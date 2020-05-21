#include <stdio.h>
#include <cs50.h>


long numberRequest();
bool cardValidityChecker(long ccn);
int cardLength(long ccn);
bool checkSum(long ccn);
void printCardCompany(long ccn);

int main(void)
{
    long card_number = numberRequest();

    if (cardValidityChecker(card_number) == true)
    {
        printCardCompany(card_number);
    }
    else
    {
        printf("INVALID\n");
    }

}

//and now the functions

long numberRequest(long n)
{
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);
    return n;
}

bool cardValidityChecker(long ccn)  //checks length of card number and if it passes checksum
{
    int length = cardLength(ccn);
    return ((length == 13 || length == 15 || length == 16) && (checkSum(ccn)));

}

int cardLength(long ccn)
{
    int length;
    for (length = 0; ccn != 0; length++, ccn /= 10);
    return length;
}

bool checkSum(long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
        if (i % 2 == 0)
        {
            sum += (ccn % 10);
        }
        else
        {

            int oddDigit = (2 * (ccn % 10));
            sum += (oddDigit % 10) + (oddDigit / 10);
        }
    return (sum % 10 == 0);
}

void printCardCompany(long ccn)
{
    if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }

    else if (ccn >= 51e14 && ccn < 57e14)
    {
        printf("MASTERCARD\n");
    }

    else if ((ccn >= 34e13 && ccn < 35e13) || ( ccn >= 37e13 && ccn < 38e13 ))
    {
        printf("AMEX\n");
    }

    else
    {
        printf("INVALID\n");
    }
}