class Solution {
public:
    bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

  long long num = 1;
    while (num <= n) {
        if (num == n) return true;
        num = num * 2;
    }
    return false;
    }
};