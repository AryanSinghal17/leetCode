class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        int i = l;
        int j = m + 1;
        vector<int> temp;
        while (i <= m && j <= r) {
            if (nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            } else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while (i <= m) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= r) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[i + l] = temp[i];
        }
    }
    int countPair(vector<int>& nums, int l, int m, int r) {
        int cnt = 0;
        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (m + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int l, int r) {
        int cnt = 0;
        if (l >= r)
            return cnt;
        if (l <= r) {
            int m = (l + r) / 2;
            cnt += mergeSort(nums, l, m);
            cnt += mergeSort(nums, m + 1, r);
            cnt += countPair(nums, l, m, r);
            merge(nums, l, m, r);
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = mergeSort(nums, l, r);
        return ans;
    }
};