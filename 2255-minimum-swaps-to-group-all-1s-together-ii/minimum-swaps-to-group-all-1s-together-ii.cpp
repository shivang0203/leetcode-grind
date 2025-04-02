class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                k++;
        }
        int s = 0, e = 0;
        int one = 0, maxi = 0;
        while (e < (n + k)) {
            if (e < k) {
                if (nums[e] == 1)
                    one++;
            } else {
                if (nums[e % n] == 1)
                    one++;
                if (nums[s] == 1)
                    one--;
                s++;
            }
            maxi = max(maxi, one);
            e++;
        }
        return k - maxi;
    }
};