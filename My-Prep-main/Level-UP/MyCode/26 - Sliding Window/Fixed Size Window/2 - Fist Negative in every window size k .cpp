
// Gfg Link - https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> ans;
    queue<int> que;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            que.push(A[i]);
    }

    // Best test Case
    ans.push_back(que.empty() ? 0 : que.front());

    for (int i = K; i < N; i++)
    {
        // negative
        if (A[i] < 0)
        {
            que.push(A[i]);

            // new element se 3 piche wala agr queue ke front ke barabar hai
            // means wo window size se bahar jaa chuka hai
            if (A[i - K] == que.front())
            {
                que.pop();
            }

            ans.push_back(que.empty() ? 0 : que.front());
        }
        // positive
        else
        {
            if (A[i - K] == que.front())
            {
                que.pop();
            }
            ans.push_back(que.empty() ? 0 : que.front());
        }
    }

    return ans;
}