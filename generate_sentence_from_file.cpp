#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <fstream>

using namespace std;

// define new types for the rules
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// generates a random number
int nrand (int n) {

  if (n <= 0 || n > RAND_MAX) 
    throw domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;
  
  int m = rand();
  do r = m / bucket_size;
  while (r >= n);

  cout << "m:" << m << "|r:" << r << endl;
  return r;
}

// check if string starts and ends with a bracket
bool bracketed (const string& s) {
  /*bool ret = s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
    cout << s << ":" << ret << endl;*/
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// recursive fonction that modifies ret in input to expand the <signs>
void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {

  // if the word is not bracketed, then it is ready to be inserted at the end
  if (!bracketed(word)) {
    ret.push_back(word);
  }

  else {

    // this will return the iterator where the word is defined in the map
    Grammar::const_iterator it = g.find(word);

    // if not found, the g.end() iterator is returned
    if (it == g.end())
      throw logic_error("empty rule");

    const Rule_collection& c = it->second;

    int k = nrand(c.size());
    //cout << word << ":" << k << "(" << c.size() << ")" << "[" << RAND_MAX << "]" << endl;
    const Rule& r = c[k];

    // recursive call
    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);

  }
}

      
// call with the "hardcode" where to start
vector<string> gen_sentence(const Grammar& g){ 

  vector<string> ret;
  gen_aux(g,"<sentence>",ret);
  return ret;

}

// our famous split function
vector<string> split (string s) {

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


Grammar read_grammar ()
{
  Grammar ret;
  string line;
  
  ifstream f ("grammar.txt");

  while(getline(f, line)) {

    vector<string> entry = split(line);
    
    // we did a split of the line, the first element is the map entry
    // the second element is a vector of strings
    if (!entry.empty())
      ret[entry[0]].push_back (Rule(entry.begin() + 1, entry.end()));
  }
  return ret;
}
			       


int main() {

  vector<string> sentence = gen_sentence(read_grammar());
  vector<string>::const_iterator it = sentence.begin() ;

  // display the first element at the beginning of the line
  if (!sentence.empty()) {
    cout << *it;
    ++it;
  }

  // display the other element, with a space in between
  while (it != sentence.end()) {
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;

}
