class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> mn(nums.size(), nums.back());
        for(int i = nums.size() - 2;i >= 0;i--) mn[i] = min(nums[i], mn[i + 1]);
        
        int mx = 0;
        for(int i = 0;i < nums.size();i++){
            mx = max(mx, nums[i]);
            if(mx <= mn[i + 1]) return i + 1;
        }

        return 0;
    }
};