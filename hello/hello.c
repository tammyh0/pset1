#include <stdio.h>

#include <cs50.h>

int main(void)
{
    // Asks user for their name to spit out a greeting
    string name = get_string("Oy! What's your name?\n");
    printf("hello, %s\n", name);
}