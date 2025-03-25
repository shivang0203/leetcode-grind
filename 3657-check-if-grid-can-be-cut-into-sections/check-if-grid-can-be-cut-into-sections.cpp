class Solution {
public:
    bool check(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int sections = 0;
        int max_end = intervals[0][1];

        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            if (max_end <= start) {
                sections++;
            }
            max_end = max(max_end, end);
        }

        return sections >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xIntervals, yIntervals;

        for (auto& rect : rectangles) {
            xIntervals.push_back({rect[0], rect[2]});
            yIntervals.push_back({rect[1], rect[3]});
        }

        return check(xIntervals) || check(yIntervals);
    }
};