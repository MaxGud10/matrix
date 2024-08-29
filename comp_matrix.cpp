#include <stdio.h>
#include <stdlib.h>

int creat_matrix1(int rows1, int cols1, int** matrix1);
int creat_matrix2(int rows2, int cols2, int** matrix2);
int product_matrix(int rows1, int cols2, int rows2, int cols1, int** matrix1, int** matrix2, int** result);
int memory_clean(int rows1, int** matrix1, int** matrix2, int** result);

int main(void)
{
    int rows1 = 0; // количество строк 
    int cols1 = 0; // количество столбцов
    printf("Enter how many rows1 and columns will be in your matrix1\n");
    scanf("%d %d", &rows1, &cols1);

    int rows2 = 0;
    int cols2 = 0;
    printf("Enter how many rows1 and columns will be in your matrix2\n");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2)
    {
        printf("Error: Matrices dimensions must match for addition.\n");
        return 1;
    }

    int** matrix1 = (int**)calloc(rows1, sizeof(int*));
    for (int i = 0; i < rows1; ++i) 
    {
        matrix1[i] = (int*)calloc(cols1, sizeof(int));
    }

    int** matrix2 = (int**)calloc(rows2, sizeof(int*));
    for (int i = 0; i < rows2; ++i) 
    {
        matrix2[i] = (int*)calloc(cols2, sizeof(int));
    }

    creat_matrix1(rows1, cols1, matrix1);

    creat_matrix2(rows2, cols2, matrix2);
    
    int** result = (int**)calloc(rows1, sizeof(int*));
    for (int i = 0; i < rows1; ++i) 
    {
        result[i] = (int*)calloc(cols2, sizeof(int));
    }
    

    product_matrix(rows1, cols2, rows2, cols1, matrix1, matrix2, result);

    memory_clean(rows1, matrix1, matrix2, result);

    return 0;
}

int creat_matrix1(int rows1, int cols1, int** matrix1)
{
    printf("Enter the elements of the first matrix:\n");

    for (int i = 0; i < rows1; ++i) 
    {
        for (int j = 0; j < cols1; ++j) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    return 0;
}

int creat_matrix2(int rows2, int cols2, int** matrix2)
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
}

int product_matrix(int rows1, int cols2, int rows2, int cols1, int** matrix1, int** matrix2, int** result)
{
    printf("Your matrix: \n");

    for (int i = 0; i < rows1; i++) // Итерируем по каждой строке первой матрицы
    {
        for (int j = 0; j < cols2; j++) // Итерируем по каждому столбцу второй матрицы
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

int memory_clean(int rows1, int** matrix1, int** matrix2, int** result)
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
}