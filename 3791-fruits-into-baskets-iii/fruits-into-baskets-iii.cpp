class Solution {
public:
    int block_sz;
    vector<int> a, block, vis;

    void preprocess(int n){
        vis.resize(n, 0);
        block_sz = sqrt(n);
        block.resize(n/block_sz+1, 0);
        int cnt = -1;
        for(int i = 0; i < n; i++){
            if(i % block_sz == 0)
                cnt++;
            block[cnt] = max(block[cnt], a[i]);
        }
    }

    bool query(int idx, int x){
        for(int i = 0; i < block.size(); i++){
            if(x > block[i]) continue; 
            int j = i*block_sz;
            while(true){
                if(x > a[j] || vis[j]){
                    j++;
                    continue;
                }
                vis[j] = 1;
                break;
            }
            update(i);
            return true;
        }
        return false;
    }
    
    void update(int idx){
        block[idx] = 0;
        int limit = min((int)a.size(), idx*block_sz+block_sz);
        for(int i = idx*block_sz; i < limit; i++){
            if(vis[i]) continue; 
            block[idx] = max(block[idx], a[i]);
        }
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->a = baskets;
        int n = fruits.size();
        preprocess(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!query(i, fruits[i]))
                ans++;
        }
        return ans;
    }
};