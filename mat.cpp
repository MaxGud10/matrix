#include <stdio.h>

void print_matrix(int data[][4], int size_x, int size_y) 
{
    for (int i = 0; i < size_x; i++) 
    {
        for (int j = 0; j < size_y; j++) 
        {
            printf("data[%d][%d] = %d ", i, j, data[i][j]);
        }
        printf("\n"); 
    }
}

int main(void) 
{
    int data[5][4] ={{11, 12, 13, 14},
                     {21, 22, 23, 24},
                     {31, 32, 33, 34},
                     {41, 42, 43, 44},
                     {51, 52, 53, 54}};


    print_matrix(data, 5, 4);

    return 0;
}

