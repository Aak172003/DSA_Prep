#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(string str, int n, string output, int i, vector<string> &v)
{
  // base case
  if (i == n)
  {
    v.push_back(output);
    return;
  }
  /*
    // Exclude
    printSubsequences(str, n, output, i + 1, v);

    // Include
    printSubsequences(str, n, output + str[i], i + 1, v);

  */

  // Or

  // include
  printSubsequences(str, n, output + str[i], i + 1, v);

  // Exclude
  printSubsequences(str, n, output, i + 1, v);
}

int main()
{
  string str = "abc";
  string output = "";
  vector<string> v;
  int i = 0;
  int n = str.length();
  printSubsequences(str, n, output, i, v);

  cout << "Printing all subsequences " << endl;
  for (auto val : v)
  {
    cout << val << endl;
  }

  cout << endl
       << "Size of vector is: " << v.size() << endl;

  return 0;
}
