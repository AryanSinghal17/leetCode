class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if (arr.size() < 2) return 0;
        int mini = arr[0];
        int profit = 0;
        for(int i = 1;i<arr.size();i++){
            int cost = arr[i] - mini;
            profit = max(profit,cost);
            mini = min(mini,arr[i]);
        }
    return profit;
    }
};