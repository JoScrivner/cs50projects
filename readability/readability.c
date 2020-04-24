#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letters(string szoveg);
int count_words(string szoveg2);
int count_sentences(string szoveg3);



int main(void)
{

    string text = get_string("Text: ");


    float L = count_letters(text) * (100 / (float)count_words(text)); //calculating L
    float S = count_sentences(text) * (100 / (float)count_words(text)); //calculating S

    //L = (countletters * (100/countwords)) / 100words 380,9

    //S = (countsentences * (100/countwords)) / 100words 14,29


    int index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index >= 1 && index <= 16) //if index is between 1-16
    {
        printf("Grade %i\n", index);

    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }




}

int count_letters(string szoveg) //function to count the number of letters
{
    int length = 0;
    for (int i = 0, n = strlen(szoveg); i < n; i++)
    {
        if (tolower(szoveg[i]) >= 'a' && tolower(szoveg[i] <= 'z')) //if they are actual letters
        {
            length++;
        }
    }
    return length;
}


int count_words(string szoveg2) //function to count the number of words
{
    int length = 0;
    if (strcmp(szoveg2, "") != 0) //if the sting is not empty, that's already 1 word
    {
        length++;
    }
    for (int i = 0, n = strlen(szoveg2); i < n; i++)
    {
        if (szoveg2[i] == ' ') //we count the number of spaces basically
        {
            length++;
        }
    }

    return length;
}



int count_sentences(string szoveg3) //function to count the number of sentences
{
    int length = 0;

    for (int i = 0, n = strlen(szoveg3); i < n; i++)
    {
        if (szoveg3[i] == '.' || szoveg3[i] == '?' || szoveg3[i] == '!')
        {
            if (szoveg3[i + 2] >= 'A'
                && szoveg3[i + 2] <=
                'Z') //counting ., ? and ! only if the 2nd character after them is a capital letter
                //(starting point of a new sentence)
            {
                length++;
            }
        }
    }
    if (szoveg3[strlen(szoveg3) - 1] == '.' || szoveg3[strlen(szoveg3) - 1] == '?'
        || szoveg3[strlen(szoveg3) - 1] == '!') //edding an extra sentence if the last character is the end of a sentence
    {
        length++;
    }

    return length;
}
