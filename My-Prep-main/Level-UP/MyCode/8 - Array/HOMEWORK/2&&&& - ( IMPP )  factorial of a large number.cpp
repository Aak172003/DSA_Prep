

// GFG - https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
public:
    vector<int> factorial(int N)
    {
        // ek vector bnaya , jisme result final ka answer store krenge
        vector<int> result;

        // Initial me push(1)

        result.push_back(1);
        int carry = 0, mul = 0;

        // yaha hum 2 loop chalaenge , phle loop 2 se lekr N tk jaega jiska hume fact nikalna hai
        // or ander wala loop result pr chalega ,

        for (int i = 2; i < N + 1; i++)
        {
            for (int j = 0; j < result.size(); j++)
            {
                // phle case me 2 * result me jo pda hai result[j] se multiply kreneg  + carry also krenge
                // uske bdd mul me jo result aaega uska carry and digit nikal lenge
                // Then digit ko result vector me daal denge result[j] pr ,
                // jisse bd me i = 3, hone pr wo 2 se multiply kre

                // Same process repeat again and again

                mul = result[j] * i + carry;

                result[j] = mul % 10;

                carry = mul / 10;
            }

            while (carry > 0)
            {
                int finalCarry = carry % 10;
                result.push_back(finalCarry);
                // if or carry bcha hai to loop gonna run
                carry = carry / 10;
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};