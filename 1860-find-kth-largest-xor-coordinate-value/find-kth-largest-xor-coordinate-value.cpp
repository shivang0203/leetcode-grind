#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix,int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>xorMatrix(m,vector<int>(n, 0));
     priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    xorMatrix[i][j] = matrix[i][j];
                }else if (i == 0){
                    xorMatrix[i][j] = xorMatrix[i][j-1] ^ matrix[i][j];
                }else if (j == 0){
                    xorMatrix[i][j] = xorMatrix[i-1][j] ^ matrix[i][j];
                }else{
                    xorMatrix[i][j] = xorMatrix[i-1][j] ^ xorMatrix[i][j-1] ^ xorMatrix[i-1][j-1] ^ matrix[i][j];
                }
                if(minHeap.size() < k){
                    minHeap.push(xorMatrix[i][j]);
                }else if(xorMatrix[i][j] > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(xorMatrix[i][j]);
                }
            }
        }
        return minHeap.top();
    }


};