class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;

        rotateA(size-k,nums,size-1);
        rotateA(0,nums,size-k-1);
        rotateA(0,nums,size-1);
    }

    void rotateA(int start,vector<int>&nums,int end){
     while(start<end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
     }   
    }
};