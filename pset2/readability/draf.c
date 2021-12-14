#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int checkword(string str, int sl , char  c);
char Endswith(string str, int sl);

int main(void)
{
    string str= get_string("text: ");
    int strln = strlen(str);
    printf("%i word(s)\n", checkword(str, strln , Endswith(str, strln)));


}
char Endswith(string str, int sl)
{
    char c;
    for (int x=0; x<= sl ; x++)
    {
        if (sl - x == 1)
        {
           c = str[x];
        }
    }
    return c;
}

int checkword(string str, int sl , char c)
{
     int words=1;
    if (isspace(c) != 0)
    {
        words = 0;
    }

    int x=0;
    while (x < sl)
    {
        if((isalpha(str[x])) || (str[x] >= 33 && str[x] <= 47) || (str[x] >= 58 && str[x] <= 63) || (str[x] >= 91 && str[x] <= 95) || (str[x] >= 123&& str[x] <= 126))
        {
            while( x+1 < sl)
            {
                if (isspace(str[x+1]))
                {
                    words++;
                    break;
                }
                else
                {
                    break;
                }

            }
        }


        x++;
    }
    return words;
}