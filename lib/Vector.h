#include <string>
#include <vector>

#ifndef VECTOR_H
#define VECTOR_H

namespace STHMIN003
{
  class Vector
  {
  private:
    std::vector<float> values;
    float avg;
  public:
    Vector(std::vector<float> new_values);
    Vector();
    Vector(int size);
    ~Vector();

    float & operator[](int index);

    float get_avg();
    Vector get_phi();
    float get_varience();
    unsigned int size();
    Vector make_unit_vector();
    void push_back(float value);
  };
  
} // STHMIN003

#endif