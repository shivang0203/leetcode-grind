class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        map<int,int>mpp;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it: restricted){
            mpp[it]++;
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            vis[node]=1;     
            q.pop();
            for(auto it:adj[node]){
                int adjnode=it;
                if(!mpp[adjnode]&&!vis[adjnode]){
                    vis[adjnode]=1;
                    q.push(adjnode);

                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i])count++;
        }
        return count;  
    }
};