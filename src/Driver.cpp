#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../lib/Perceptron.h"
#include "../lib/XOR.h"

using namespace std;

void test_xor(string and_txt, string or_txt, string xor_txt);
void test_training(string and_txt, string or_txt);

int main(int argc, char const *argv[])
{
  cout << "====== ANN ======" << endl;
  cout << "training " << endl;
  string xor_txt = argv[1],
         or_txt = argv[2], 
         and_txt = argv[3];

  test_xor(and_txt, or_txt, xor_txt);
  return 0;
}

void test_xor(string and_txt, string or_txt, string xor_txt){
  STHMIN003::XOR x(2, and_txt, or_txt, xor_txt);

  cout << "0 XOR 0: "
      << (float)x.predict({0.0f, 0.0f})
      << std::endl
      << "0 XOR 1: "
      << (float)x.predict({0.0f, 1.0f})
      << std::endl
      << "1 XOR 0: "
      << (float)x.predict({1.0f, 0.0f})
      << std::endl
      << "1 XOR 1: "
      << (float)x.predict({1.0f, 1.0f})
      << std::endl;
}

void test_training(string and_txt, string or_txt){
  long start = time(NULL);
  STHMIN003::Perceptron p(2); //init perceptron with number of weights
  cout << "initial weights " << p.get_weights()[0] << " " << p.get_weights()[1]
       << endl;
  int update_count = 0;
  vector<vector<float>> inputs;
  inputs.push_back({0.0f, 0.0f});
  inputs.push_back({0.0f, 1.0f});
  inputs.push_back({1.0f, 0.0f});
  inputs.push_back({1.0f, 1.0f});
  //labels for testing
  int label_true = 1, label_false = 0;
  //rate at which the the updates are displayed
  int update_interval_in_seconds = 1;

  string op = "AND";
  while(true){

    if(op == "OR"){
        //trainging OR gate
        p.train(inputs[0], label_false); //  0, 0
        p.train(inputs[1], label_true);  //  0, 1
        p.train(inputs[2], label_true);  //  1, 0
        p.train(inputs[3], label_true);  //  1, 1
    }
    else if (op == "AND"){
        //trainging AND gate
        p.train(inputs[0], label_false);  //  0, 0
        p.train(inputs[1], label_false);  //  0, 1
        p.train(inputs[2], label_false);  //  1, 0
        p.train(inputs[3], label_true);   //  1, 1
    }
    else if (op == "CUSTOM"){
        //trainging CUSTOM gate
        p.train(inputs[0], label_false);  //  0, 0
        p.train(inputs[1], label_false);  //  0, 1
        p.train(inputs[2], label_true);  //  1, 0
        p.train(inputs[3], label_true);   //  1, 1
    }

    //operation beign tested
      ++update_count;
    if(abs(time(NULL) - start) > update_interval_in_seconds ){
      start = time(NULL);
      cout << "(0 "<< op << " 0): " << p.activation_function({0.0f,0.0f}) << endl;
      cout << "(0 "<< op << " 1): " << p.activation_function({0.0f,1.0f}) << endl;
      cout << "(1 "<< op << " 0): " << p.activation_function({1.0f,0.0f}) << endl;
      cout << "(1 "<< op << " 1): " << p.activation_function({1.0f,1.0f}) << endl;
      cout << "weights " << p.get_weights()[0] << " " << p.get_weights()[1]
           << endl;
      cout << "bias " << p.get_bias() << endl;
      cout << "updated count " << update_count << endl; 
    }
  }
}
