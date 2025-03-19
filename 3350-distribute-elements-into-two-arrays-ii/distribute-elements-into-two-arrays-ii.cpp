class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums;
        }
        
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};

        vector<int> sorted1 = {nums[0]};
        vector<int> sorted2 = {nums[1]};
        
        for (int i = 2; i < nums.size(); i++) {
            int count1 = sorted1.size() - (upper_bound(sorted1.begin(), sorted1.end(), nums[i]) - sorted1.begin());

            int count2 = sorted2.size() - (upper_bound(sorted2.begin(), sorted2.end(), nums[i]) - sorted2.begin());
            
            if (count1 > count2) {
                arr1.push_back(nums[i]);
                auto pos = upper_bound(sorted1.begin(), sorted1.end(), nums[i]);
                sorted1.insert(pos, nums[i]);
            } else if (count2 > count1) {
                arr2.push_back(nums[i]);
                auto pos = upper_bound(sorted2.begin(), sorted2.end(), nums[i]);
                sorted2.insert(pos, nums[i]);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    auto pos = upper_bound(sorted1.begin(), sorted1.end(), nums[i]);
                    sorted1.insert(pos, nums[i]);
                } else {
                    arr2.push_back(nums[i]);
                    auto pos = upper_bound(sorted2.begin(), sorted2.end(), nums[i]);
                    sorted2.insert(pos, nums[i]);
                }
            }
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};