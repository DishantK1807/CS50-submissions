/* Implement Caesar cipher

by: Dishant Khanna */

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string args[])
{
    int key, offset, pi, ci;
    if (argc != 2)
    {
        printf("Error!"); // prints error if number of arguments are not equal to 2
        return 1;
    }
    key = atoi(args[1]) % 26;
    string plain_text = get_string("plaintext: "); // get plaintext
    printf("ciphertext: "); //print cipher text
    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (!isalpha(plain_text[i])) //if character is not alphabet
        {
            printf("%c", plain_text[i]);
            continue;
        }
        offset = isupper(plain_text[i]) ? 65 : 97;
        pi = plain_text[i] - offset;
        ci = (pi + key) % 26;
        printf("%c", ci + offset);  // prints ciphertext
    }
    printf("\n");
    return 0;
}