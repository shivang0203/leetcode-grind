class Solution {
public:
    string SCS(string str1, string str2, int n, int m) {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string s = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                s.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    s.push_back(str2[j - 1]);
                    j--;
                }
                else {
                    s.push_back(str1[i - 1]);
                    i--;
                }
            }
        }
        while (i > 0) {
            s.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            s.push_back(str2[j - 1]);
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        return SCS(str1, str2, n, m);
    }
};