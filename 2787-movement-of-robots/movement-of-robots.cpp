class Solution {
public:
    int mod=1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long int> ans;
        int n=nums.size();
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            if(s[i]=='L'){
                ans[i]=(ans[i]-d);
            }
            else{
                ans[i]=(ans[i]+d);
            }
        }
        long long int a=0;
        long long int pref=0;
        sort(ans.begin(), ans.end());
        for(int i=0; i<n; i++){
            a+=i*ans[i]-pref;
            a%=mod;
            pref+=ans[i];
        }
        return a;
    }
};