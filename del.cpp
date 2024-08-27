#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct TriangleMatrix {int* data; int size;};
// SIZE - константа
// setTriangleMatrixRandom(TriangleMatrix* matrix);
// printTriangleMatrix(const TriangleMatrix* matrix);

/*a(n) = a(n+1) - d
S(n) = ((a(1) + a(n)))*n / 2
*/

struct TriangleMatrix 
{
    int* data; 
    int size; // размер матрицы
};

int set_triangle_matrix_random(TriangleMatrix* matrix);
void print_triangle_matrix(const TriangleMatrix* matrix);

int main(void) 
{

    int size;
    printf("Enter the size of the triangular matrix:\n");
    scanf("%d", &size); 

     if (size <= 0) 
    {
        printf("\nSize must be greater than 0.\n");
        return 1;
    }

    struct TriangleMatrix matrix;
    matrix.size = size;
    matrix.data = (int*)malloc((size * (size + 1)) / 2 * sizeof(int));

    if (matrix.data == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    srand(time(NULL));
    set_triangle_matrix_random(&matrix); // Заполнение матрицы случайными числами
    print_triangle_matrix(&matrix); // Печать треугольной матрицы
}

int set_triangle_matrix_random(TriangleMatrix* matrix) 
{
    int index = 0; 
    for (int row = 0; row < matrix->size; row++) 
    {
        for (int col = 0; col <= row; col++) 
        {
            matrix->data[index++] = rand() % 10; 
        }
    }
    return 0; 
}

void print_triangle_matrix(const TriangleMatrix* matrix) 
{
    int index = 0; 
    for (int row = 0; row < matrix->size; row++) 
    {
        for (int col = 0; col <= row; col++) 
        {
            printf("%2d ", matrix->data[index++]); 
        }
        printf("\n");
    }
}
