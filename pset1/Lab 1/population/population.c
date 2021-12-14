#include <cs50.h>
#include <stdio.h>

// to make main at the top
// added headers of methods
void getDetails(string msg, int *num);


int main(void)
{
    // get starting size
    int startingSize;
    do
    {
        getDetails("Start size: ", &startingSize);
        // printf("this is the starting size, %d\n", startingSize);
    }
    while (startingSize < 9);

    // Prompt for end size
    int endSize;
    do
    {
        getDetails("End Size: ", &endSize);
        // printf("this is the ending size, %d\n", endSize);
    }
    while (endSize < startingSize);


    //Calculate number of years until we reach threshold
    int numberOfYears = 0;
    do
    {
        if (startingSize == endSize)
        {
            break;
        }
        else
        {
            startingSize = startingSize + ((startingSize / 3) - (startingSize / 4));
            numberOfYears++;
        }
    }
    while (startingSize <= endSize);


    // TODO: Print number of years
    printf("Years: %d\n", numberOfYears);
}


// propmt for details and save it to main
void getDetails(string msg, int *num)
{
    // get user input
    int userInput = get_int("%s", msg);
    // put the value of user input into the value of num
    *num = userInput;

}

