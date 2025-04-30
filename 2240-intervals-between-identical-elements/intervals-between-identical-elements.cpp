class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> result(arr.size(), 0);

        unordered_map<int, vector<int>> occurrences;
        for (int i = 0; i < arr.size(); ++i) {
            occurrences[arr[i]].push_back(i);
        }

        for (auto& pair : occurrences) {
            vector<int>& indices = pair.second;
            int size = indices.size();

            long long sum = 0;

            for (int index : indices) {
                sum += index;
            }

            long long prefixSum = 0;
            for (long long i = 0; i < size; i++) {
                int index = indices[i];

                result[index] = (index * i - prefixSum) +
                                (sum - prefixSum - index) -
                                (size - i - 1) * index;
                prefixSum += index;
            }
        }
        return result;
    }
};
