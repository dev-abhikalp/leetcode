class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        int i=0;
        while(!nums.empty()){
            s.clear();
            for (int x : nums) {
                s.insert(x);
            }
            for(int it : s){
                ans.push_back(it);
            }
            for(int x : s){
                auto it = find(nums.begin(),nums.end() , x);
                if(it!=nums.end()){
                    nums.erase(it);
                }
            }
        }
        return ans;
    }
};