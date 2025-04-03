class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int range = nums[0];
        for(int num:nums){
            range=max(num,range);
        }
        int i=0,j=range;
        while(i < j){
            int mid = (i+j)/2;
            int m=0,n=1;
            int count = 0;
            while(n < nums.size()){
                while(nums[n] - nums[m] > mid){
                    m++;
                }
                count+=n-m;
                n++;
            }
            if(count >= k){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return i;                
    }
};