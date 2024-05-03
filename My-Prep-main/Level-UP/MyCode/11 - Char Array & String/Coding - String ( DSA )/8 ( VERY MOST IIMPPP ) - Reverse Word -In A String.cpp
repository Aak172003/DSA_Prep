/*
LeetCode Link - https://leetcode.com/problems/reverse-words-in-a-string/submissions/888854442/

*/

class Solution
{
public:
	string reverseWords(string s)
	{

		//                                Appoach 1 - Use Tokenizer

		stringstream ss(s);
		string token = "";

		string result = "";
		// By default stringstream tokenizes on ' ' (space character)

		while (ss >> token)
		{

			result = token + " " + result;
		}

		result.pop_back();
		return result;

		/*

		// ********************************************************************************************************


		//                               Appoach 2 - Use Stack ( Extra Space )


		Time Complexity: O(N), Traversing the entire string
		Space Complexity: O(N), Stack and ans variable

		*/

		int n = s.size();
		stack<string> st;
		string temp = "";

		for (int i = 0; i < n; i++)
		{

			// until not find spaces add the character into temp
			// This is how we access seperate string from a big sentence , then push into stack

			if (s[i] != ' ')
				temp += s[i];

			// temp.size() > 0 ths condition is help when we takle with multiple spaces ,
			// leading spaces or , Trailing Spaces , in case of multiple spaces ,
			// we add into temp but its size not greater than 0 ,
			// so hum uko stack me daalenge jinka size > 0 hoo

			else if (temp.size() > 0)
			{
				st.push(temp);
				temp.clear();
			}
		}

		// Let's suppose this example -> "the sky is blue"
		// blue ke bdd space nhi mila, islea wo temp me hi rh gya ,

		// which means jb encounter space " " tb hum stack me dal rhe hai

		//  so hume usko last me temp se nikal kr
		// stack me daalna pdega

		// But in this example -> "  hello world  "
		// world ke bdd space hai that why wo automatically chal jaega
		if (temp.size() > 0)
			st.push(temp);

		s.clear();

		while (!st.empty())
		{
			// Add into string , jo phle clear kia hai
			s += st.top();
			// then remove
			st.pop();
			// Add space
			s += ' ';
		}
		// hum hr word daalne ke bd ek space daal rhe hai , means jn last word daalenge tb bhi to ek space jaega ,
		// usko remove bhi krna hai

		// At last we have a null character , so we need to remove last null Character from string
		s.pop_back();
		return s;

		// ********************************************************************************************************

		//                               Appoach 3 - Use Stack ( Extra Space )

		// story
		// 1. reverse whole string

		reverse(s.begin(), s.end());

		int i = 0;
		// hero honge hamare l and r jo revrese karenge words ko
		int l = 0, r = 0;

		int n = s.length();

		while (i < n)
		{
			while (i < n && s[i] != ' ')
			{
				// i ko agar char dikha to r ko dega and i++ and r++
				s[r] = s[i];
				i++, r++;
			}
			// if i found space

			if (l < r)
			{
				// l  b /w  r
				reverse(s.begin() + l, s.begin() + r);

				// Make a space
				s[r] = ' ';
				r++;

				l = r;
			}

			i++; // y eto badhta rahega
		}

		// at last me space is add
		s = s.substr(0, r - 1);

		return s;
	}
}