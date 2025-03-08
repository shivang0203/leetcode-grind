class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int n = blocks.length();
        int left = 0; 
        int whiteCount = 0; 
        int minOperations = INT_MAX; 

        for (int right = 0; right < n; right++) {
            if (blocks[right] == 'W') whiteCount++;

            if (right - left + 1 == k) {
                minOperations = min(minOperations, whiteCount);

                // Move the left pointer forward
                if (blocks[left] == 'W') whiteCount--;
                
                left++;
            }
        }

        return minOperations;
    }
};