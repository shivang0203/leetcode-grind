class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {

        long long positive = 0;
        long long negative = 0;
        if (k == 0) {
            if (nums1 == nums2)
                return 0;
            else
                return -1;
        }

        for (int i = 0; i < nums1.size(); i++) {

            if ((nums1[i] - nums2[i]) % k == 0) {
                if (nums1[i] - nums2[i] > 0) {
                    positive += (nums1[i] - nums2[i]) / k;
                } else {
                    negative += abs((nums1[i] - nums2[i]) / k);
                }
            } else {
                return -1;
            }
        }
        if (positive != negative)
            return -1;
        return positive;
    }
};