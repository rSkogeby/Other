#include <stdlib.h>
#include <iostream>

// Reverse elements O(n), for n elements loops n/2 times
int main(){
  float x[10]={11,22,33,44,55,66,77,88,99,101};
  float* left = &x[0];
  float* right = &x[9];
  std::cout << left << " " << right << std::endl;
  while(left < right){
    float temp = *left;
    *left++  = *right;
    *right-- = temp;
  }

  return EXIT_SUCCESS;
}
