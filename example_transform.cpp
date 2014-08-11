#include <algorithm> 
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int square (int i) {

  return i*i*i;

}

int main () {

  static const int arr[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  vector<int> w;

  w.resize(v.size()); // the memory allocation is not handled by the transform
  transform(v.begin(),v.end(),w.begin(),square);

  for (vector<int>::iterator iter = w.begin(); iter != w.end(); ++iter)
    cout << *iter << endl;

  return 0;

}
