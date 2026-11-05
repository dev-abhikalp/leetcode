class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;

        for (int x : arr1) {
            int left = 0, right = arr2.size() - 1;
            bool valid = true;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (abs(x - arr2[mid]) <= d) {
                    valid = false;
                    break;
                }
                else if (arr2[mid] < x) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (valid)
                count++;
        }
        return count;
    }
};