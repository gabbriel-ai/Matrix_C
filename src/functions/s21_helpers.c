#include "../s21_matrix.h"

void s21_copy_minor(matrix_t *input, matrix_t *result, int except_row,
                    int except_column) {
  for (int i = 0, result_row = 0; i < input->rows; i++) {
    if (i != except_row) {
      for (int j = 0, result_column = 0; j < input->columns; j++) {
        if (j != except_column) {
          result->matrix[result_row][result_column] = input->matrix[i][j];
          result_column++;
        }
      }
      result_row++;
    }
  }
}

void s21_scale_row(int row, int cur_row, double scale, matrix_t *result) {
  for (int i = 0; i < result->columns; i++) {
    result->matrix[row][i] =
        result->matrix[row][i] + result->matrix[cur_row][i] * scale;
  }
}

double mult_result(matrix_t *A, matrix_t *B, int row, int col) {
  double result = 0.0f;
  for (int i = 0; i < A->columns; i++) {
    result += A->matrix[row][i] * B->matrix[i][col];
  }
  return result;
}