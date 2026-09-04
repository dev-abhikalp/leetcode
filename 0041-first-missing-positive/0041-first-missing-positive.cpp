class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool contains1 = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                contains1 = true;
            }

            if (nums[i] <= 0 || nums[i] > n) { // [1, n]
                nums[i] = 1;
            }
        }

        if (contains1 == false) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            int idx = num - 1;

            // Mark the number as present
            nums[idx] = -abs(nums[idx]);
        }

        // first positive value
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};