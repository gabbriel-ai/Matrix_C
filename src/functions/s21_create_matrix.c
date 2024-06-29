#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  }

  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (!result->matrix) {
    return INCORRECT_MATRIX;
  }
  for (int row = 0; row < rows; row++) {
    result->matrix[row] = (double *)calloc(columns, sizeof(double));
    if (!result->matrix) {
      return INCORRECT_MATRIX;
    }
  }
  result->rows = rows;
  result->columns = columns;
  return OK;
}