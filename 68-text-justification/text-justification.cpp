class Solution {
public:
    vector<int> distributeSpaces(int spaceCnt,int wordsCnt){
        --wordsCnt;

        if(wordsCnt==0){
            vector<int> ans;
            ans.push_back(spaceCnt);
            return ans;
        }
        int base=spaceCnt/wordsCnt;
        int extra=spaceCnt%wordsCnt;
        vector<int> ans(wordsCnt,base);
        for(int i=0;i<extra;i++){
            ++ans[i];
        }
        return ans;
    }
    string getSpaceString(int cnt){
        string s="";
        for(int i=0;i<cnt;i++){
            s.push_back(' ');
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int idx=0;
        while(idx<words.size()){
            int start=idx;
            int end=idx;
            int currLength=0;
            while(end<words.size()){
                // end++;
                int t=0;
                if(end>start) t=1;
                currLength+=t+words[end].size();
                if(currLength>maxWidth){
                    break;
                }
                // cout<< currLength<<" "<<end<<":";
                end++;
            }
            
            // cout<<currLength<<" "<<end<<"\n";
            int totalWordCount=0;
            for(int cnt=start;cnt<end;cnt++){
                totalWordCount+=words[cnt].size();
                // cout<<totalWordCount<<" ";
            }
            // cout<<totalWordCount<<" ";
            int spaceCnt=maxWidth-totalWordCount;
            vector<int> spaces=distributeSpaces(spaceCnt,end-start);
            string line="";
            for(int cnt=start;cnt<end;cnt++){
                line.append(words[cnt]);
                if(cnt-start<spaces.size()){
                    line.append(getSpaceString(spaces[cnt-start]));
                }
            }
            if(end>=words.size()){
                line="";
                line.append(words[start]);
                for(int cnt=start+1;cnt<end;cnt++){
                    line.append(" ");
                    line.append(words[cnt]);
                }
                line.append(getSpaceString(maxWidth-line.size()));
            }
            ans.push_back(line);
            idx=end;
        }
        return ans;
    }
};