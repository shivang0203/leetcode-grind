class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 ) return 0;
        int low = 1;
        int high = x;
        long long  mid;
        int ans;
        while( low <= high ){
            mid = low + ( high-low )/2;
            if( mid * mid <= x && ( (mid+1) * (mid+1) ) > x ){
                ans = mid;
                break;
            }
            else if( (mid * mid) > x ) high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
};