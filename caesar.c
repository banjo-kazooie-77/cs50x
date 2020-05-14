// Takes a plaintext input and outputs ciphertext using Caesar's cipher

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool keyCheck(int argc);
bool digitCheck(string key);
int main(int argc, string argv[])
{

    if ((keyCheck(argc) == true) && (digitCheck(argv[1]) == true))
    {

        // Ask user for input

        string plain = get_string("Plaintext: ");

        // Convert user's key from string to int
        // Formula: c = (p + k) % 26 (see the printf)

        int upperkey = atoi(argv[1]) - 65;
        int lowerkey = atoi(argv[1]) - 97;

        // Add the key to the plaintext to make the cipher
        // Use mod 26 to stay in the alphabet
        // Remap the alphabet??
        // Maintain case with is alpha, is upper, is lower
        // Maintain punctuation


        printf("ciphertext: ");
        for (int i = 0, n = strlen(plain); i < n; i++)
        {
            if (isupper(plain[i]))
            {
                printf("%c", ((plain[i] + upperkey) % 26) + 65);
            }
            else if (islower(plain[i]))
            {
                printf("%c", ((plain[i] + lowerkey) % 26) + 97);
            }
            else
            {
                printf("%c", (plain[i]));
            }
        }

        printf("\n");
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

bool keyCheck(int argc)
{
    return (argc == 2);
}

bool digitCheck(string key)
{
    int sum = 0;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        sum = 1 * isdigit(key[i]);
    }
    return (sum > 0);
}

