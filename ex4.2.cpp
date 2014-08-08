#include <iostream> 
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::setw;

int main () {

  for (int i=0; i!= 101; ++i) {

    cout << "i:" << setw(3) << i << ",i^2:" << setw(6)<< i*i << endl;

  }
}
