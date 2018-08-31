#include <iostream>
#include <fstream>
#include <sstream>
#include "XOR.h"

using namespace std;
namespace STHMIN003
{
  XOR::XOR(int num_weights, string and_txt, string or_txt, string xor_txt){
    and_perceptron.reset(num_weights);
    or_perceptron.reset(num_weights);
    load(and_txt, or_txt, xor_txt);
  }

  void XOR::train(std::vector< std::vector<float>> inputs){
    //pre generate answers
    
    and_answers.push_back(0);
    and_answers.push_back(0);
    and_answers.push_back(0);
    and_answers.push_back(1);
    //train AND perceptron
    train_perceptron(and_perceptron, inputs, and_answers);

    or_answers.push_back(0);
    or_answers.push_back(1);
    or_answers.push_back(1);
    or_answers.push_back(1);
    //trian OR perceptron
    train_perceptron(or_perceptron, inputs, or_answers);

  }

  /**
   * activation function using the output of
   * A'&&B || A&&B' as A^B by training 2 neuaral networks (AND and OR)
   * and combining them for the output
   */
  int XOR::predict(std::vector<float> inputs){

    float A = inputs[0];
    float B = inputs[1];
    float notA = (A == 0.0f ? 1.0f : 0.0f);
    float notB = (B == 0.0f ? 1.0f : 0.0f);

    //use AND and OR outputs as input for XOR gate
    return or_perceptron.activation_function(
      {
        //not A and B
        (float)and_perceptron.activation_function({notA, B}),
        //A and not B
        (float)and_perceptron.activation_function({A, notB})
      }
    );
  }
  
  void XOR::train_perceptron(Perceptron & p, std::vector<std::vector<float>> inputs, std::vector<int> answers){
    //start training
    for(int i = 0; i < 13; ++i){ //train perceptrons for 100 000 iterations
      p.train(inputs[0], answers[0]); // 0, 0
      p.train(inputs[1], answers[1]); // 0, 1
      p.train(inputs[2], answers[2]); // 1, 0
      p.train(inputs[3], answers[3]); // 1, 1
    }

  }

  void XOR::load(string and_txt, string or_txt, string xor_txt){
    vector<vector<float>> inputs;
    //inputes correspinding to input values
    float x, y;
    int answer;
    
    ifstream and_ifs(and_txt);
    ifstream xor_ifs(xor_txt);
    ifstream or_ifs(or_txt);
    string line;
    if(and_ifs.is_open() && xor_ifs.is_open()
        && or_ifs.is_open()){

      //load AND data
      while(getline(and_ifs, line)){
        stringstream ss(line);
        ss >> x >> y >> answer;
        inputs.push_back({x, y});
        and_answers.push_back(answer);
      }

      //load XOR data
      while(getline(xor_ifs, line)){
        stringstream ss(line);
        ss >> x >> y >> answer;
        inputs.push_back({x, y});
        and_answers.push_back(answer);
      }

      //load OR data
      while(getline(or_ifs, line)){
        stringstream ss(line);
        ss >> x >> y >> answer;
        inputs.push_back({x, y});
        and_answers.push_back(answer);
      }

    train(inputs);
    }
    else{
      cout << "could not open a file" <<  endl;
      throw;
    }
  }

  XOR::~XOR(){}
} // STHMIN003
