// Gfg -  https://practice.geeksforgeeks.org/problems/help-classmates--141631/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {

        // Solve using Two Loop

        vector<int> ans;
        int minele = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            bool found = false;

            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    minele = arr[j];
                    found = true;
                    break;
                }
            }
            if (found)
            {
                ans.push_back(minele);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;

        // Using Stack

        vector<int> ans;

        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            int ele = arr[i];

            // cout<<"ele is : "<<ele <<endl;
            if (st.empty())
            {
                ans.push_back(-1);
                st.push(ele);

                // cout << "top ele : " << st.top() << endl;
            }

            // here goes if st.empty nhi hai
            else
            {
                // cout << "first ele : " << ele << " "<< "first top : " << st.top() << endl;

                while (!st.empty() && st.top() >= ele)
                {
                    st.pop();
                }

                int size = st.size();
                // cout<<"size is : "<<size<<endl;

                if (st.empty())
                {
                    ans.push_back(-1);
                }
                else
                {

                    // cout<<"st.top : "<<st.top()<<endl;
                    int topele = st.top();
                    ans.push_back(topele);
                }

                st.push(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};