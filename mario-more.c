#include <cs50.h>
#include <stdio.h>

// Problem set (week 1) on Mario (more comfortable) from Harvard's CS50 class.
// This code creates pyramids in C using hashes (#) for bricks.

int get_height(void);
void build_pyramid(int h);
int main(void)
{
    // Prompt user for imput
    int h = get_height();

    // print pyramids
    build_pyramid(h);

}

int get_height(void)
{
    int h;
    do
    {
        h = get_int("Enter height of pyramid here: ");
    }
    // Make sure that the input height(h) is within the range 1-8
    while (h < 1 || h > 8);
    return h;

}

void build_pyramid(int h)
{
    for (int row = 0; row < h; row++)
    {
        for (int k = h - 1; k > row; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < row + 1; j++)
        {

            printf("#");
        }


        for (int l = 0; l < row + 1; l++)
        {
            if (l == 0)
            {
                // Creates the white space between pyramids
                printf("  #");
            }

            // Creates hashes after pyramids
            else
            {
                printf("#");
            }

        }

        printf("\n");
    }
}
