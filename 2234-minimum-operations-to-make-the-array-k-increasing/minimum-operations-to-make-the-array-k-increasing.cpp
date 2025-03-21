class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = arr.size();
        for (int i = 0; i < k; i++) {
            vector<int> tails;
            for (int j = i; j < arr.size(); j += k) {
                if (tails.size() == 0 or arr[j] >= tails[tails.size() - 1]) {
                    tails.push_back(arr[j]);
                } else {
                    tails[upper_bound(tails.begin(), tails.end(), arr[j]) -
                          tails.begin()] = arr[j];
                }
            }
            ans -= tails.size();
        }
        return ans;
    }
};