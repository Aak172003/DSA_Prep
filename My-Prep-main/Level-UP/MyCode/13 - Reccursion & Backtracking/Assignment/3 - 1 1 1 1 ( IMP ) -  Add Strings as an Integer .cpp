/*

Link - https://leetcode.com/problems/add-strings/description/

*/

//                Approach - 1 Using Built - in Functions

// stoi -> string to integer conversion
// to_string -> integer to string conversion

// int main()
// {
//     int n1 = stoi(num1);
//     int n2 = stoi(num2);
//     int sum = n1 + n2;
//     string ans = to_string(sum);

//     cout<<"Ans is :"<<ans<<endl;
// }

//               Approach - 2 Using Reccursion

class Solution
{
public:
    string addChar(string num1, int p1, string num2, int p2, int carry = 0)
    {
        // Base Case

        if (p1 < 0 && p2 < 0)
        {
            if (carry != 0)
            {
                // Create 1 length ka string , or usme carry + '0' krke integer value daal dia
                return string(1, carry + '0');
            }
            // if carry nhi hota
            return "";
        }

        // Solve 1 case

        // jb tk p1 >= hota hai 0 se ,
        // tb tk mujhe num1[p1] dedo otherwise 0 de do
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

        int sum = n1 + n2 + carry;
        // extract digit
        int digit = sum % 10;
        // extract carry
        carry = sum / 10;

        // create string ans naam ki
        string ans = "";
        // ans me digit ko daal dene ka with + '0' krke to make char value
        ans.push_back(digit + '0');

        ans = ans + addChar(num1, p1 - 1, num2, p2 - 1, carry);
        return ans;
    }
    string addStrings(string num1, string num2)
    {

        int l1 = num1.size();
        int l2 = num2.size();

        // l1-1 -> pointer on num1 string ki last character pr
        // l2-1 -> pointer on num2 string ki last character pr
        string ans = addChar(num1, l1 - 1, num2, l2 - 1);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//                               Optimised in terms of Memory Utilisation , and in terms of Run Time

/*
    copy pss krne me Jbki hum jante hai ki reccursion means br br call ,
    so if we pass copy , so memeory space faltu consumes krta hai , or

    // run time bhi slow ho jata hai , kyuki jb jb reccursion call hoga tb tb new copy bnega ,
    so  that why we pass by reference
    ans ko bhi hum pass by reference krte hai

    Reccursion ki problems me pass by reference is better than pass by copy
*/

class Solution
{
public:
    void addChar(string &num1, int p1, string &num2, int p2, int carry, string &ans)
    {
        // Base Case
        if (p1 < 0 && p2 < 0)
        {
            if (carry != 0)
            {
                ans.push_back(carry + '0');
            }
            return;
        }

        // Solve 1 case

        // jb tk p1 >= hota hai 0 se ,
        // tb tk mujhe num1[p1] dedo otherwise 0 de do
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

        int sum = n1 + n2 + carry;
        // extract digit
        int digit = sum % 10;
        // extract carry
        carry = sum / 10;

        // ans me digit ko daal dene ka with + '0' krke to make char value
        ans.push_back(digit + '0');

        addChar(num1, p1 - 1, num2, p2 - 1, carry, ans);
    }

    string addStrings(string num1, string num2)
    {
        // Using Reccursion
        int l1 = num1.size();
        int l2 = num2.size();
        int carry = 0;

        string ans = "";

        addChar(num1, l1 - 1, num2, l2 - 1, carry, ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};