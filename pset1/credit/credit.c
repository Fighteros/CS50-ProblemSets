#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // storing the cc number
    long cc;
    do
    {
        cc = get_long("Number: ");
    }

    // loopiong with no reason
    while (cc < 0);
    long working_cc = cc;
    int sum = 0;
    int count = 0;
    long divisor = 10;
    working_cc /= 10; //first step to get the sum of every other digit, starting with the number’s second-to-last digit
    while (working_cc > 0)
    {
        int last_digit = working_cc % 10;
        int temp_2 = last_digit * 2 ;
        sum += ((temp_2 % 10) + (temp_2 / 10));
        working_cc /= 100;
    }

    //second step getting the digits that weren’t multiplied by 2 in the last step
    working_cc = cc;
    int summ = 0;
    while (working_cc > 0)
    {
        int last_digit = working_cc % 10 ;
        summ += last_digit ;
        working_cc /= 100;
    }
    int total_sum = sum + summ;// get total sum
    //get digits lengths
    working_cc = cc;
    while (working_cc != 0)
    {
        working_cc /= 10 ;
        count++;
    }
    for (int x = 0; x < count - 2; x++)
    {
        divisor *= 10;
    }

    // calcualting some leftDigit!
    int lftfdigit = cc / divisor;
    int lfttwodigits = cc / (divisor / 10);
    // checks the issuer of the card
    if (total_sum % 10 == 0)
    {
        if (lftfdigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if (count == 15 && (lfttwodigits == 34 || lfttwodigits == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (lfttwodigits > 50 && lfttwodigits < 56))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}