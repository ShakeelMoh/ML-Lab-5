//Feed forward ANN
//Shakeel Mohamed

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

float e = 2.71828182845904523536;

//Calculates sigmoid output
float sigmoid(float x){

   float output = 1/(1+(pow(e, -x)));
   return output;

}
//Calculate hidden neuron output
float hiddenNeuronOutput(float x[3], float w[3], float bias){
   
   float output = 0;
   for (int i = 0; i < 3; ++i){
      output += x[i]*w[i];
      
   }
   output += bias;
   output = sigmoid(output);
   cout << output << "\n" << endl;
   return output;
   
}
//Calculate final neuron output
float outputNeuron(float x1, float x2, float w1, float w2, float bias){
  
   float output = 0;
   
   output += x1 * w1;
   
   output += x2 * w2;

   output += bias;
   output = sigmoid(output);
   cout << output << "\n" << endl;
   
   return output;
   
}  

int main (int argc, char *argv[]) {

   cout << "Feed forward ANN\n" << endl;
   
   //Initial inputs
   float inputs[3] = {1.3, 2.7, 0.8};
   float weightsH1[3] = {0.1, 0.2, 0.5};
   float biasH1 = 0.1;
   float weightsH2[3] = {-0.4, 1, -0.6};
   float biasH2 = -0.3;
   
   float H1Output = 0;
   float H2Output = 0;
   float finalOutput = 0;
   //Calculate hidden layer 1 output
   cout << "Hidden neuron 1 output: " << endl;
   H1Output = hiddenNeuronOutput(inputs, weightsH1, biasH1);
   cout << "Hidden neuron 2 output: " << endl;
   H2Output = hiddenNeuronOutput(inputs, weightsH2, biasH2);
   cout << "Output neuron output: " << endl;
   finalOutput = outputNeuron(H1Output, H2Output, 0.8, 1, -0.3);
   
   return 0;
   
}