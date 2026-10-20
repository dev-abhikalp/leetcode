
class Solution {
public:
    // Checks whether a is a cyclic rotation of b using KMP
    bool isRotation(vector<int>& a, vector<int>& b) {
        int m = a.size();

        if (m != (int)b.size()) return false;
        if (m == 0) return true;

        // Build the KMP LPS array for a
        vector<int> lps(m, 0);

        for (int i = 1, len = 0; i < m; ) {
            if (a[i] == a[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search for a in b + b, without constructing b + b
        int i = 0, j = 0;

        while (i < 2 * m - 1) {
            int value = b[i % m];

            if (value == a[j]) {
                i++;
                j++;

                if (j == m) return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            // Check every block of size k
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(
                    nums.begin() + start,
                    nums.begin() + start + k
                );

                vector<int> vec2(
                    sorted.begin() + start,
                    sorted.begin() + start + k
                );

                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                result += k;
        }

        return result;
    }
};
