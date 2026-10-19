class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int cnt=0;
        int targetCnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                cnt++;
            }
            else if(nums[i]==target){
                targetCnt++;
            }
        }
        cnt=cnt-1;
        while(targetCnt>0){
            ans.push_back(cnt+1);
            cnt=cnt+1;
            targetCnt--;
        }
        return ans;
    }
};