#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  if (rows < 1 || columns < 1) {
    flag = INCORRECT_MATRIX;
  }
  if (!flag) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = malloc(sizeof(double *) * rows);
    if (result->matrix == NULL) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = malloc(sizeof(double) * columns);
        if (result->matrix[i] == NULL) {
          flag = CALC_ERROR;
          break;
        }
      }
    }
  }
  return flag;
}
