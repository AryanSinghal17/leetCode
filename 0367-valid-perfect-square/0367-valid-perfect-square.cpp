class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1) return x;
        long long low = 1;
        long long high = x;
        long long ans = 1;
        while(low <= high){
            long long mid = (low+high)/2;
            if((long long)mid*mid<=x){
                ans = mid;
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
    bool isPerfectSquare(int num) {
        int n = mySqrt(num);
        return n*n == num;
    }
};