class Solution {
public:
    int dp[102][102];
    int solve(int i, int j,string s) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 1 + solve(i + 1, j, s);
        for (int groupidx = i + 1; groupidx <= j; groupidx++) {
            if (s[groupidx] == s[i]) {
                ans = min(ans, solve(i + 1, groupidx - 1, s) +
                                   solve(groupidx, j, s));
            }
        }
        return dp[i][j] = ans;
    }
   
    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n- 1, s);

    }
};