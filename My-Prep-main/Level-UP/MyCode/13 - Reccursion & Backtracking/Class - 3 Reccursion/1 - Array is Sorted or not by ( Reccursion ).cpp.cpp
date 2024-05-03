#include <iostream>
#include <vector>
using namespace std;

// *************************************************************************************************

bool checkSorted(vector<int> &arr, int &n, int i)
{
  // base case   - >>> Because Agr i == n  hoga ,
  // to hamare pss aage or koi value hi nhi hai islea
  // humne i == n-1 lia hai

  if (i == n - 1)
  {
    return true;
  }

  // 1st Iteration
  //   1 , 1, 2 ,5 ,  6, 9 , 8
  //   |   |
  //  i-1  i

  // 2nd Iteration
  //   1 , 1 , 2 , 5 ,  6 , 9 , 8
  //       |   |
  //      i-1  i

  // 3rd Iteration
  // Ind 0   1   2   3    4   5   6
  //     1 , 1 , 2 , 5 ,  6 , 9 , 8
  //             |   |
  //            i-1  i

  // 1 case solve krna h
  if (arr[i] > arr[i + 1])
    return false;

  // baaki recursio sambhal lega , Reccursion ko call krdia
  // wo hume true or false me dega
  bool ans = checkSorted(arr, n, i + 1);

  // if agr kahi bhi false mila to , directly hume false mil jaata hai
  return ans;
}

int main()
{
  // Vector me value daalna
  vector<int> v{1, 1, 5, 1, 1, 5, 6, 7, 8};
  int n = v.size();
  int i = 0;
  bool isSorted = checkSorted(v, n, i);

  // if true
  if (isSorted)
  {
    cout << "Array is sorted" << endl;
  }
  // if false
  else
  {
    cout << "Array is not sorted" << endl;
  }

  return 0;
}