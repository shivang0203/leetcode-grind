class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto i : words)mp[i]++;
        bool flag = false;
        int ans = 0;
        for (auto i : mp) {
            string temp = i.first;
            reverse(temp.begin(), temp.end());
            if (temp == i.first and i.second % 2 != 0 and flag == false) {
                flag = true;
                ans += 2;
                mp[temp]--;
            }
            if (mp.find(i.first) != mp.end() and mp.find(temp) != mp.end()) {
                if (i.first != temp) {
                    ans += min(mp[i.first], mp[temp]) * 2 * 2;
                    mp[i.first] = mp[temp] = 0;
                } else {
                    ans += mp[temp] / 2 * 2 * 2;
                    mp[i.first] = mp[temp] = 0;
                }
            }
        }
        return ans;
    }
};