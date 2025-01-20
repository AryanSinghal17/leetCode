class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if (arr.size() < 2)
            return 0;
        int buy = arr[0];
        int profit = 0;
        for (int i = 1; i < arr.size(); i++) {
            if(arr[i] < buy){
                buy = arr[i];
            }else if(arr[i] - buy > profit){
                profit = arr[i] - buy;
            }
        }
        return profit;
    }
};