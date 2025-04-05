class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i=0;i<n+1; i++){
            dp[i][0]=0;
        }
        for(int i=0;i<m+1; i++){
            dp[0][i]=0;
        }
        for(int ind1=1; ind1<n+1; ind1++){
            for(int ind2=1; ind2<m+1; ind2++){
                if(word1[ind1-1]==word2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
                }
            }
        }
        int lcs=dp[n][m];
        int ans=(n-lcs)+(m-lcs);
        return ans;
    }
};