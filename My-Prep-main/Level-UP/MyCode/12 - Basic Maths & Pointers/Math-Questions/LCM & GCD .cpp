/*
LCD and GCD Leetcode Link - https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1
*/


class Solution {
  public:

vector<long long> lcmAndGcd(long long A , long long B) {

        vector<long long> v;

        long long lcm, gcd;
        
        // Gcd inbuilt function __gcd(A, B);
        gcd = __gcd(A, B);

        lcm = (A*B)/gcd;
        
        // gcd or lcm push into vector
        v.push_back(lcm);
        v.push_back(gcd);

        return v;

    }
};