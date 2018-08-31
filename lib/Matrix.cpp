#include <math.h>
#include <iostream>
#include "Matrix.h"

namespace STHMIN003
{
    Matrix::Matrix(){}
    Matrix::Matrix(std::vector<STHMIN003::Vector> vectors)
    {
      for(Vector vector : vectors)
      {
        values.push_back(vector);
      }
    }

    //identity matrix of given size
    Matrix::Matrix(int size)
    {
      for(int i = 0; i < size; ++i)
      {
        Vector row(size);
        row[i] = 1;
        values.push_back(row);
      }
    }

    Matrix::Matrix(int width, int height){
      for(int i = 0; i < height; ++i){
        Vector row(width);
        row[i] = 0;
        values.push_back(row);
      }
    }

    Matrix::~Matrix(){}

    Matrix Matrix::operator*(Matrix other)
    {
      Matrix result;
      Vector result_row;
      //for row in A
      for(unsigned int i = 0; i < values.size(); ++i)
      {
        //  get row
        Vector row_of_A = values[i];
        //  for col in B
        for (unsigned int j = 0; j < values.size(); ++j)
        {
          Vector col_of_B = other.get_col(j);
          float sum = 0;
          for(unsigned int k = 0; k < row_of_A.size(); ++k)
          {
          //    rowA * colB
            sum += row_of_A[k] * col_of_B[k];
          }
          result_row.push_back(sum);
        }
        result.push_back(result_row);
      }

      return result;
    }

    Matrix Matrix::operator-(Matrix other)
    {
      Matrix result(values.size());
      for(unsigned int i = 0; i < values.size(); ++i)
      {
        Vector row;
        for(unsigned int j = 0; j < values[0].size(); ++j)
        {
          result.values[i][j] = values[i][j] - other.values[i][j];
        }
      }
      return result;
    }

    void Matrix::push_back(STHMIN003::Vector row)
    {
      values.push_back(row);
    }

    float Matrix::get(int row, int col)
    {
      return values[row][col];
    }

    Vector Matrix::get_col(int index)
    {
      Vector result;
      for(Vector row: values)
      {
        result.push_back(row[index]);
      }
      return result;
    }

    float Matrix::determinant(STHMIN003::Matrix matrix)
    {
      return (matrix.get(0,0) * matrix.get(1,1) + (matrix.get(0,1) * matrix.get(1,0))); 
    }

    Vector Matrix::get_eigen_values()
    {
      Vector result;
      float A = get(0,0),
            B = get(0,1),
            C = get(1,0),
            D = get(1,1);
      float eigen1 = ((A + D) + sqrt(((A + D) * (A + D)) - 4 * (A * D - B * C) )) / 2;
      float eigen2 = ((A + D) - sqrt(((A + D) * (A + D)) - 4 * (A * D - B * C) )) / 2;

      result.push_back(eigen1);
      result.push_back(eigen2);
      return result;
    }

    float Matrix::get_total_varience()
    {
      return this->get(0,0) + this->get(1,1);
    }

    Matrix Matrix::make_eigen_vectors()
    {
      Vector eigen_values = this->get_eigen_values();
      Vector eigen_vector_1(std::vector<float>({this->get(0, 1), eigen_values[0] - this->get(0, 0)}));
      Vector eigen_vector_2(std::vector<float>({this->get(0, 1), eigen_values[1] - this->get(0, 0)}));
      // Vector eigen_values;
      // Vector eigen_vector_1(std::vector<float>({1, -1 - 0 }));
      // Vector eigen_vector_2(std::vector<float>({1, -2 - 0 }));
      Matrix eigen_vectors;
      eigen_vectors.push_back(eigen_vector_1.make_unit_vector());
      eigen_vectors.push_back(eigen_vector_2.make_unit_vector());
      return eigen_vectors;
    }

    
} // STHMIN003
