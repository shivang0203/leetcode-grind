class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                double ans = (arr[i] * 1.0) / (arr[j] * 1.0);
                pq.push({ans, {i, j}});
            }
        }
        while (k > 1) {
            pq.pop();
            k--;
        }
        int i = arr[pq.top().second.first];
        int j = arr[pq.top().second.second];
        return {i, j};
    }
};