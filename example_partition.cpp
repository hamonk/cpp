#include <algorithm> 
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

bool is_odd (int i) {

  return i % 2;

}

int main () {

  static const int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
  vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  vector<int> w = v;

  cout << "partition" << endl;
  partition(v.begin(),v.end(),is_odd);

  for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    cout << " " << *iter;

  cout << endl;

  cout << "stable partition" << endl;
  stable_partition(w.begin(),w.end(),is_odd);

  for (vector<int>::iterator iter = w.begin(); iter != w.end(); ++iter)
    cout << " " <<*iter;

  cout << endl;
  return 0;

}
