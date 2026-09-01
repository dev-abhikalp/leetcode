class MyCalendarTwo {
private:
    map<int, int> event;

public:
    MyCalendarTwo() {
    }

    bool book(int startTime, int endTime) {
        event[startTime]++;
        event[endTime]--;

        int overlaps = 0;
        for (auto &it : event) {
            overlaps += it.second;

            if (overlaps >= 3) {
                event[startTime]--;
                event[endTime]++;
                return false;
            }
        }
        return true;
    }
};