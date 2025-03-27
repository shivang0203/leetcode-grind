class Solution {
public:
    bool isAlternating(vector<int>& nums, int i, int l) {
        int distance = i - l;
        if (distance % 2 == 1) {
            if (nums[i] - nums[l] == 1 && nums[l + 1] - nums[l] == 1)
                return true;
            return false;
        } 
        else {
            return nums[i] - nums[l] == 0;
        }
    }

    int alternatingSubarray(vector<int>& nums) {
        int maxLength = 0;
        int l = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            while (!isAlternating(nums, i, l)) {
                l++;
            }
            maxLength = max(maxLength, i - l + 1);
        }
        return (maxLength <= 1) ? -1 : maxLength;
    }
};