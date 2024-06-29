#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL) {
    return INCORRECT_MATRIX;
  }

  int code = OK;
  matrix_t temp;
  code = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_copy_minor(A, &temp, i, j);
        double determinant = 0;
        code = s21_determinant(&temp, &determinant);
        result->matrix[i][j] = determinant * pow(-1, i + j);
      }
    }
  }

  s21_remove_matrix(&temp);
  return code;
}
