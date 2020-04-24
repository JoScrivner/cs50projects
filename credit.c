#include <cs50.h>
#include <stdio.h>
#include <math.h>

long checkiflong(string prompt);
long luhn(long bev);


int main(void)
{
    long bevitel = checkiflong(""); //first we check if the given number is long type
    long fajtasorszam = luhn(bevitel); // checking if the number is valid or not and what type of card
    if (fajtasorszam == 1)
    {
        printf("AMEX\n"); //valid AMEX number
    }
    else if (fajtasorszam == 2)
    {
        printf("MASTERCARD\n"); //valid MASTERCARD
    }
    else if (fajtasorszam == 3)
    {
        printf("VISA\n"); // valid VISA
    }
    else
    {
        printf("INVALID\n"); //not valid
    }

}

long checkiflong(string prompt) //checking if the given number is long type
{
    long n;
    do // do it until we get a number is long
    {
        n = get_long("Number: %s", prompt);
    }
    while (n < 0);
    return n;
}

long luhn(long bev) //checking validity with Luhn's algorithm and then the type of the card
{
    long len = 0;
    long paratlanossz = 0; //odd numbers
    long parosduplaossz = 0; //even numbers, times 2
    long totalhossz = 0; //total
    long kesobb = bev; // I want to use the original input number later

    while (bev != 0)// do it until the number is 0
    {
        paratlanossz = paratlanossz + (bev % 10);
        bev = (bev - (bev % 10)) / 10;  //taking away digits from the end
        len++; //adding to length

        if (bev != 0 && ((bev % 10) * 2 < 10)) //if times 2 is a 1 digit bumber
        {
            parosduplaossz = parosduplaossz + ((bev % 10) * 2); //2, 14, 22
            bev = (bev - (bev % 10)) / 10; //taking away digits from the end

            len++;

        }
        else if ((bev != 0)) //is times 2 is a 2 digit number
        {
        
            long egyes = (((bev % 10) * 2) % 10);
            long tizes = (((bev % 10) * 2) - egyes) / 10;
            
            parosduplaossz = parosduplaossz + (egyes + tizes);
            bev = (bev - (bev % 10)) / 10;  //taking away digits from the end

            len++;
        }
        
    }
    totalhossz = paratlanossz + parosduplaossz; //the result of Luhn's algorithm

    bool isvalid;
    long brand  = 0;
    if (totalhossz % 10 == 0) //checking validity based on Luhn's algorithm
    {
        isvalid = true;
    }
    else
    {
        isvalid = false;
    }

    if (isvalid == true) //checking validity based on first 1 or 2 digits
    {
        while (kesobb > 99) //getting the first 2 digits
        {
            kesobb = (kesobb - (kesobb % 10)) / 10;
        }
        if (len == 15) //15 digits
        {
            if (kesobb == 37 || kesobb == 34)
            {
                brand = 1; //AMEX
            }
            else
            {
                brand = 4; //invalid
            }
        }
        else if (kesobb == 51 || kesobb == 52 || kesobb == 53 || kesobb == 54 || kesobb == 55)
        {
            if (len == 16)
            {
                brand = 2; //MasterCard
            }
            else
            {
                brand = 4; //invalid
            }
        }
        else if (len == 13 || len == 16)
        {
            kesobb = (kesobb - (kesobb % 10)) / 10;
            if (kesobb == 4)
            {
                brand = 3; // Visa
            }
            else
            {
                brand = 4; //invalid
            }
        }
        else
        {
            brand = 4; //invalid
        }
    }
    else
    {
        brand = 4; //invalid
    }
    

    return brand;
}
