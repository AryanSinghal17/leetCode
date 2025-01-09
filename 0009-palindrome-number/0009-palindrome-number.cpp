class Solution {
public:
    bool isPalindrome(int x) {
        
        int n = x;
        long y = 0;
        while(x > 0){
            int num = x%10;
            y = y * 10 + num;
            x = x/10;
        }
        return y == n;
        
    }
};