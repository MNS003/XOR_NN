#include "../lib/Vector.h"
#include <math.h>

namespace STHMIN003
{
  Vector::Vector()
  {
    avg = 0;
    values.clear();
  }
  Vector::Vector(std::vector<float> new_values)
  {
    float sum = 0;
    for(float value: new_values)
    {
      values.push_back(value);
      sum += value;
    }
    
    avg = sum / values.size();
  }
  //empty vector of size length
  Vector::Vector(int size)
  {
    avg = 0;
    values.clear();
    values.resize(size);
  }
  Vector::~Vector(){}

  float Vector::get_avg(){return avg;}

  float & Vector::operator[](int index)
  {
    return values[index];
  }

  float Vector::get_varience()
  {
    float sum = 0;
    for (unsigned int i = 0; i < size(); ++i)
    {
      sum += (values[i] - avg) * (values[i] - avg);
    }
    return sum / (size() - 1);
  }

  

  void Vector::push_back(float value)
  {
    values.push_back(value);
    float sum = 0;
    for(float value: values)
    {
      sum += value;
    }
    avg = sum / values.size();
  }

  Vector Vector::get_phi()
  {

    Vector phi_list;
    for(float x: values)
    {
      phi_list.values.push_back(x - avg);
    }
    return phi_list;
  }

  Vector Vector::make_unit_vector()
  {
    float magnitude = sqrtf( ((values[0] * values[0]) + (values[1] * values[1]) ) );
    // float smaller = values[0] > values[1] ? values[1] : values[0];
    return Vector(std::vector<float>({
      values[0]/magnitude, values[1]/magnitude
    }) );
  }

  unsigned int Vector::size(){return values.size();}

} // STHMIN003
