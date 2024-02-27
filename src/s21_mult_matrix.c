#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!A || !B || A->rows < 1 || B->rows < 1 || A->columns < 1 ||
      B->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else {
    if (A->columns != B->rows) {
      flag = CALC_ERROR;
    }
  }
  if (!flag) {
    flag = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        double new = 0;
        for (int k = 0; k < A->columns; k++) {
          new += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = new;
      }
    }
  }
  return flag;
}
