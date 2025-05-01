class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<array<int,2>>> graph(n+1);
        for(auto e:edges){
            int x=e[0],y=e[1],cost=e[2];
            graph[x].push_back({y,cost});graph[y].push_back({x,cost});
        }

        priority_queue<array<int,3>,vector<array<int,3>>> pq;

        pq.push({-passingFees[0],0,0});

        vector<int> minimumTimeVisited(n+1,INT_MAX);
        while(pq.size()){
            auto [cost,node,time]=pq.top();pq.pop();
            if(minimumTimeVisited[node]<=time) continue;
            minimumTimeVisited[node]=time;

            if(node==n-1 and time<=maxTime) return -cost;

            for(auto [ne,w]:graph[node]){
                pq.push({-(-cost+passingFees[ne]),ne,time+w});
            }
        }

        return -1;
    }
};