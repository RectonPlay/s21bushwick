#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!(A && A->columns > 0 && A->rows > 0) || result == NULL) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALC_ERROR;
  } else {
    matrix_t temp1 = {0}, temp2 = {0};
    double determinant = 0.0;
    s21_determinant(A, &determinant);
    if (determinant == 0.0) return 2;
    s21_calc_complements(A, &temp1);
    s21_transpose(&temp1, &temp2);
    s21_mult_number(&temp2, 1 / determinant, result);
    s21_remove_matrix(&temp1);
    s21_remove_matrix(&temp2);
  }
  return status;
}
