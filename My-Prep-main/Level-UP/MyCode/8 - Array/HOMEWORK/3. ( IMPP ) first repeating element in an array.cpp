// Gfg -  https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {

        // ***************  1st Approach
        // Give TLE
        /*

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    return i + 1;
                }
            }
        }
        return -1;

        */

        //  ***************   2nd Approach
        // Phle sb elements ko map me daal do , uske bdd array me traverse krna
        // jaise hi koi element , jiska occurance >= 2 hua tbhi , return

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            // Agr milta hai to
            if (mpp.find(arr[i]) != mpp.end())
            {
                if (mpp[arr[i]] >= 2)
                {
                    // break;
                    return i + 1;
                }
            }
        }
        return -1;
    }
};