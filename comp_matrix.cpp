#include <stdio.h>
#include <TXLib.h>
#include <stdlib.h>
#include <assert.h>

#include "check_input.h"

int** memory_for_matrix(int rows, int cols);
int input_matrix( int** matrix1, int rows, int cols);
int product_matrix(int** result, int** matrix1, int** matrix2, int rows1, int cols1, int cols2);
int printf_product(int** result, int rows, int cols);
int memory_clean(int** matrix, int rows);

const int ROWS1 = 2;
const int COLS1 = 3;
const int ROWS2 = 3;
const int COLS2 = 2;

int main(void)
{
    int rows1 = check_input("Enter how many rows will be in your matrix1");
    int cols1 = check_input("Enter how many cols will be in your matrix1");
    int rows2 = check_input("Enter how many rows will be in your matrix2");
    int cols2 = check_input("Enter how many cols will be in your matrix2");

    if (cols1 != rows2) 
    {
        printf("Error: Matrices dimensions must match for addition. GO AWAY AND READ MATH BOOKS!!!\n");
        return 1; 
    }  // не засунул в функцию, потому что она слишком поздно проверяла бы параметры
    // пользователь сначала вводил бы индексы матриц, а только потом бы проходила проверка  

    int** matrix1 = memory_for_matrix(rows1, cols1);
    int** matrix2 = memory_for_matrix(rows2, cols2);

    input_matrix(matrix1, rows1, cols1);
    input_matrix(matrix2, rows2, cols2); 
    
    int** result = memory_for_matrix(rows1, cols2);

    product_matrix(result, matrix1, matrix2, rows1, cols1, cols2);

    memory_clean(matrix1, rows1);
    memory_clean(matrix2, rows2);
    memory_clean(result,  rows1);

    return 0;
}

int** memory_for_matrix(int rows, int cols)
{
    int** matrix = (int**)calloc(rows, sizeof(int*));
    assert(matrix != NULL);
    /*if (matrix == NULL) 
    {
        printf("Failed to allocate memory for rows");
        return 1;
    }*/
    
    for (int i = 0; i < rows; ++i) 
    {
        assert(0 <= i && i < rows);
        matrix[i] = (int*)calloc(cols, sizeof(int));
        assert(matrix[i] != NULL);
    }

    return matrix;
}

int input_matrix( int** matrix, int rows, int cols)
{
    printf("Enter the elements of the first matrix:\n");

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            assert(0 <= i && i < rows);
            assert(0 <= j && j < cols);
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf_product(matrix, rows, cols);

    return 0;
}

/*int creat_matrix2(int rows2, int cols2, int** matrix2)
{
    printf("Enter the elements of the second matrix:\n");

    for (int i = 0; i < rows2; ++i) 
    {
        for (int j = 0; j < cols2; ++j) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    return 0;
}*/

int product_matrix(int** result, int** matrix1, int** matrix2, int rows1, int cols1, int cols2)
{
    printf("Your matrix: \n");

    for (int i = 0; i < cols1; i++) // row
    {
        for (int j = 0; j < cols2; j++) // cols
        {
            printf("i = %d and j = %d\n", i, j );
            assert(0 <= i && i < ROWS1);
            assert(0 <= j && j < COLS2);

            result[i][j] = 0; // присваиваем элемент результирующей матрицы нулем
            for (int k = 0; k < cols1; k++) // Суммируем произведения элементов из строки первой матрицы и столбца второй
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf_product(result, rows1, cols2);
    return 0;
} 

int printf_product(int** result, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            assert(0 <= i && i < rows);
            assert(0 <= j && j < cols);
            printf("%d ", result[i][j]); 
        }
        printf("\n");
    }
    return 0;
} 


int memory_clean(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        assert(0 <= i && i < rows);
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}



/*int memory_clean(int rows1, int** matrix1, int** matrix2, int** result)
{
    for (int i = 0; i < rows1; ++i)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}*/