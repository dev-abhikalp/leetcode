class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        vector<pair<long long,int>> events;

        for(auto &interval : intervals) {
            events.push_back({interval[0], 1});
            events.push_back({interval[1], -1});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        long long active = 0;
        long long ans = 0;

        for(auto &event : events) {
            if(event.second == 1) {
                ans += active;
                active++;
            }
            else {
                active--;
            }
        }

        return ans;
    }
};