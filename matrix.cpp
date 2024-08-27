#include <stdio.h>

int ror (int size_y, int number);

int main(void) 
{
    int number = 1;
    int size_y = 4;

    /*int data[5][4] ={{11, 12, 13, 14},
                     {21, 22, 23, 24},
                     {31, 32, 33, 34},
                     {41, 42, 43, 44},
                     {51, 52, 53, 54}};*/

    for (int i = 0; i < size_y; i++) 
    {
        for (int j = 0; j <= i ; j++) 
        {   
            printf("|%d| ", number);
            number++;
        }
        printf("\n"); 
    }

    return 0;
}