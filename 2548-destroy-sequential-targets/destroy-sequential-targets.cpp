class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, vector<int>> mp;
        int mx = 0, ans = 0;
        for (auto& i : nums) {
            if (mp.count(i % space) == 0) {
                mp[i % space] = {1, i};
            } else {
                mp[i % space][0]++;
                mp[i % space][1] = min(i, mp[i % space][1]);
            }
            if (mp[i % space][0] > mx) {
                mx = mp[i % space][0];
                ans = mp[i % space][1];
            }
            if (mp[i % space][0] == mx) {
                ans = min(ans, mp[i % space][1]);
            }
        }
        return ans;
    }
};