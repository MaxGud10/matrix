#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "check_input.h"

int** memory_for_matrix(int rows, int cols);
int input_matrix( int** matrix1, int rows, int cols);
//int creat_matrix2(int rows2, int cols2, int** matrix2);
int product_matrix(int rows1, int cols2, int rows2, int cols1, int** matrix1, int** matrix2, int** result);
int memory_clean(int** matrix, int rows);
//int memory_clean(int rows1, int** matrix1, int** matrix2, int** result);

int main(void)
{
    int rows1 = 0; // количество строк 
    int cols1 = 0; // количество столбцов

    int rows2 = 0;
    int cols2 = 0;

    check_input1(&rows1, &cols1);
    check_input2(&rows2, &cols2);

    if (cols1 != rows2) // TODO: засунуть в функцию умножения 
    {
        printf("Error: Matrices dimensions must match for addition.\n");
        return 1; 
    } // не засунул в функцию, потому что она слишком поздно проверяла бы параментры
    // пользователь сначало вводил бы индексы матриц, а только потом бы проходила проверка  

    int** matrix1 = memory_for_matrix(rows1, cols1);
    int** matrix2 = memory_for_matrix(rows2, cols2);

    input_matrix(matrix1, rows1, cols1);
    input_matrix(matrix2, rows2, cols2); // правильно ли. проверить объявление функции 
    
    int** result = memory_for_matrix(rows1, cols2);

    product_matrix(rows1, cols2, rows2, cols1, matrix1, matrix2, result);

    //memory_clean(rows1, matrix1, matrix2, result); // TODO надо разделить очистку памяти на матрицы по отдельности 
    memory_clean(matrix1, rows1);
    memory_clean(matrix2, rows2);
    memory_clean(result, rows1);

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
        matrix[i] = (int*)calloc(cols, sizeof(int));
        assert(matrix[i] != NULL);
    }

    return matrix;
}

int input_matrix( int** matrix1, int rows, int cols)
{

    printf("Enter the elements of the first matrix:\n");

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

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

int product_matrix(int rows1, int cols2, int rows2, int cols1, int** matrix1, int** matrix2, int** result)
{
    
    printf("Your matrix: \n");

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++) 
        {
            result[i][j] = 0; // Инициализируем элемент результирующей матрицы нулем
            for (int k = 0; k < cols1; k++) // Суммируем произведения элементов из строки первой матрицы и столбца второй
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
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