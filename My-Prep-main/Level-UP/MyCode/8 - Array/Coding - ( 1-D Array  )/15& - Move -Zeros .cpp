class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
    // Both Pointing To ist index value 
    int left = 0;  
	int right = 0;  
	while(left<=right && right < nums.size()) 
    {
		// if 0 pdega to right++ 
		if(nums[right] == 0) 
        {
			right++;
		}
		// otherwise swap left and rigth then left++ , right++
		else 
        {
            swap(nums[left],nums[right]);

			//  int temp = nums[left];
			//  nums[left] = nums[right];
			//  nums[right] = temp;
			left++;
			right++;
		}
	 } 
    }
};