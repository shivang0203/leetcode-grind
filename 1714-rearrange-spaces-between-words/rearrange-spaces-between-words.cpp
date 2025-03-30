class Solution {
public:
    string reorderSpaces(string text) {
        stringstream ss(text);
        vector<string> word;
        string words;

        while (ss >> words) {
            word.push_back(words);
        }

        int count = 0;
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') {
                count++;
            }
        }

        int n = word.size();

        string answer = "";
        if (n == 1) {
            answer += word[0];
            for (int j = 1; j <= count; ++j) {
                answer.push_back(' ');
            }
            return answer;
        }
        int space = count / (n - 1);
        int left = count - ((n - 1) * space);

        for (int i = 0; i < word.size(); ++i) {
            answer += word[i];

            if (i != word.size() - 1) {
                for (int j = 0; j < space; ++j) {
                    answer.push_back(' ');
                }
            }
        }
        for (int j = 1; j <= left; ++j) {
            answer.push_back(' ');
        }

        return answer;
    }
};