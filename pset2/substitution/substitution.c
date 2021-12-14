#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkrepeated(string str, int keylen);//check for repeated chars
int check_key_isalpha(string str);//checks for alpha
int letterindex(char p);//get alphaptiecal position
int main(int argc, string argv[])
{
    //get key and key len;
    string key = "";
    int keylen = 0 ;
    //check if the user passed the key as command line argument
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        key = argv[1];
        //check all the key is alphapetic chars
        int checkkeyisalpha = check_key_isalpha(key);
        keylen = strlen(key);
        //check for repeated chars in the key
        int dbletters = checkrepeated(key, keylen);
        //check key length
        if (keylen < 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;

        }
        else if (checkkeyisalpha == 0)
        {
            printf("Key must only contain alphapetic characters.\n");
            return 1;
        }
        else if ((keylen == 26) && (checkkeyisalpha != 0) && (dbletters == 0)) // valdiate the key first here
        {
            //get plaintext
            string plaintext = get_string("plaintext: ");
            int plaintextlen = strlen(plaintext);
            char keyarr[keylen];//make an array of key!
            //make an array of plaintext
            char letter_plaintext[plaintextlen];
            for (int i = 0; i < strlen(key); i++)
            {
                //check for case of the key letters
                if (isupper(key[i]) != 0)
                {
                    keyarr[i] = key[i];
                }
                else if (islower(key[i]) != 0)
                {
                    keyarr[i] = toupper(key[i]);
                }
            }
            printf("ciphertext: ");
            for (int x = 0; x < plaintextlen; x++)
            {
                //check for the plain text letter key and encrypt outputing ciphertext
                letter_plaintext[x] = plaintext[x];
                if (isalpha(letter_plaintext[x]) != 0)
                {
                    if (islower(letter_plaintext[x]) != 0)
                    {
                        printf("%c", tolower(keyarr[letterindex(letter_plaintext[x])]));
                    }
                    else if (isupper(letter_plaintext[x]) != 0)
                    {
                        printf("%c", keyarr[letterindex(letter_plaintext[x])]);
                    }
                }
                //check for non alphapetic chars to escape encypting them
                else if (isspace(letter_plaintext[x]) != 0)
                {
                    printf("%c", letter_plaintext[x]);
                }
                else
                {
                    printf("%c", letter_plaintext[x]);
                }
            }
            printf("\n");
        }

        else if ((keylen == 26) && (checkkeyisalpha != 0) && (dbletters != 0))
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
}
int check_key_isalpha(string str)//check if key is alpha
{
    int c = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            ;
        }
        else
        {
            c = 0;
            break;
        }
    }
    return c;
}
int checkrepeated(string str, int keylen)//check for repeated chars !
{
    char c;
    int count = 0;
    for (int i = 0; i <  keylen; i++)
    {
        for (int x = i + 1 ; x < keylen; x++)
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
//get a char's position due to alphapetic schem of ascii
int letterindex(char p)
{
    int index = 0;
    if (islower(p) != 0)//if lower get position
    {
        char small = 'a';//97
        int alphastart = (int) small;
        index = ((int) p - alphastart);
    }
    else if (isupper(p) != 0)//if upper get position right !
    {
        char upper = 'A';//101
        int alphastart = (int) upper;
        index = ((int) p - alphastart);
    }
    return index;
}