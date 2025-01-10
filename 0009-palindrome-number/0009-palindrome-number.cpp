class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        long y = 0;
        while(x > 0){
            int n = x%10;
            y = y*10 +n;
            x =x/10;
        }
        return num == y;
    }
};