class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0;
        int left=0;
        int maxLength=0;
        int zeros=0;
        
        while(right<nums.size()){
            if(nums[right]==0){
                zeros++;
            }

            while(zeros>k){  // if number of zeros have exceeded 'k', we kept on moving 'left' till number of zeros came under control.
                if(nums[left]==0){
                    zeros--;
                    
                }
                left++;
            }
            if(zeros<=k){
            int length=right-left+1;
            maxLength=max(maxLength,length);
            
            }
            right++;

        }
        return maxLength;
    }
};