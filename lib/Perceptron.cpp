#include <vector>
#include <iostream>
#include <stdio.h>  /* NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "Perceptron.h"

namespace STHMIN003
{
  
  Perceptron::Perceptron(int number_of_weights){

    //initialise weights vector
    weights.clear();
    weights.resize(number_of_weights);
    this->number_of_weights = number_of_weights;

    /* initialize random seed for rand() */
    srand(time(NULL));
    
    for(int i = 0 ; i < number_of_weights; ++i)
    {
      /* generate random number between -1 and 1: */
      float random_weight = (static_cast<float>(rand())/ static_cast<float>(RAND_MAX) )* 2 - 1;
      weights.push_back(random_weight);
    }
    bias = (static_cast<float>(rand())/ static_cast<float>(RAND_MAX) )* 2 - 1;
    
  }

  Perceptron::~Perceptron(){ }
  
  Perceptron::Perceptron(){
    
  }

  float Perceptron::get_bias() { return bias; }
  void Perceptron::reset(int number_of_weights){ 
    //initialise weights vector
    weights.clear();
    weights.resize(number_of_weights);
    this->number_of_weights = number_of_weights;

    /* initialize random seed for rand() */
    srand(time(NULL));
    
    for(int i = 0 ; i < number_of_weights; ++i){
      /* generate random number between -1 and 1: */
      float random_weight = (static_cast<float>(rand())/ static_cast<float>(RAND_MAX) )* 2 - 1;
      weights.push_back(random_weight);
    }
    bias = (static_cast<float>(rand())/ static_cast<float>(RAND_MAX) )* 2 - 1;
  }
  std::vector<float> Perceptron::get_weights(){ return weights; }

  void Perceptron::train(std::vector<float> inputs, int answer){
    int guess = activation_function(inputs);
    int error = guess - answer;// t - y

    //adjust weights
    for(unsigned int i = 0; i < inputs.size(); ++i){
      weights[i] += learning_rate * error * inputs[i];
    }
    //adjust bias
    bias += learning_rate * error * 1; //input = 1 for bias
  }

  /**
   * takes inputs and multiply by corresponding weights
   * checks if the sum is positive or negative, returns 1 or 0
  */
  int Perceptron::activation_function(std::vector<float> inputs){
    float wieghted_sum = 0;
    for(unsigned int i = 0; i < inputs.size(); ++i){
      wieghted_sum += weights[i] * inputs[i]; // loop through inputs
    }
    wieghted_sum += bias;
    return wieghted_sum > 0 ? 0 : 1;
  }
  
} // STHMIN003