
#include <stdio.h>
#include <TMatrixD.h>
#include "mtrx_inv_lapack.h"
#include "test_mat.h"
// #include "mtrx_inv_openblas.h"

int main() {
  const int N = 8;
//   const int N = 5;
//   double A[] = {
//     0.378589, 0.971711, 0.016087, 0.037668, 0.312398,
//     0.756377, 0.345708, 0.922947, 0.846671, 0.856103,
//     0.732510, 0.108942, 0.476969, 0.398254, 0.507045,
//     0.162608, 0.227770, 0.533074, 0.807075, 0.180335,
//     0.517006, 0.315992, 0.914848, 0.460825, 0.731980
//   };

  printf(" ==== test_mat ====\n");
  double * A = boothroyd(N);
  printf("\n%+12.8f\n", boothroyd_determinant(N));
  printf(" ==================\n");

  printf(" ==== TMatrixD ====\n");
  TMatrixD M(N, N, A);
  mtrx_print(N, M.GetMatrixArray());
  printf("\n%+12.8f\n", M.Determinant());
  M.Invert();
  mtrx_print(N, M.GetMatrixArray());
  printf("\n%+12.8f\n", M.Determinant());
  printf(" ==================\n");

  printf(" ==== mtrx_inv ====\n");
  mtrx_print(N, A);
  printf("\n%+12.8f\n", mtrx_det(N, A));
  mtrx_inv(N, A);
  mtrx_print(N, A);
  printf("\n%+12.8f\n", mtrx_det(N, A));
  printf(" ==================\n");
}
