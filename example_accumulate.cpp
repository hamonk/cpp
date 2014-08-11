#include <algorithm> 
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main () {

  //accumulate(b,e,t)

  static const int arr[] = {16,2,77,29};
  vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  cout << "answer should be 124" << endl; 
  cout << accumulate(v.begin(), v.end(), 0.0) << endl;;

  return 0;

}
