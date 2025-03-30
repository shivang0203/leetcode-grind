class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int> > isPalin(n, vector<int> (n));
        for(int i = 0; i < n; i++) isPalin[i][i] = 1;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) isPalin[i][i+1] = 1;
        }
        for(int L = 3; L <= n; L++){
            for(int i = 0; i <= n-L; i++){
                int j = i+L-1;
                if(isPalin[i+1][j-1] == 0) continue;
                if(s[i] == s[j]) isPalin[i][j] = 1;
            }
        }
        vector<int> dp(n+1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            bool f = 0;
            for(int j = i - k; j >= 0; j--){
                if(isPalin[j][i-1]) f = 1;
                if(f) dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};