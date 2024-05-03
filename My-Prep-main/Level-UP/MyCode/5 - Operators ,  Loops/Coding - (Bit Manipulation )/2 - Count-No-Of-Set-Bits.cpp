/*
Leetcode Link - https://leetcode.com/problems/number-of-1-bits/submissions/
*/

// Note that in some languages, such as Java, there is no unsigned integer type.
// In this case, the input will be given as a signed integer type.
// It should not affect your implementation,
// as the integer's internal binary representation is the same, whether it is signed or unsigned.

// In Java, the compiler represents the signed integers using 2's complement notation.
// Therefore, in Example 3, the input represents the signed integer. -3.

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n != 0)
        {
            /*
                Checking last bit
                last bit se & (AND) krna hai
                */

            // jbki n me no of bits dia hai , so uska AND krne me koi problem nhi hogi

            if (n & 1 == 1) // Jb dono true honge then count++
                count++;

            n = n >> 1; // Right Shift krte rhege jb tk saari value 0 na hojae
            // jb n ki value 0 hogyi means saari value count hogyi
        }
        return count;
    }
};