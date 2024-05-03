
/*
LeetCode Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

// ***********************************     Bruteforce Apprch + Two for loop

// Idea - Do Check Double Time For Each element

// Time Complexcity - O(N*N) < = Give You TLE
// Space Complexcity - O(1)

bool isPresentornot(int ele, vector<int> &ans)
{
    for (auto it : ans)
    {
        if (ele == it)
            return true;
    }
    return false;
}
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        bool isPresent = isPresentornot(ele, ans);
        cout << "bool is : " << isPresent << endl;
        if (!isPresent)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (ele == nums[j])
                {
                    ans.push_back(nums[j]);
                }
            }
        }
    }

    for (auto it : ans)
    {
        cout << "the data is " << it << endl;
    }
    return ans;
}

// ***********************************     2.Using Sort + linearly iterate

// First Sort the array , then linearly itterative from i =1 to n-1
// if array ke aage ki value or usse just piche ki value same hoti hai to usko vector me push krdenge

// Time Complexcity - O(N*Log N)
// Space Complexcity - O(1)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return {};
        vector<int> ans;

        sort(begin(nums), end(nums));

        for (int i = 1; i < nums.size(); i++)
        {
            // then linearly itterative from i =1 to n-1
            // if array ke aage ki value or usse just piche ki value same hoti hai to usko vector me push krdenge
            if (nums[i] == nums[i - 1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// ***********************************               3. Using HashMap

// // jb do duplicate elements nikalna hai ron hum map ka hi use best rhega kyuki ,
// // XOR ek elements ko find krne ke lie sahi hai

// in this approach , we store the frequency of all elements
// then iterate over array , then those elemets have frequency == 2  , then push into vector

// Time Complexcity - O(N)
// Space Complexcity - O(N)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mapp;
        // First of All here we count frequencies means no of occurance in array
        for (auto it : nums)
        {
            mapp[it]++; // mpp[it] means hash table me it ki jo value hai usko increment if it occur multiple time
        }
        // Use to store the rsult
        vector<int> ans;
        for (auto it : mapp) // it it an iterator
        {
            if (it.second == 2)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// *************************************      4. Most Efficent Solution ( Negative Marking Method )
// Idea -

// If you Look This ->array of integers, 1 ≤ a[i] ≤ n (n = size of array)constrain [ given ]
// We Can Easily Identify That All element's Are greater Then or equal 1 and Less Then or Equall size of the array
// And 2 . Constrain elements appear twice and others appear once

// So try To Use Those Information To Come Up better a solution

// What We can Do is That We Can Use That Given Array As an Frequency Array
// and Instade of Count The each Element we Can Use -[minus] To track Each Element we are traverse Or Not [as They said That any element can occoure max Twice]
// While Traverseing if We Get Negetive element again We Know That It's Allredy Visited So It Wolud Be a duplicate num <= Push That Into ANS array

// Lastly Return ANS array

// For More Clearfy This Approch let's take an Example

//     Example
//     Assume I/O Array A - [ 4, 3, 2, 7, 8, 2, 3, 1 ]
//                index -     0  1  2  3  4  5  6  7
//

//     index element Todo 0 A[0] = 4 A[4 - 1] Not negative do it negetive mean we visited 4 array - [ 4, 3, 2, -7, 8, 2, 3, 1 ]

//                        1 A[1] = 3 A[3 - 1] Not negative do it negetive mean we visited 3 array - [ 4, 3, -2, -7, 8, 2, 3, 1 ]

//                        2 A[2] = 2 A[2 - 1] Not negative do it negetive mean we visited 2 array - [ 4, -3, -2, -7, 8, 2, 3, 1 ]

//                        3 A[3] = 7 A[7 - 1] Not negative do it negetive mean we visited 7 Array - [ 4, -3, -2, -7, 8, 2, -3, 1 ]

//                        4 A[4] = 8 A[8 - 1] Not negative do it negetive mean we visited 8 Array - [ 4, -3, -2, -7, 8, 2, -3, -1 ]

//                        5 A[5] = 2 A[2 - 1] is Negative Mean It is A duplicate ele so Put it into ans array Array[4, -3, -2, -7, 8, 2, -3, -1]

//                        6 A[6] = 3 A[3 - 1] is Negative Mean It is A duplicate ele so Put it into ans array Array - [ 4, -3, -2, -7, 8, 2, -3, -1 ]

//                        7 A[7] = 1 A[1 - 1] Not negative do it negetive mean we visited 1 Array - [-4, -3, -2, -7, 8, 2, -3, -1]

//  So we Have{ 2, 3 } <= Here For ans

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // if nums empty , so return empty vector
        if (nums.empty())
            return {};
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            // if vallue visited hai , so push into vector
            if (nums[abs(nums[i]) - 1] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            // value not visited , so mark -ve , indicates visited
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return ans;
    }
};