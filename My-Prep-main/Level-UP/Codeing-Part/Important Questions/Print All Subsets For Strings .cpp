/*
Coding Ninja Link - https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16
*/

//             Logic Same as Print All Subsets For Array
#include <bits/stdc++.h> 
// During Function Calling yaha hume original wo wala vector bhejna pdega jisme final answer store hoga 
void solve(string str ,string ans , int index,vector<string>& result)

{
	// Agr index hamara traverse krte krte array size se bahar so return 
	if(index>=str.length())
	{
		// means is Question me empty size ka sub array output me nhi dena hai 
		if(ans.length()>0)
		{
			// jb jb 
			result.push_back(ans);
		}
		return;
	}
    
	// excluding the element
	solve(str,ans,index+1,result);
    
	// including the Element 
	// string ke case me char lekr kaam krna hai 
	char element = str[index];
	ans.push_back(element);

	solve(str,ans,index+1,result);

}
vector<string> subsequences(string str)
{

	vector<string>result;
	// string ke case me empty string lena hai , or array ke case me ek vector lena hai 
	string ans = "";
	int index = 0;

	solve(str,ans,index,result);
	return result ;
	
}
