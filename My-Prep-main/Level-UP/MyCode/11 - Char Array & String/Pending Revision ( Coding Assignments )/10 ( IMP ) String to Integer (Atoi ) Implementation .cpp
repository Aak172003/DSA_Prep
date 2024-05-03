/*
LeetCode Link - https://leetcode.com/problems/string-to-integer-atoi/description/

Youtube Link -  https://youtu.be/qZoFJKyHQ98

TC-O(N)
SC-O(N)

*/

class Solution {
public:
    int myAtoi(string s) 
    {
        /*
        Step1 - Ignore Leading white Space 
        Step2 - Identify Sign whether is +ve or -ve 
        Step3 - If digit foun after finding sign 
                then prepare an integer 
        Step4 - Till next non-digit character is found 
        Step5 - Special Hadling -> if num is out of bound 
        */

        if(s.length()==0)return 0;
        int i=0;
        
        while(i<s.size()&& s[i]==' '){
            i++;
        }
        // so when after ignoring leading white spaces , so we focus only from 
        // i after ignore jaha paucha vaha se string ki end tkk
        // then usko s me daal denge after removing leading white spaces 

        s=s.substr(i);  // i iterate to the last character 
        
        int sign=+1;
        long ans=0;
        
        
        if(s[0]=='-')sign=-1;
        
        int MAX=INT_MAX;
        int MIN=INT_MIN;
        
        // means agr "+" , "-" occur hota hai to hum i just uske aage se iterate kreneg 
        // or agr leading spaces ke bdd just integer hai to i = 0 se iterate krenge
        i=(s[0]=='+'|| s[0]=='-')?1:0;
        
        // i iterate until s is not end 
        while(i<s.length())
        {
        // if after -ve sign then uske bdd agr space or non-digit aae to hum break kr jaenge 
            if(s[0]==' ' || !isdigit(s[i]))break;
            // ans meadd krna integer value ko string me se 
            ans=ans*10+s[i]-'0';
            
            // if sign is -ve , so if ans < INT_MIN means out of bound , so return INT_MIN
            if(sign==-1 && -1*ans<MIN)return MIN;
            // if sign is +ve , so if ans > INT_MAX means out of bound , so return INT_MAX
            if(sign==1 && ans>MAX)return MAX;
            
            i++;
        }

        return(int)(sign*ans);
        
    }
};