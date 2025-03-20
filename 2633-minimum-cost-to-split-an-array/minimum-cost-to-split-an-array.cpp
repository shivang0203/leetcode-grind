class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        vector<int> dp(nums.size() + 1, 0);
        reverse(nums.begin(), nums.end());
        nums.push_back(-1);
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            int s = 0, ans = 1e8;
            unordered_map<int, int> mp;
            for (int j = i; j > 0; j--) {
                if (mp[nums[j]] > 0) {
                    s++;
                    if (mp[nums[j]] == 1) {
                        s++;
                    }
                }
                mp[nums[j]]++;
                ans = min(ans, dp[j - 1] + s);
            }
            dp[i] = ans + k;
        }
        return dp[nums.size() - 1];
    }
};