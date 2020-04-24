#include <cs50.h>
#include <stdio.h>
#include <math.h>


float get_pos_float(string prompt);


int main(void)
{
    int coins = 0;
    float dollars = get_pos_float("");

    int cents = round(dollars * 100); //from dollars to cents

    int quarter = cents / 25;
    //coins=coins+quarter;
    int rest = cents % 25;

    int dime = rest / 10;
    //coins=coins+dime;
    int rest2 = rest % 10;

    int nickel = rest2 / 5;
    int rest3 = rest2 % 5;
    coins = coins + (nickel + quarter + dime +  rest3);


    printf("%i\n", coins);

}




float get_pos_float(string prompt) //checking if the given number is non-negative
{
    float n;
    do // do it until we get a number that's not smaller than 0
    {
        n = get_float("Change owed: %s", prompt);
    }
    while (n < 0);
    return n;
}
