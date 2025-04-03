class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();

        vector<long long>prefix_max(n);
        
        prefix_max[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix_max[i]=max(prefix_max[i-1],1LL*nums[i]);
        }

        vector<long long>suffix_max(n);
        suffix_max[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_max[i]=max(suffix_max[i+1],1LL*nums[i]);
        }

        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(prefix_max[i-1]-1LL*nums[i])*suffix_max[i+1]);
        }
        return ans;
    }
};