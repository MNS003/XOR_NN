#include <string>
#include <vector>
#include "Vector.h"

#ifndef MATRIX_H
#define MATRIX_H

namespace STHMIN003
{
  class Matrix
  {
  private:
    std::vector<STHMIN003::Vector> values;
  public:
    Matrix();
    Matrix(int size);
    Matrix(int width, int height);
    Matrix(std::vector<STHMIN003::Vector> vectors);
    ~Matrix();

    Matrix operator*(Matrix other);
    Matrix operator-(Matrix other);

    STHMIN003::Vector get_col(int i);
    float get_total_varience();
    float get(int row, int col);
    void push_back(STHMIN003::Vector row);
    STHMIN003::Vector get_eigen_values();
    Matrix make_eigen_vectors();
    Matrix make_covarience_matrix(std::vector<STHMIN003::Vector> variables);
    float determinant(Matrix matrix);

  };
} // STHMIN003

#endif
