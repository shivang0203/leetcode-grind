class Solution {
public:
    vector<int> a;
    int n;
    vector<vector<int>> dp;
    int fun(int l,int r){
        if (l>r) return 0;
        if (dp[l][r]!=-1) return dp[l][r];
        int first = a[l] + min(fun(l+1,r-1),fun(l+2,r));
        int last = a[r] + min(fun(l+1,r-1),fun(l,r-2));
        
        return dp[l][r] =max(first,last);


    }
    bool predictTheWinner(vector<int>& nums) {
        n =nums.size();
        a =nums;
        dp.resize(n,vector<int>(n,-1));
        int first =fun(0,n-1);
        
        int sec = accumulate(begin(a),end(a),0)-first;
        return first>=sec;

    }
};