#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkrepeated(string str, int keylen);
int letterindex(char p);
int main(void)
{
    string key = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    int keylen = 26;
    if (checkrepeated(key, keylen) > 0 )
    {
        printf("repeated chardetected %i \n",checkrepeated(key, keylen) );

    }
    else{
        string plaintext = get_string("plaintext: ");
        int plaintextlen = strlen(plaintext);
        char keyarr[keylen];
        char letter_plaintext[plaintextlen];
        for (int i = 0; i< strlen(key); i++)
        {
            keyarr[i] = key[i];
            //printf(" %i -:%c \n",i, keyarr[i]);
            //printf("%i\n", letterindex(keyarr[i]));

        }printf("ciphertext: ");
        for (int x = 0;x < plaintextlen;x++)
        {
            letter_plaintext[x] = plaintext[x];
            printf("%c",keyarr[letterindex(letter_plaintext[x])]);
        }printf("\n");

    }

}
int checkrepeated(string str, int keylen)
{
    char c;
    int count = 0;
    for (int i = 0; i <  keylen; i++)
    {
        for (int x = i+1 ; x < keylen; x++)
        {

            if (tolower(str[i]) == str[x] || toupper(str[i]) == str [x])
            {
                count++;
                c = str[i];
                break;
            }
        }
        if (count > 0)
        {
            break;
        }
    }
     return count;
}
int letterindex(char p)
{
    int index = 0;
    if(islower(p) != 0)
    {
        char small = 'a';//97
        int alphastart = (int) small;
        index = ((int) p - alphastart );
    }else if (isupper(p) != 0)
    {
        char upper = 'A';//101
        int alphastart = (int) upper;
        index = ((int) p - alphastart);
    }
    return index;
}