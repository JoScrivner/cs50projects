#include <cs50.h>
#include <stdio.h>

int get_right_int(string prompt); //so C recognizes my functions
void hashtag(int h);
void space(int s);


int main(void)
{
    int i = get_right_int("A number between 1 and 8: ");
    for (int j = 1; j <= i; j++)
    {
        space(i - j); //first we need space(s)
        hashtag(j); //then hashtag(s)
        printf("  "); //2 spaces in the middle
        hashtag(j); //then just hashtags
        printf("\n");

    }
    
}


void hashtag(int h) //the hashtag creating function
{
    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
}

void space(int s) //the space creating function
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }
}


int get_right_int(string prompt) //checking if the given number is between 1 and 8
{
    int n;
    do // do it until we get a number between 1 and 8
    {
        n = get_int("Height: %s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
