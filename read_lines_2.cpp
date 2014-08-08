#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main () {

  string s;

  // this condition is false if we read the end of file aka CTRL-D from the command line
  while (cin >> s) {

    cout << s << endl;

  }      

  cout << "that's it, let's exit" << endl;

  return 0;

}
