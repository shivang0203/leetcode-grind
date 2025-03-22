class Solution {
public:
    bool solve(vector<long long> nums, int n) {
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] > n)
                nums[i - 1] += (nums[i] - n);
        }

        return (nums[0] <= n);
    }

    int minimizeArrayValue(vector<int>& nums) {
        vector<long long> n;
        for (auto i : nums)
            n.push_back(i);

        int l = 0, r = 1e9;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(n, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};