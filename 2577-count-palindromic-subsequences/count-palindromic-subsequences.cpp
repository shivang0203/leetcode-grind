class Solution {
public:
    int dp[10001][5][100];
    const int M = 1e9+7;
    int solve(int i, int n, int cnt, int hash, string& s){
        if(cnt == 5){
            return 1;
        }
        if(cnt >= 5) return dp[i][cnt][hash] = 0;
        if(i == n) return dp[i][cnt][hash] = 0;

        if(dp[i][cnt][hash] != -1) return dp[i][cnt][hash];

        long long ans = 0;
        ans += solve(i+1, n, cnt, hash, s);
        ans %= M;
        int digit = s[i] - '0';
        if(cnt < 2){
            ans += solve(i+1, n, cnt+1, hash*10+digit, s);
        }
        else if(cnt == 2){
            ans += solve(i+1, n, cnt+1, hash, s);
        }
        else{
            if(cnt == 3){
                if(digit == (hash % 10)) ans += solve(i+1, n, cnt+1, hash, s); 
            }
            else if(cnt == 4){
                if(digit == (hash / 10)) ans += solve(i+1, n, cnt+1, hash, s);
            }
        }
        return dp[i][cnt][hash] = ans % M;
    }
    int countPalindromes(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, 0, 0, s);
    }
};