/* Prints number of coins required in change

by: Dishant Khanna */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change_owed = 0.00;
    int coins = 0, change_reqd;
    do
    {
        change_owed = get_float("Change owed: "); //get change required
    }
    while (change_owed < 0);
    change_reqd = round(change_owed * 100); // round-off to nearest cents
    while (change_reqd >= 25)
    {
        change_reqd = change_reqd - 25;
        coins++;
    }
    while (change_reqd >= 10)
    {
        change_reqd = change_reqd - 10;
        coins++;
    }
    while (change_reqd >= 5)
    {
        change_reqd = change_reqd - 5;
        coins++;
    }
    while (change_reqd >= 1)
    {
        change_reqd = change_reqd - 1;
        coins++;
    }
    printf("%i\n", coins); // print number of coins required
}