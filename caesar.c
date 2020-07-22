#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encode(int key, string p, int c []);

int main(int argc, string argv[])
{
    // Check if there are 2 arguments inside of argv if so run rest of the code if not abort
    if (argc == 2)
    {
        // Go over all the characters in argv and check if they are all positive ints
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // Get the key and convert it to an int
        int key = atoi(argv[1]);

        // Prompt user for an input and asign it to plaintext
        string plaintext = get_string("plaintext: ");
        // Declare a var for the cipher text
        int ciphertext[strlen(plaintext)];
        // Run the encoding
        encode(key, plaintext, ciphertext);

        // Output the ciphertext
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", ciphertext[i]);
        }

        // end the line and return 0
        printf("\n");
        return 0;

    }
    else
    {
        // if all is false return 1 and print fail text
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Encoding function
void encode(int key, string p, int c [])
{
    // loop through all the characters of the plaintext
    for (int i = 0; i < strlen(p); i++)
    {
        // check if the char is a lowercase value
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            // Calculation for cipher
            c[i] = ((((p[i] - 97) + key) % 26) + 97);
        }
        // check if the char is a uppercase value
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            // Calculation for cipher
            c[i] = ((((p[i] - 65) + key) % 26) + 65);
        }
        // else it gets printed uncoded
        else
        {
            c[i] = p[i];
        }
    }
}
