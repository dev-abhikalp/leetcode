class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1 ;// '1111111' all bits sets
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]!=i){// misplaced 
                k = (k & nums[i]);
            }
        }
        return k==-1?0:k;
    }
};