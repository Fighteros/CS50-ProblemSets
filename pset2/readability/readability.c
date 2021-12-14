#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int lettercount(string str, int strlens);
int count_words(string str, int sl, char c);
int count_sent(string str, int sl);
char Endswith(string str, int sl);

int main(void)
{
    // take input from the user
    string text = get_string("Text: ");
    //get string length
    int strlength = strlen(text);
    int letters = lettercount(text, strlength);
    int words =  count_words(text, strlength, Endswith(text, strlength));
    int sents = count_sent(text, strlength);
    //get L
    double L = (double) letters / words * 100 ;
    //get S
    double s = (double) sents /  words * 100;
    // calculate the index of Coleman-Liau index = 0.0588 * l - 0.296 * s - 15.8
    double index = (0.0588 * L) - (0.296 * s) - 15.8;
    //print Grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %.0f\n", round(index));
    }
}
//count letters
int lettercount(string str, int sl)
{
    int letters = 0;
    for (int i = 0; i < sl ; i++)
    {
        //check if it is an A - Z letter or a - z
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            letters++;
        }
    }
    return letters;
}
//check last character in the text to determine words initial condition
char Endswith(string str, int sl)
{
    char c;
    for (int x = 0; x <= sl ; x++)
    {
        if (sl - x == 1)
        {
            c = str[x];
        }
    }
    return c;
}
//count words
int count_words(string str, int sl, char c)
{
    int words = 1;
    if (isspace(c) != 0)
    {
        words = 0;
    }

    int x = 0;
    while (x < sl)
    {
        if ((isalpha(str[x])) || (str[x] >= 33 && str[x] <= 47) || (str[x] >= 58 && str[x] <= 63) || (str[x] >= 91 && str[x] <= 95)
            || (str[x] >= 123 && str[x] <= 126))
        {
            while (x + 1 < sl)
            {
                if (isspace(str[x + 1]))
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
//count sentences
int count_sent(string str, int sl)
{
    int sent = 0;
    for (int x = 0 ; x < sl ; x++)
    {

        if (str[x] == 33 || str[x] == 46 || str[x] == 63)
        {
            sent++;
        }
    }
    return sent;

}