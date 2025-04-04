class Solution {
public:
    int count(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != 0) return dp[i][j];

        int num=0;
        if(s[i] == s[j]){
            num = 2 * count(i+1,j-1,s,dp);

            int l=i+1,r=j-1;
            while(l<=r && s[l]!=s[i]) l++;
            while(l<=r && s[r]!=s[i]) r--;

            if(l<r) num -= count(l+1,r-1,s,dp);
            else if(l == r ) num += 1;
            else num += 2;
        }
        else{
            num = count(i+1,j,s,dp) + count(i,j-1,s,dp) - count (i+1,j-1,s,dp);
        }

        dp[i][j] = (num < 0) ? num + 1000000007 : num % 1000000007;
        return dp[i][j];
    }
    int countPalindromicSubsequences(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return count(0,n-1,s,dp);
    }
};