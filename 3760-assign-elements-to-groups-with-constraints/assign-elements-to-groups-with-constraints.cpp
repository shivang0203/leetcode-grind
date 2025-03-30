class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size(), defaultIdx = -1;
        int maxSize = *max_element(groups.begin(), groups.end());

        vector<int> sieve(maxSize+1, defaultIdx);
        
        for (int i = 0; i < elements.size(); ++i) {
            int element = elements[i];
            if (element == 1) {
                defaultIdx = i;
                break;
            }

            if (element > maxSize or sieve[element] != -1) {
                continue;
            }

            for (int val = element; val <= maxSize; val += element) {
                if (sieve[val] == -1) {
                    sieve[val] = i;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int groupSize = groups[i];
            result.push_back(sieve[groupSize] == -1 ? defaultIdx : sieve[groupSize]);
        }
        return result;
    }
};