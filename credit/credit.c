#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Get credit card number
    long num = get_long("Number: "); 

    // Calculate checksum
    bool is_underlined = false; 
    long underlined_sum = 0; 
    long non_underlined_sum = 0; 
    long remaining_num = num; // Current number sequence

    // Extract each digit starting from the end
    while (remaining_num > 0) // Has digits left
    {
        long last_digit = remaining_num % 10; 
        // Adds digits that aren't underlined
        if (is_underlined == false) 
        {
            non_underlined_sum += last_digit;
            is_underlined = true;
        }
        else 
        {
            // Adds digits that are underlined
            long product = (last_digit * 2); 
            // Adds products digits
            while (product > 9)
            {
                long last_digit2 = product % 10; //2
                underlined_sum += last_digit2;
                product = (long)floor(product / 10); //1
            }
            underlined_sum += product; // 
            is_underlined = false;
        }
        // Remove last digit and update remaining number sequence
        remaining_num = (long)floor(remaining_num / 10);
    }
    
    // Checks if total's last digit is 0
    if ((underlined_sum + non_underlined_sum) % 10 == 0) // Card is valid
    {
        // Calculate card length
        int length = 0;
        remaining_num = num;
        while (remaining_num > 0)
        {
            length++;
            remaining_num = (long)floor(remaining_num / 10);
        }
        // Check American Express
        if (length == 15)
        {
            remaining_num = num;
            for (int i = 0; i < length - 2; i++)
            {
                remaining_num = (long)floor(remaining_num / 10);
            }
            if (remaining_num == 34 || remaining_num == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Check Visa
        else if (length == 13)
        {
            remaining_num = num;
            for (int i = 0; i < length - 1; i++)
            {
                remaining_num = (long)floor(remaining_num / 10);
            }
            if (remaining_num == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Either Visa or MasterCard
        else if (length == 16)
        {
            // Get first digit
            remaining_num = num;
            for (int i = 0; i < length - 1; i++)
            {
                remaining_num = (long)floor(remaining_num / 10);
            }
            // Check Visa
            if (remaining_num == 4)
            {
                printf("VISA\n"); 
            }
            else
            {
                // Get first two digits
                remaining_num = num;
                for (int i = 0; i < length - 2; i++)
                {
                    remaining_num = (long)floor(remaining_num / 10);
                }
                // Check MasterCard
                if (remaining_num > 50 && remaining_num < 56)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
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