class Solution {
public:
    vector<int> find(string str) {
        int n = str.size();
        vector<int> lps(n, 0);
        int j = 0;
        int i = 1;
        while (i < n) {
            if (str[i] == str[j]) {
                j++;
                lps[i] = j;
                i++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int minValidStrings(vector<string>& words, string target) {
        int n = words.size();
        vector<vector<int>> str;
        for (auto i : words) {
            str.push_back(find(i + "#" + target));
        }
        int len = target.size();
        int match = 0;
        while (len > 0) {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = max(ans, str[i][words[i].size() + len]);
            }
            if (ans == 0)
                return -1;
            match++;
            len -= ans;
        }
        return match;
    }
};