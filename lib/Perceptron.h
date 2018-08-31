#include <vector>

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

namespace STHMIN003
{
  
  class Perceptron
  {
  private:
    std::vector<float> weights;
    float learning_rate = 0.08, bias;
    int number_of_weights;
  public:
    Perceptron(int number_of_weights);
    Perceptron();
    ~Perceptron();
    void train(std::vector<float> input, int answer);
    int activation_function(std::vector<float> input);
    std::vector<float> get_weights();
    void reset(int number_of_weights);
    float get_bias();
  };
  
} // STHMIN003

#endif