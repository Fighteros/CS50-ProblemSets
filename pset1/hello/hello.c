#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user's name
    string name = get_string("What's your name? \n");
    printf("hello, %s\n", name);
}