class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int n = aliceValues.size();
        for (int i = 0; i < n; i++) {
            pq.push({aliceValues[i] + bobValues[i],
                     {aliceValues[i], bobValues[i]}});
        }

        bool flag = 0;
        int val = 0;

        while (!pq.empty()) {
            if (flag == 0) {
                val += pq.top().second.first;
            } else {
                val -= pq.top().second.second;
            }
            flag = !flag;
            pq.pop();
        }

        if (val == 0)
            return 0;
        if (val > 0)
            return 1;
        return -1;
    }
};