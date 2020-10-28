#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2) // if there!s more or less than 1 code input
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else
    {
        string code = argv[1];
        string output = "";

        for (int k = 0, l = strlen(code); k < l; k++) //checking if anz of the chars in the code is not a letter
        {
            if (code[k] < 'a' || code[k] > 'z')
            {
                if (code[k] < 'A' || code[k] > 'Z')
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
            for (int h = k + 1, f = strlen(code); h < f; h++) //making sure that all the chars occur only once
            {
                if (code[h] == code [k])
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }


        if (strlen(code) == 26) //if the code has the right length
        {
            string input = get_string("plaintext: ");

            printf("ciphertext: ");
            for (int i = 0, n = strlen(input); i < n; i++)
            {
                if (input[i] >= 'a' && input[i] <= 'z') //small letters
                {
                    int ind = (int)input[i];
                    printf("%c", tolower(code[ind - 97]));
                }
                else if (input[i] >= 'A' && input[i] <= 'Z') //capital letters
                {
                    int ind = (int)input[i];
                    printf("%c", toupper(code[ind - 65]));
                }
                else
                {
                    printf("%c", input[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n"); //error message
            return 1;
        }

    }


}