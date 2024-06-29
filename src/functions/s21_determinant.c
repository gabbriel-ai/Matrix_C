#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }
  if (A->columns == 1 && A->rows == 1) {
    *result = 1.0f;
    return OK;
  }
  int code = OK;
  *result = 1;
  matrix_t temp;
  code = s21_create_matrix(A->rows, A->columns, &temp);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        temp.matrix[i][j] = A->matrix[i][j];
      }
    }

    for (int i = 1; i < A->rows; i++) {
      for (int j = 0; j < i; j++) {
        double scale = temp.matrix[i][j] / temp.matrix[j][j] * (-1);
        s21_scale_row(i, j, scale, &temp);
      }
    }
    for (int i = 0; i < A->rows; i++) {
      *result = *result * temp.matrix[i][i];
    }
  }

  s21_remove_matrix(&temp);
  return code;
}
