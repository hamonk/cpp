#include <algorithm> 
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main () {

  static const int arr[] = {16,2,77,29};
  vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  vector<int>::iterator iter;

  int a = 2;
  iter = find(v.begin(), v.end(),a);
  cout << ((*iter == a) ? "success!" : "fail!") << endl;

  a = 77;
  iter = find(v.begin(), v.end(),a);
  cout << ((*iter == a) ? "success!" : "fail!") << endl;

  a = 81;
  iter = find(v.begin(), v.end(),a);
  cout << ((*iter == a) ? "success!" : "fail!") << endl;

  return 0;

}
