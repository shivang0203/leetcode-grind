class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        string temp;
        for( int i = 0; i < n; i++ ){
            if( temp.size() < k ){
                temp += s[ i ];
            }
            else{
                ans.push_back( temp );
                temp = s[ i ];
            }
        }
        while( temp.size() != 0 && temp.size() != k ) temp += fill;
        if( temp.size() == k ) ans.push_back( temp );
        return ans;
    }
};