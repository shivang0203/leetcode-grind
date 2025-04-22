class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size() ;
        long long count = 0 ;
        unordered_map<int,int> mp ;
        int curr = 0 ;
        for(int i=0;i<n;i++){
            curr^=nums[i];
            if(curr==0) count++ ;
            if(mp.find(curr)!=mp.end()){
                count+=mp[curr] ;
            }
            mp[curr]++ ;
        }
        return count;
    }
};