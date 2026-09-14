class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  x = 0;

        for (int num : nums) {
            x ^= num;
        }

        int bit = x & (-x);
        int a = 0;
        int b = 0;

        for (int num : nums) {
            if (num & bit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};