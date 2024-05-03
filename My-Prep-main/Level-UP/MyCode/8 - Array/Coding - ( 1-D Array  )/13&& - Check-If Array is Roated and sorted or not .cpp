/*

Suppose Example

in sorted Order           {1,2,3,4,5}    arr[i-1]>arr[i]   // For ek ek element
in Random order           {3,5,7,1,6}    arr[i-1]>arr[i]   // For ek ek element
in Rotaed or Sorted oRDER {3,4,5,1,2}    arr[i-1]>arr[i]   // For ek ek element

For 1st 5>1 so 1 Pair
For 2nd 7>1,6>3 so 2 Pair
For 3rd 5>1 so 1 Pair

*/

// Ek array ko hum sorted tb khenge jb array ki first value < array ki last value se
// Ek array ko hum rotated tb khenge (arr[i - 1] > arr[i]) ho

// Sos sirf rotated check krne ke lie , we only check (arr[i - 1] > arr[i]) this condition on every element
// but our task is to find , rotated or sorted ho
class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            // This is check for Rotated sorted array is present or not
            if (arr[i - 1] > arr[i]) // i-1  piche and i aage
            {
                count++;
            }
        }

        // Check for last index value , if suppose in sorted Order {1,2,3,4,5}  5>1 then Count++
        if (arr[0] < arr[n - 1])
        {
            count++;
        }

        // If All Value are same means there is Example  = {1,1,1}
        // count = 0 , means all are same elements

        // [1,2,3] , this is only sorted  (arr[0] < arr[n - 1]) from this condi
        // but sorted check krne ke lie kahi i-1 > i se

        if (count == 0 || count == 1)
            return true;
        // if count == 1 , then error because if our input is [1,1,1]
        else
            return false;

        // agr kahi count ki value 2 hoti hai means , wo sorted array nhi hai
    }
};
