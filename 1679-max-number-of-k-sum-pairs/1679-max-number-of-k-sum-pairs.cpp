class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            int rem = k - arr[i];

            if (mp[rem] > 0) {
                count++;
                mp[rem]--; 
            } else {
                mp[arr[i]]++;
            }
        }

        return count;
    }
};
