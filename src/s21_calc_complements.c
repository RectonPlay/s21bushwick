#include "s21_matrix.h"

int s21_minor(int rows, int columns, matrix_t *A, matrix_t *minor) {
  int flag = OK;
  flag = s21_create_matrix(A->rows - 1, A->columns - 1, minor);
  if (!flag) {
    int n = 0;
    int k = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i == rows) continue;
      for (int j = 0; j < A->columns; j++) {
        if (j == columns) {
          continue;
        } else {
          minor->matrix[n][k++] = A->matrix[i][j];
        }
      }
      k = 0;
      n++;
    }
  }
  return flag;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (!A || A->rows < 1 || A->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else {
    if (A->rows != A->columns) flag = CALC_ERROR;
  }
  if (!flag) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double det = 0;
        matrix_t minor;
        s21_minor(i, j, A, &minor);
        s21_determinant(&minor, &det);
        result->matrix[i][j] = pow(-1, (i + j)) * det;
        s21_remove_matrix(&minor);
      }
    }
  }
  return flag;
}
