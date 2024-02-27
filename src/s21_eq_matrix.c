#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (!A || !B || A->rows != B->rows || A->columns != B->columns) {
    flag = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabsl(A->matrix[i][j] - B->matrix[i][j]) > COMPARE) {
          flag = FAILURE;
          break;
        }
      }
    }
  }
  return flag;
}
