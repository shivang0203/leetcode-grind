class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        unordered_set<string> vis;
        vis.insert("0000");
        int turns=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr=q.front();q.pop();
                if(curr==target) return turns;
                for(int i=0;i<4;i++){
                    string next = curr;
                    next[i]=(next[i]=='9')?'0':next[i]+1;
                    if(!dead.count(next) && !vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                    next=curr;
                    next[i]=(next[i]=='0')?'9':next[i]-1;
                    if(!dead.count(next) && !vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};