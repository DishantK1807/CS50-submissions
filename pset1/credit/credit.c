/* Check credit card Validity and Authencity

by: Dishant Khanna */

#include <stdio.h>
#include <cs50.h>

int main()
{
    long long number;
    int nums[20], count = 0, num, i = 0, checksum = 0, variable, varsum;
    do
    {
        number = get_long_long("Number: "); // get card number
    }
    while (number < 0);
    while (number > 0) // convert to array
    {
        num = number % 10;
        nums[i] = num;
        number = number / 10;
        count++;
        i++;
    }
    for (i = 0; i < count; i++)
    {
        if (i == 0 || (i % 2 == 0 && i > 0))
        {
            checksum = checksum + nums[i];
        }
        else if (i > 0 && i % 2 != 0)
        {
            variable = 2 * nums[i];
            if (variable / 10 == 0)
            {
                varsum = variable;
            }
            else
            {
                varsum = (variable / 10) + (variable % 10);
            }
            checksum = checksum + varsum; //calc checksum
        }
    }
    if (checksum % 10 == 0) //if valid check card type
    {
        if (nums[count - 1] == 3 && (nums[count - 2] == 4 || nums[count - 2] == 7) && count == 15)
        {
            printf("AMEX\n"); // if credit card is American Express
        }
        else if (nums[count - 1] == 5 && (nums[count - 2] == 1 || nums[count - 2] == 2 || nums[count - 2] == 3 || nums[count - 2] == 4
                                          || nums[count - 2] == 5) && count == 16)
        {
            printf("MASTERCARD\n"); // if credit card is MasterCard
        }
        else if (nums[count - 1] == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n"); // if credit card is Visa
        }
    }
    else
    {
        printf("INVALID\n"); // if card is invalid
    }

}