struct Node {
    Node *links[26];
    int precnt = 0;
    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        return links[ch - 'a']; 
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node; 
    }
    void setpre() {
        precnt++;
    }
    int getpre() { 
        return precnt;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->setpre(); 
        }
    }
    int searchPrefixScore(string word) {
        Node *node = root;
        int ans = 0;
        for (char ch : word) {
            node = node->get(ch);
            if (!node) break;
            ans += node->getpre(); 
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for (auto &word : words) {
            t.insert(word);
        }
        vector<int> ans(words.size());
        for (int i = 0; i < words.size(); i++) {
            ans[i] = t.searchPrefixScore(words[i]);
        }
        return ans;
    }
};