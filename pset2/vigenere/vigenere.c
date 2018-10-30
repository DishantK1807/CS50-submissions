/* Implement Vigenere cipher

by: Dishant Khanna */

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool is_valid_key(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, string argv[])
{
    int offset, pi, ci, kj, key_length;
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Error! \n"); // prints error if number of arguments are not equal to 2
        return 1;
    }
    string key = argv[1];
    string plain_text = get_string("plaintext: "); // get plaintext
    key_length = strlen(argv[1]);
    printf("ciphertext: "); //print cipher text
    for (int i = 0, j = 0; i < strlen(plain_text);i++)
    {
        if (!isalpha(plain_text[i])) //if character is not alphabet
        {
            printf("%c", plain_text[i]);
            continue;
        }
        offset = isupper(plain_text[i]) ? 65 : 97;
        pi = plain_text[i] - offset;
        kj = toupper(key[j % key_length]) - 65;
        ci = (pi + kj) % 26;
        printf("%c", ci + offset);  // prints ciphertext
        j++;
    }
    printf("\n");
    return 0;
}