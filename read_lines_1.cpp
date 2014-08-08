#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

vector<string> my_split (string s) {
  
  vector<string> v ;
  
  cout << "the size is " << s.size() << endl;

  string::size_type i = 0;
  
  while (i != s.size()) {

    if (!isspace(s[i])) {

      string::size_type j = i;

      while (j != s.size() && !(isspace(s[j]))) {
	
	++j;

      }

      if (j > i) {
	
	// we found a word with at least 1 letter 
	v.push_back(s.substr(i,j-i));

      }

      // jump to the j_th position
      i = j;

    }
	
    ++i;
  }
  
  return v;

}

int main () {

  string s;

  while (getline(cin, s)) {

    vector<string> v = my_split(s);

    for (vector<string>::size_type j = 0; j != v.size(); ++j) {

      cout << j << ":" << v[j] << endl;

    }
  }      

  return 0;

}
