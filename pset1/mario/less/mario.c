/* Prints Mario Less hashes

by: Dishant Khanna */

#include<stdio.h>

int main(void)
{
    int line, spaces, height, hashes;
    do
    {
        printf("Height: "); // Get hieght from user
        scanf("%i", &height);
    }
    while (height < 0 || height > 23); // get height between 0 and 23
    for (line = 0; line < height; line++)
    {
        for (spaces = 0; spaces < height - line - 1; spaces++)
        {
            printf(" "); // print spaces
        }
        for (hashes = line + 1; hashes >= 0; hashes--)
        {
            printf("#"); //print hashes
        }
        printf("\n"); // goto nextline
    }
}