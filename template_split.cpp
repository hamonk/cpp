#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <fstream>
#include <ostream>
#include <iterator>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

bool space(char c) 
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

// our split function with template
template <class Out>
void split (const string& str, Out os) {
  
  typedef string::const_iterator iter;
  
  iter i = str.begin();
  while (i != str.end()) {
    i = find_if (i, str.end(), not_space);
    
    iter j = find_if(i, str.end(), space);
    
    if (i != str.end()) {
      *os++ = string(i,j);
    }
    
    i=j;    
  }
}


Grammar read_grammar ()
{
  Grammar ret;
  string line;
  
  ifstream f ("grammar.txt");

  while(getline(f, line)) {

    split(line, ostream_iterator<string>(cout, "\n"));
    // split(line, back_inserter(word_list)); //would work as well!
    
    // we did a split of the line, the first element is the map entry
    // the second element is a vector of strings
    //if (!entry.empty())
    //  ret[entry[0]].push_back (Rule(entry.begin() + 1, entry.end()));
  }
  return ret;
}
			       


int main() {

  cout << "--------->read" << endl;

  read_grammar();

  cout << "end<--------------" << endl;

  return 0;

}
