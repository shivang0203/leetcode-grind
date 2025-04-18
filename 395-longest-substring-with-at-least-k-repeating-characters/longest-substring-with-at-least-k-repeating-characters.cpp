class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();

        int len = 0;
        for (int i = 1; i <= 26; i++) {
            int unique = 0;
            int l = 0, r = 0;
            int count = 0;
            unordered_map<char, int> mpp;
            while (r < n) {
                if (mpp[s[r]] == 0)unique++;
                mpp[s[r]]++;
                if (mpp[s[r]] == k)count++;
                while (unique > i) {
                    if (mpp[s[l]] == k)count--;
                    mpp[s[l]]--;
                    if (mpp[s[l]] == 0)unique--;
                    l++;
                }
                if (unique == count) {
                    len = max(len, r - l + 1);
                }
                r++;
            }
        }
        return len;
    }
};