class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<bool> v(target + 1, false);
        v[0] = true;  
        for(int num : nums){
            for (int j = target; j >= num; j--) { 
                v[j] = v[j] || v[j - num];
            }
        } 
        return v[target];
    }
};