#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    return INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int code = OK;
  code = s21_create_matrix(A->rows, B->columns, result);
  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = mult_result(A, B, i, j);
      }
    }
  }
  return code;
}
