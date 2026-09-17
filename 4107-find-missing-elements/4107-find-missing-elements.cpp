class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];

        vector<bool> present(101, false);

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
            present[x] = true;
        }

        vector<int> ans;

        for (int x = mn + 1; x < mx; x++) {
            if (!present[x]) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};