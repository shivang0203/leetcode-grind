class Solution {
public:
    bool canrob(int mid,vector<int> &nums,int k){
        int count=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int left=1;
        int right= *max_element(nums.begin(),nums.end());
        int ans=right;
        while(left<=right){
            int mid=left +(right-left)/2;
            if(canrob(mid,nums,k)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }

        }
        return ans;
    }
};