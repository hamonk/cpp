#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> frame_it (const vector<string> vec_s) {
  
  vector<string> ret ;
  string::size_type maxlen = 0;
  
  for (vector<string>::size_type i = 0; i != vec_s.size(); ++i) {

    if ((vec_s[i]).size() > maxlen) {

      maxlen = (vec_s[i]).size();

    }
  }

  string border(maxlen + 4, '*');
  ret.push_back(border);

  for (vector<string>::size_type i = 0; i != vec_s.size(); ++i) {
    ret.push_back("* "+
		  vec_s[i]+
		  string(maxlen-vec_s[i].size(),' ')+
		  " *");
  }

  ret.push_back(border);

  return ret;
}

vector<string> my_split (string s) {
  
  vector<string> v ;
  string::size_type i = 0;
  
  while (i < s.size()) {

    if (!isspace(s[i])) {

      string::size_type j = i;

      while (j != s.size() && !(isspace(s[j]))) {
	++j;
      }

      // we found a word with at least 1 letter 
      if (j > i) {
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

  cout << "Please enter your text, I will frame it for you" << endl;

  while (getline(cin, s)) {

    vector<string> v = my_split(s);
    vector<string> r = frame_it(v);

    for (vector<string>::size_type j = 0; j != v.size(); ++j) {

      cout << r[j] << endl;

    }
    
    cout << "end for this line" ;
  }      

  cout << "end for the program" << endl;

  return 0;

}
