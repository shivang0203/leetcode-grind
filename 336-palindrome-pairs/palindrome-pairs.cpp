class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    string reverseString(const string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> wordMap;
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int len = word.size();
            for (int j = 0; j <= len; j++) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);
                if (isPalindrome(prefix, 0, prefix.size() - 1)) {
                    string revSuffix = reverseString(suffix);
                    if (wordMap.find(revSuffix) != wordMap.end() &&
                        wordMap[revSuffix] != i) {
                        res.push_back({wordMap[revSuffix], i});
                    }
                }
                if (!suffix.empty() &&
                    isPalindrome(suffix, 0, suffix.size() - 1)) {
                    string revPrefix = reverseString(prefix);
                    if (wordMap.find(revPrefix) != wordMap.end() &&
                        wordMap[revPrefix] != i) {
                        res.push_back({i, wordMap[revPrefix]});
                    }
                }
            }
        }

        return res;
    }
};