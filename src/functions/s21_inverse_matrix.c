#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL) {
    return INCORRECT_MATRIX;
  }

  int code = OK;
  double determinant = 0;
  s21_determinant(A, &determinant);
  if (determinant != 0) {
    matrix_t temp;
    matrix_t temp2;
    code = s21_create_matrix(A->rows, A->columns, &temp);
    code = s21_create_matrix(A->rows, A->columns, &temp2);
    if (code == OK) {
      code = s21_calc_complements(A, &temp);
      code = s21_transpose(&temp, &temp2);
      code = s21_mult_number(&temp2, 1.0 / determinant, result);
    }
    s21_remove_matrix(&temp);
    s21_remove_matrix(&temp2);
  } else {
    code = CALCULATION_ERROR;
  }
  return code;
}