/* Functions to handle matrices */

#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"


/**
 * @brief Allocates storate for a matrix with the given dimensions
 *
 * @param rows Number of rows (> 0)
 * @param cols Number of columns (> 0)
 * @return Pointer to the allocated Matrix structure
 */
Matrix* matrix_create(int rows, int cols)
{
    assert(rows > 0 && cols > 0);

    Matrix* mat;

    if ((mat = malloc(sizeof(Matrix))) == NULL) {
        return NULL;
    }

    if ((mat->data = calloc(rows, sizeof(float*))) == NULL) {
        free(mat);
        return NULL;
    }

    for (int i = 0; i < rows; ++i) {
        mat->data[i] = calloc(cols, sizeof(float));
        if (mat->data[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }

    mat->rows = rows;
    mat->cols = cols;

    return mat;
}


float multiply_row_by_column(const Matrix* a, int row, const Matrix* b, int col)
{
    float sum = 0.0f;

    for (int k = 0; k < a->cols; ++k) {
        sum += a->data[row][k] * b->data[k][col];
    }

    return sum;
}


/**
 * @brief Multiplies two matrices, producing a new matrix
 *
 * @param a Pointer to matrix on the left of the multiplication
 * @param b Pointer to matrix on the right of the multiplication
 * @return Pointer to a new Matrix structure containing the product
 */
Matrix* matrix_multiply(const Matrix* a, const Matrix* b)
{
    assert(a != NULL && b != NULL);
    assert(a->cols == b->rows);

    Matrix* result = matrix_create(a->rows, b->cols);

    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < b->cols; ++j) {
            result->data[i][j] = multiply_row_by_column(a, i, b, j);
        }
    }

    return result;
}


float get_pseudorandom_number(float max_value)
{
    int num = rand();
    return (max_value * num) / RAND_MAX;
}


/**
 * @brief Fills a matrix with pseudorandom values in the range [0.0, 1.0]
 *
 * @param mat Pointer to matrix that will hold the values
 */
void matrix_fill(Matrix* mat)
{
    assert(mat != NULL);

    srand(time(NULL));

    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j) {
            mat->data[i][j] = get_pseudorandom_number(1.0);
        }
    }
}


/**
 * @brief Releases all memory allocated to the given matrix
 *
 * @param mat Pointer to an existing Matrix structure
 */
void matrix_destroy(Matrix* mat)
{
    assert(mat != NULL);

    for (int i = 0; i < mat->rows; ++i) {
        free(mat->data[i]);
    }

    free(mat->data);
    free(mat);
}
