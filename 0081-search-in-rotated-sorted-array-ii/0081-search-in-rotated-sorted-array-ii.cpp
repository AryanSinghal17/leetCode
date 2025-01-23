class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int low = 0;
        int end = arr.size() - 1;
        while(low<=end){
            int mid = (low+end)/2;
            if(arr[mid] == k){
                 return true;
            }
             if (arr[low] == arr[mid] && arr[mid] == arr[end]) {
                low++;
                end--;
                continue;
            }
            if(arr[low] <= arr[mid]){
                if(arr[low] <=k && arr[mid] >= k){
                    end = mid -1;
                }else{
                    low = mid+1;
                }
            }else{
                if(arr[mid] <= k && arr[end] >=k){
                    low = mid +1;
                }else{
                    end = mid -1;
                }
            }
        }
        return false;
    }
};