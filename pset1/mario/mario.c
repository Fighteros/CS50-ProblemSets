#include <stdio.h>
#include <cs50.h>

int getposinum(void);
int main(void)// main method of my program
{
    int h = getposinum(); //getting our height from the method which returns a positive number from 1-8
    for (int i = 0; i < h; i++)
    {
        string spaces = " ";
        string shape = "#";
        for (int j = 0 ; j < h - i - 1; j++) //print spaces to each line before the #
        {
            printf("%s", spaces);
        }
        for (int x = 0; x <= i; x++) //print # in each line due to number of line  -left side of the shape-
        {
            printf("%s", shape);

        }
        for (int z = 0; z <= 1; z++) //print the gap to each line
        {
            printf("%s", spaces);
        }
        for (int y = 0 ; y <= i; y++)//print right side of the shape
        {
            printf("%s", shape);
        }
        printf("\n");
    }
}
//get postive num
int getposinum(void)
{
    //ask for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}