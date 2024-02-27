#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (!A || A->rows < 1 || A->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else {
    if (A->rows != A->columns) flag = CALC_ERROR;
  }
  if (!flag) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      if (A->rows == 2) {
        *result = (A->matrix[0][0] * A->matrix[1][1] -
                   A->matrix[1][0] * A->matrix[0][1]);
      } else {
        for (int i = 0; i < A->rows; i++) {
          matrix_t minor;
          double det = 0;
          flag = s21_minor(i, 0, A, &minor);
          s21_determinant(&minor, &det);
          s21_remove_matrix(&minor);
          *result += pow(-1, i) * A->matrix[i][0] * det;
        }
      }
    }
  }
  return flag;
}
