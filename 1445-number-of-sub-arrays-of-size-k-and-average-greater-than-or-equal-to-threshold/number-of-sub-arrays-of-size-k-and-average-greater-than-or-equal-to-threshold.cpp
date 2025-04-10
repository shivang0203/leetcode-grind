class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        if (nums.size()<k) return 0;
        int sum = 0;
        int left = 0;
        int cnt = 0;

        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(right-left+1==k){
                if(sum>=k*threshold) cnt++;
                sum -= nums[left];
                left++;
            }
        }

        return cnt;
    }
};