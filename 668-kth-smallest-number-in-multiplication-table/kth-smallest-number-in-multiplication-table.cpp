class Solution {
public:
    int sumSmallEqual(int m, int n, int val){
        int count = 0;
        for(int r=m;r>0;r--){
            int c = val/r;
            if (c < n)
                count += c;
            else 
                return count + n*r;
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        if (m > n) swap(m,n);
        int l=1, r=m*n;
        while (l<r){
            int mid = (l+r)/2;
            int count = sumSmallEqual(m,n,mid);
            if (count < k)
                l = mid+1;
            else
                 r = mid;
        }
        return l;

    }
};