/*
LeetCode Link - https://leetcode.com/problems/divide-two-integers/description/
*/

// This was also solve by , Babbar bhaiya

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long start = 0;
        long end = abs(dividend);
        long ans = 0;

        // if upr wali value bahut INT_MIN dia ho , or nice wali -1
        if (dividend == INT_MIN && divisor == -1)
        {
            // so we return INT_MAX value
            return INT_MAX;
        }

        while (start <= end)
        {
            long mid = start + (end - start) / 2;
            /*

                Lets Say , Hota hai na ,
                phli bt yaha koi index to hai mhi ,
                yaha hum assume krke chalenge agr 10 divisor dia hai to means
                0 1 2 3 4 5 6 7 8 9   tk value dia hoga

                So agr hume pta krna ki hamara answer after divide

                so hota hai na 20/2 = 10
                so if hamare pss 20 tk value dia hai
                to kya mai mid jo hai usme agr divior ka multiply krta hu , to kya mujhe answer mil paega ki nhi
                agr ha equal hota hai to us cureent value ko store krdenge ,
                or left ke lie call mrr denge ,
                kyuki hume ensure krna hai ki hamara divide krte time km se km answer aaye

            */

            if (abs(mid * divisor) == abs(dividend))
            {
                ans = mid;
                break;
            }
            if (abs(mid * divisor) > abs(dividend))
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;
            }
        }

        // if both positive , and if both negative
        // return positive value , kyuki dono kt jaenge + / +  or - / -
        if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
        {
            return int(ans);
        }
        // if both are non positive and if both are non negative
        // one is positive and other is negative return -ve ans
        else
        {
            return int(-ans);
        }
    }
};

// Babbar Bhaiya -  DSA Supreme Battch

// TestCases
// cout << 22 / (-7) << '\n';
// cout << (-22) / (-7) << '\n';
// cout << (-22) / 7 << '\n';
