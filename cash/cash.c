#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Get amount of change owed
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0.00);
   
    // Count minimum number of coins owed
    int cents = round(change * 100); // convert dollars into cents
    int count = 0;
    while (cents > 0)
    {
        if ((cents - 25) >= 0)
        {
           cents -= 25;
        } 
        else if ((cents - 10) >= 0)
        {
           cents -= 10;
        }
        else if ((cents - 5) >= 0)
        {
           cents -= 5;
        }
        else 
        {
           cents -= 1;
        }
        count++;
    }
    
    // Print minimum number of coins owed
    printf("%i\n", count);
}