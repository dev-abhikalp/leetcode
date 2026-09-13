class Solution {
public:

    int countoverlaps(vector<vector<int>>& A,
                      vector<vector<int>>& B,
                      int row_off,
                      int col_off) {

        int n = A.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int new_row = i + row_off;
                int new_col = j + col_off;

                if (new_row >= 0 && new_row < n &&
                    new_col >= 0 && new_col < n) {

                    if (A[i][j] == 1 && B[new_row][new_col] == 1) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        for (int row_off = -n + 1; row_off < n; row_off++) {
            for (int col_off = -n + 1; col_off < n; col_off++) {

                ans = max(ans,
                          countoverlaps(img1, img2,
                                        row_off, col_off));
            }
        }

        return ans;
    }
};