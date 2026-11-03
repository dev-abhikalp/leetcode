class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxEle=nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]>maxEle){
                maxEle=nums[i];
            }
        }
        long long  result=0;
        for(int i=0;i<n;i++){
            result+=maxEle-nums[i];
        }
        return result;
    }
};