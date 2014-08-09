#include <vector>
#include <iostream>
#include <string>
#include "frame_picture_lib.h"

using namespace std;

int main () {

  string s;

  cout << "Please enter your text, I will frame it for you" << endl;

  while (getline(cin, s)) {

    vector<string> v = my_split(s);
    vector<string> r = frame_it(v);

    for (vector<string>::size_type j = 0; j != r.size(); ++j) {

      cout << r[j] << endl;

    }
    
    //cout << "end for this line" << endl ;
  }      

  //cout << "end for the program" << endl;

  return 0;

}
