class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sum = 0, maxLength = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            bool isTurbulent = (i == 0) || (i % 2 == 0 ? arr[i - 1] < arr[i]
                                                       : arr[i - 1] > arr[i]);
            if (isTurbulent) {
                sum++;
            } else {
                sum = 1;
            }
            maxLength = max(maxLength, sum);
        }

        sum = 0;
        for (int i = 0; i < n; ++i) {
            bool isTurbulent = (i == 0) || (i % 2 != 0 ? arr[i - 1] < arr[i]
                                                       : arr[i - 1] > arr[i]);
            if (isTurbulent) {
                sum++;
            } else {
                sum = 1;
            }
            maxLength = max(maxLength, sum);
        }

        return maxLength;
    }
};