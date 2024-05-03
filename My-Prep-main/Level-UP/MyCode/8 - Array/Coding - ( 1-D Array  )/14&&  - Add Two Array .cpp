/*
CodeStudio Link - https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4&leftPanelTab=0
Love Bhaiya Video - Approach
*/

// Hamre vector me answe reverse order jaega ,
// two sahi answer paane ke lie usko reverse krna pdega

vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    while (s < e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

// starting from this function
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    // initailly point i and j to last index of both Given Array
    int i = n - 1;
    int j = m - 1;

    vector<int> ans;
    int carry = 0;
    int digit = 0;

    // tb ke lie jo dono i and j me value hai ,
    // or jb tk dono me se koi ek final tk na pauch gya hoo

    while (i >= 0 && j >= 0)
    {

        int sum = a[i] + b[j] + carry;

        carry = sum / 10;
        digit = sum % 10;

        ans.push_back(digit);
        i--;
        j--;
    }

    // if suppose 4 2 3 6
    //                  2

    //  in this case 6 + 2 hone ke bdd ab bs upr wale array me value pdi hai to hum bs usko add krte jaenge
    // if dono me se koi bhi apne last se me pauch gya to jis
    // array me last tk nhi pauche usko add krte jaenge

    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        digit = sum % 10;
        ans.push_back(digit);
        i--;
    }

    // second case
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit);
        j--;
    }

    //  if last me carry aaya h to usko sum me assign krke vector me push maar denge
    //  99 5 6
    //  3  4 5

    // isme last me carry 103 bnega , so 3 ko to hum sum krenge , baaki 10 bcha
    // usko hum jb tk carry 0 nhi hojata , tb tk hum usko ek ek krke piche se split krke vector me daal denge

    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        digit = sum % 10;
        ans.push_back(digit);
    }

    return reverse(ans);
}