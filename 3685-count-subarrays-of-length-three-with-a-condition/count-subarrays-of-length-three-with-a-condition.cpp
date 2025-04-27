class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int count=0;
        for(int i=1;i<n-1;i++){
            sum +=nums[i+1];
            if(nums[i]/2==sum && abs(nums[i])%2 != 1)count++;
            sum = sum-nums[i-1] +nums[i]-nums[i+1];
        }
        return count;
    }
};