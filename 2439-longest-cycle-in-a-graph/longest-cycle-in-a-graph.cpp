class Solution {
public:
    vector<int>edge;
    int ans=-1;
    void dfs(int src,int prev,int &count,vector<bool>&vis,vector<bool>&recVis,vector<int>&store){
        if(edge[src]==-1) return;
        if(prev==-1) store[src]=1;
        else store[src]=store[prev]+1;
        vis[src]=true;
        recVis[src]=true;
        count++;
        
        if(vis[edge[src]]){
            if(recVis[edge[src]]){
                int x=count-store[edge[src]]+1;
                ans=max(ans,x);
            }
        }
        else dfs(edge[src],src,count,vis,recVis,store);
        recVis[src]=false;
    }
    int longestCycle(vector<int>& edges) {
        edge=edges;
        int n=edges.size();
        vector<bool>vis(n,false);
        vector<bool>recVis(n,false);
        vector<int>store(n,1);
        for(int i=0;i<n;i++){
            if(edges[i]==-1) continue;
            if(!vis[i]){
                int count=0;
                dfs(i,-1,count,vis,recVis,store);
            }
        }
        return ans;
    }
};