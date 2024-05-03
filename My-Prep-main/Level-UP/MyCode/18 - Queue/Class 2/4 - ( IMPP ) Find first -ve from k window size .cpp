vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    int i = 0, j = 0;
    queue<int> q;
    vector<long long int> ans;

    while (j < N)
    {
        // jb tk k tk nhi pauchta hum value -ve hai ki nhi wo check krke queue me daalte jaenge
        if (A[j] < 0)
        {
            q.push(A[j]);
        }

        if (j - i + 1 < K)
        {
            j++;
        }
        // Jb reach kr jaega to q check krenge ki wo empty hai ki nhi
        // agr wo khali hota hai means no -ve value encountered during traversal
        // so hum ans me 0 daal denge
        else if (j - i + 1 == K)
        {
            // if q isempty
            if (q.empty())
            {
                ans.push_back(0);
            }
            // ek brr me k size tk ki -ve value Queue me chali jaegii , jb ek baar me k size tk ki value queue me
            // jaane ke bdd i bdh jaega ,
            // jisse hum q.front ki value check krenge agr A[] ki value same hoti hai means wo queue se pop krdenge

            // kyuki duplicate element na jae
            else
            {
                int data = q.front();
                ans.push_back(data);
                // data ko ans me push_back krne ke bdd Queue se delete
                if (data == A[i])
                {
                    q.pop();
                }
            }
            // Phr i++ , j++ bdh jaega phr dubara se sb -ve value queue me jaati or
            // queue check hota agr empty nhi hai to
            // q ki jo phli value hai usko hum ans me daal denge
            // or phr uske bdd hum check krenge ki jo value hai wo a[i] ke equal hai to
            // usko q se pop krdenge
            i++;
            j++;
        }
    }
    return ans;
}
