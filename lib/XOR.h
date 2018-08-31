#include "Perceptron.h"

#ifndef XOR_H
#define XOR_H

namespace STHMIN003
{
  
  class XOR
  {
  private:
    Perceptron and_perceptron, or_perceptron, xor_perceptron;
    std::vector<int> and_answers, or_answers, xor_answers;
  public:
    XOR(int num_weights,std::string and_txt, std::string or_txt, std::string xor_txt);
    ~XOR();
    void train(std::vector< std::vector<float>> inputs);
    void acitvation_function(std::vector<float> inputs);
    int predict(std::vector<float> inputs);
    void load(std::string and_txt, std::string or_txt, std::string xor_txt);
    void train_perceptron(Perceptron & p, std::vector<std::vector<float>> inputs, std::vector<int> answers);
  };
  
} // STHMIN003

#endif