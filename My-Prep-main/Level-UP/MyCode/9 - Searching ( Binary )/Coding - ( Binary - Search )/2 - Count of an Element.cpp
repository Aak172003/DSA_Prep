/*
GFG Link - https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

*/

// Approch 1 ->   Linear Search
// TC - O(n)
// ek counter lo , linerarly traverse krte rho ,
// jaha se jaha tk wo element milta hai jisko hum search kr rhe hai so waha tk counter ko ++ krte chalenge

// Approch 1 ->   Binary  Search
// TC - O(logn)
class Solution
{
public:
	int findFirstOccurence(int arr[], int n, int x)
	{

		int low = 0;
		int high = n - 1;
		int firstcount = -1;

		while (low <= high)
		{
			int mid = low + (high - low) / 2;

			if (arr[mid] == x)
			{
				// if key ke equal mil jaata hai to hum us index ko
				// ans me store kr denge or phr left me search krna start
				// kyuki hume left most occurance nikalna hai
				firstcount = mid;
				high = mid - 1;
			}
			// if target ki jo value hai wo mid se bdi hai means hume right me search krna hai
			else if (arr[mid] < x)
			{
				low = mid + 1;
			}
			// Otherwise left me search krna hai
			else
			{
				high = mid - 1;
			}
		}
		return firstcount;
	}

	int findLastOccurence(int arr[], int n, int x)
	{

		int low = 0;
		int high = n - 1;
		int lastcount = -1;

		while (low <= high)
		{
			int mid = low + (high - low) / 2;

			// if key ke equal mil jaata hai to hum us index ko
			// ans me store kr denge or phr right me search krna start
			// kyuki hume right most occurance nikalna hai
			if (arr[mid] == x)
			{
				lastcount = mid;
				// search right side to find the last occurrence ,  right Wale array me search krenge
				low = mid + 1;
			}

			//  mid ki value agr choti hoti hai to hum , Right me check krenge
			else if (arr[mid] < x)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		return lastcount;
	}

	int count(int arr[], int n, int x)
	{
		// code here
		int first = findFirstOccurence(arr, n, x);

		int last = findLastOccurence(arr, n, x);
		// if dono me se koi bhi function hume -1 deta hai
		// iska mtlb us taraf koi element hi nhi hai hai means wo element hai hi nhi
		if (first == -1 || last == -1)
			return 0;
		else
			return last - first + 1;
	}
};
