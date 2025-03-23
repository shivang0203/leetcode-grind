class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        stack<double> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && cars[s.top()][1] >= cars[i][1]) {
                s.pop();
            }
            while (!s.empty()) {
                double time = (double)(cars[s.top()][0] - cars[i][0]) /
                              (cars[i][1] - cars[s.top()][1]);
                if (ans[s.top()] == -1 || time <= ans[s.top()]) {
                    ans[i] = (time);
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};