// Gfg - https://practice.geeksforgeeks.org/problems/common-elements1132/1

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {

        // *********************************************************************************************************************************************

        //                                  1st Method ( With Extra Data Structure )
        // TC - O(N)
        // SC - O(N + M)

        unordered_map<int, int> mp, mp1;
        vector<int> a, b;

        for (int i = 0; i < n1; i++)
        {
            mp[A[i]]++;
        }

        for (int i = 0; i < n2; i++)
        {
            if (mp.find(B[i]) != mp.end())
            {
                // if find
                a.push_back(B[i]);
                // If found seo us element ko map se erase bhi krna pdega ki ,
                // jisse wo dubara se na aaske agr koi same milta hai but wo 1 hi brr hai
                mp.erase(B[i]);
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            mp1[a[i]]++;
        }
        for (int i = 0; i < n3; i++)
        {
            if (mp1.find(C[i]) != mp1.end())
            {
                b.push_back(C[i]);
                // If found seo us element ko map se erase bhi krna pdega ki ,
                // jisse wo dubara se na aaske agr koi same milta hai but wo 1 hi brr hai
                mp1.erase(C[i]);
            }
        }

        return b;

        //                                 2nd Method ( Without Extra Data Structure )
        // TC - O(N)
        // SC - O(N + M)

        vector<int> ans;

        vector<int> result;
        int i = 0;
        int j = 0;
        int k = 0;

        // prevent to inserting Duplicate Element
        // For track of previous value ,
        // ki jo value pichli brr dala tha ki wo same hota hai to hum , nhi daalenge
        int previous = INT_MIN;

        while (i < n1 && j < n2 && k < n3)
        {

            if ((A[i] == B[j]) && (B[j] == C[k]))
            {
                if (A[i] == previous)
                {
                    i++;
                    j++;
                    k++;
                    continue;
                }

                // At initial first step ,
                // if all values are not equzl ,
                // so previous me A[i] daal denge
                previous = A[i];

                // Or us previus ko ans vector me daal denge or sbko aage bdha denge ek ek
                result.push_back(previous);
                i++;
                k++;
                j++;
            }
            else
            {
                int maxi = max(A[i], max(B[j], C[k]));

                // if(value == maxi) so do nothing
                while (A[i] < maxi)
                {
                    i++;
                }
                while (B[j] < maxi)
                {
                    j++;
                }
                while (C[k] < maxi)
                {
                    k++;
                }
            }
        }
        return result;
    }
};