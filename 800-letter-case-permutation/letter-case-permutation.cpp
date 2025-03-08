class Solution {
public:
    void backtrack(vector<string> &ans,int i,string &s){
        if(i==s.size())ans.push_back(s);
        else{
            if (isalpha(s[i])) { 
                s[i] = toupper(s[i]);
                backtrack(ans, i + 1, s);

                s[i] = tolower(s[i]);
                backtrack(ans, i + 1, s);
            } else {
                backtrack(ans, i + 1, s);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        backtrack(ans,0,s);
        return ans;
    }
};