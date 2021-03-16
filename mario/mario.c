#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for pyramid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // Create pyramid
    for (int i = 0; i < height; i++) // height
    {
        for (int n = 0; n < (height - 1) - i; n++) // left side
        {
            printf(" ");
        }
        for (int n = 0; n < i + 1; n++) 
        {
            printf("#");  
        }
        
        printf("  "); // middle 
        
        for (int n = 0; n < i + 1; n++) // right side
        {
            printf("#");  
        }
        printf("\n");
    }
}