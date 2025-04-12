class Solution {
public:
    typedef pair<int,int>P;
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        for(auto &num: barcodes) mp[num]++;
        priority_queue<P>pq;
        for(auto &p: mp) pq.push({p.second,p.first}); 
        vector<int>ans;
        while(!pq.empty()){
            int curr_num = pq.top().second;
            int curr_freq = pq.top().first;
            pq.pop();
            if(ans.size() >= 1 && ans[ans.size()-1] == curr_num){      
                if(pq.empty()) break;
                int next_num = pq.top().second;
                int next_freq = pq.top().first;
                pq.pop();
                ans.push_back(next_num);
                if(next_freq-1 > 0) pq.push({next_freq-1, next_num});
                pq.push({curr_freq, curr_num});
            }
            else{ 
                ans.push_back(curr_num);
                if(curr_freq-1 > 0) pq.push({curr_freq-1, curr_num});
            }
        }
        return ans;
    }
};