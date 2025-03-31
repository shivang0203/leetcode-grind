class Solution {
public:
 int solve(vector<vector<int>>& m, int i, int j, vector<vector<int>>& dp) {
        int n = m.size();
        int mn = m[0].size();

        if (i >= n || j >= mn || m[i][j] == 0) 
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        int right = solve(m, i, j + 1, dp);
        int dia = solve(m, i + 1, j + 1, dp);
        int down = solve(m, i + 1, j, dp);

        return dp[i][j] = 1 + min({right, dia, down});
    }
    int countSquares(vector<vector<int>>& m) {
         int n = m.size();
        int mn = m[0].size();
        vector<vector<int>> dp(n, vector<int>(mn, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mn; j++) {
                ans += ( solve(m, i, j, dp));
            }
        }

        return ans ;
    }
};