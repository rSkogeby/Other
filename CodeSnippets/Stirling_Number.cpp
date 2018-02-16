#include <iostream>

// (n k) ways of partitioning n objects into k nonempty subsets

int stirling(int n,int k){
  if ( n<k ) return 0;
  if ( k==0 && n>0 ) return 0;
  if ( n==k ) return 1;
  return k*stirling(n-1,k)+stirling(n-1,k-1);
}

int main(){

  int n = 5;
  int k = 4;
  int nk = stirling(n,k);
std::cout << "There are " << nk << " ways of partitioning " << n << " objects into " << k << " nonempty subsets" << std::endl;

}
