class Solution {
public:
     const int mod = 1e9 + 7;
     int fun(int i,int j,vector<vector<int>> & grid,int remen,int k,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int  m = grid[0].size();
        if(i==(n-1) && j==(m-1)){
            if((grid[i][j]%k+remen)%k== 0){
                return 1;
            }
            else{
                return 0;
            }
        }
       if(dp[i][j][remen]!=-1){
        return dp[i][j][remen];
       }
        int rem = grid[i][j]%k;
        int b=0,r=0;
        if(i+1<n){
        b =fun(i+1,j,grid,(rem+remen)%k,k,dp);
        }
        if(j+1<m){
          r = fun(i,j+1,grid,(rem+remen)%k,k,dp);
        }
       
        dp[i][j][remen] = (b+r)%mod;
        return dp[i][j][remen];
     }
    int numberOfPaths(vector<vector<int>>& grid, int k){
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return fun(0,0,grid,0,k,dp)%mod;
    }
};