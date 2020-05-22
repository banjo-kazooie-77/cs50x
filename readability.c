//Calculates the reading grade level of a user-input text

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int gradeChecker(int l, int w, int s);
int sentenceCounter(string s);
int wordCounter(string s);
int funcLetterCounter(string s);
int main(void)
{

    /*Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8*/
    // L = avg number of letters per 100 words
    // S = avg number of sentences per 100 words

    //promt user for text
    string text = get_string("Text: ");
    //printf("Total String Length: %lu\n", strlen(text));

    int letters = funcLetterCounter(text);
    //printf("Letters in string: %d\n", letters);

    int words = wordCounter(text);
    //printf("Words in string: %d\n", words);

    int sentences = sentenceCounter(text);
    //printf("Sentences in string: %d\n", sentences);

    int gradeLevel = gradeChecker(letters, words, sentences);

    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }

}

int funcLetterCounter(string s)
{
    int sum = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            sum++;
        }
    }

    return sum;
}

int wordCounter(string s)
{

    int spaceSum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            spaceSum++;
        }
    }

    return spaceSum + 1;

}

int sentenceCounter(string s)
{
    int sentenceSum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '?' || s[i] == '.' || s[i] == '!')
        {
            sentenceSum++;
        }
    }
    return sentenceSum;

}

/*Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8*/
// L = avg number of letters per 100 words
// S = avg number of sentences per 100 words

int gradeChecker(int l, int w, int s)
{
    int index = round(0.0588 * (l * 100 / w) - 0.296 * (s * 100 / w) - 15.8);
    return index;

}
