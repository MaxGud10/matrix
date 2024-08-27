#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // количество строк
#define COLS 4 // количество столбцов

// struct TriangleMatrix {int* data; int size;};
// SIZE - константа

/*a(n) = a(n+1) - d
S(n) = ((a(1) + a(n)))*n / 2
*/
// setTriangleMatrixRandom(TriangleMatrix* matrix);
// printTriangleMatrix(const TriangleMatrix* matrix);


struct TriangleMatrix 
{
    int* data; 
    int size; // размер матрицы
};

int  triangle_random(int size_y);
void rectangle_random(int col, int size_y);
int  index_matrix ();
int get_element(int data[][COLS], int row, int col);

int main(void) 
{
    int col, row;

    srand(time(NULL));

    int number = 1;
    int size_x = 5;
    int size_y = 4;
    
    //                              0   1   2   3
    int data[ROWS][COLS] =  /*0*/ {{11, 12, 13, 14}, 
                            /*1*/  {21, 22, 23, 24},
                            /*2*/  {31, 32, 33, 34}, 
                            /*3*/  {41, 42, 43, 44},
                            /*4*/  {51, 52, 53, 54}};

                                  
    triangle_random(size_y);

    printf("\n");

    rectangle_random(size_x, size_y);

    printf("Enter the index you would like to display:\n");
    scanf("%d %d", &row, &col);

    if (row < 0     || 
        row >= ROWS || 
        col < 0     ||
        col >= COLS)
    {
        printf("Error: Invalid indexes. Please enter values ​​between 0 and %d for rows and between 0 and %d for columns.\n", ROWS - 1, COLS - 1);
    }
    else 
    {
        printf("matrix element [%d][%d] = %d\n", col, row, get_element(data, row, col));
    }

    return 0;
}

int get_element(int data[][COLS], int row, int col) 
{
    return data[row][col];
}

int triangle_random(int size_y)
{
    for (int y = 0; y < size_y; y++) 
    {
        for (int x = 0; x <= y ; x++) 
        {   
            srand(time(NULL));
            printf("|%d| ", rand());
        }
        printf("\n");
    }
    return 0;
}

void rectangle_random(int size_x, int size_y)
{
    for (int y = 0; y < size_x; y++)
    {
        for (int x = 0; x <= size_y; x++)
        {
            //srand(time(NULL));
            printf("|%d| ",  rand()%10);
        }
        printf("\n");
    }
}
