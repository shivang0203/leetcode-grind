class Solution {
public:
    int f(vector<vector<int>>& v, int (&dp)[51][51][51], int n, int r1, int c1, int c2){
        int r2 = r1 + c1 - c2;
        if(r1>=n || r2 >=n || c1 >=n || c2>=n || v[r1][c1] == -1 || v[r2][c2] == -1)
            return -1e8;
        if(r1==n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1)
            return v[r1][c1];
        if(dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];
        
        int ans = 0;
        if(r1==r2 && c1 == c2)
            ans += v[r1][c1];
        else
            ans += v[r1][c1] + v[r2][c2];
        int a1 = f(v, dp, n, r1+1, c1, c2);
        int a2 = f(v, dp, n, r1, c1+1, c2+1);
        int a3 = f(v, dp, n, r1+1, c1, c2+1);
        int a4 = f(v, dp, n, r1, c1+1, c2);
        ans += max({a1, a2, a3, a4});
        return dp[r1][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& v) {
        int n = v.size();
        int dp[51][51][51];
        memset(dp, -1, sizeof(dp));
        int ans = f(v, dp, n, 0, 0, 0);
        ans = max(ans, 0);
        return ans;
    }
};