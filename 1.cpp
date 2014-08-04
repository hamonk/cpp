#include <vector>
#include <iostream>

using namespace std;

int main () {

  double x;
  vector<double> homework;

  while (cin >> x) 
    homework.push_back(x);

  sort (homework.begin(), homework.end() );

  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  for (vec_sz i = 0; i != size; i++) 

    cout << i << " -> " << homework[i] << endl;

  return 0;

}
