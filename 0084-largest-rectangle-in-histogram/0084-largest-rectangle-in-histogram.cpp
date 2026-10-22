
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> st;

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        // Clear the stack
        while (!st.empty()) {
            st.pop();
        }
        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        int maxRect = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int currArea = heights[i] * width;
            maxRect = max(maxRect, currArea);
        }
        return maxRect;
    }
};
