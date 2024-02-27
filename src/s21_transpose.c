 #include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (!A || A->rows < 1 || A->columns < 1) {
    flag = INCORRECT_MATRIX;
  }
  if (!flag) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return flag;
}
