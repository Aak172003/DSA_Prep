#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int> &arr, int target)
{
  // base case ,
  // if target hi nhi dia means hum 0 return krdenge
  if (target == 0)
  {
    return 0;
  }
  // If apni value -ve me jaati hai ,
  // mini update hi na hoo is case me
  if (target < 0)
  {
    return INT_MAX;
  }

  // let's solve 1 case

  // jb hamare target < 0 jaata hai means there is
  //   no number of elemet to reach target sum
  int mini = INT_MAX;

  for (int i = 0; i < arr.size(); i++)
  {

    // cout << "Iteration -> " << i << endl;

    //  Solve return minimum , no of eleements to get target sum
    //  ans is that value jo target me arr[index] ki value substract krke
    int ans = solve(arr, target - arr[i]);

    // cout << "ans value is " << ans << endl;
    // cout << "mini value befor: " << mini << endl;

    // check constion if or ans reach -ve value ,
    // then we dont update mini value

    if (ans != INT_MAX)
    {
      // + 1 because 1 ,dia hai or arr = [1 2]
      // jo initial me ans  = 0, hota hai , jb ek brr reccursion chala
      // tb wo ek br hi chaleha or phr ans  =0 , return krega ,

      // so mini nikalne ke lie min(mini  , ans + 1) which means 1 br to hoga hi
      mini = min(mini, ans + 1);
    }

    // cout << "mini value is " << mini << endl;
  }

  return mini;
}

int main()
{
  vector<int> arr{1, 2};
  int target = 3;

  int ans = solve(arr, target);
  cout << "Answer is: " << ans << endl;
  return 0;
}

// OutPut

/*

// phle left left call until target not reach = 0 or -ve value

Iteration -> 0
Iteration -> 0
Iteration -> 0

//                        Initial
ans value is 0
mini value befor: 2147483647
//                        Then value
mini value is 1

// [1,2]
//    i = 1
Iteration -> 1
ans value is 2147483647
mini value befor: 1
mini value is 1

// Return back krte time ans = 1

ans value is 1
mini value befor: 2147483647
mini value is 2


// [1,2]
//    i = 1

Repeat Again

Answer is: 2

*/
