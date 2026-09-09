class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            swap(nums[0] , nums[1]);
            return nums;
        }
        vector<int> leftProduct(n , 1) , rightProduct(n , 1);
        leftProduct[0] = nums[0];
        rightProduct[n - 1] = nums[n - 1];
        for(int i = 1 ; i < n ; i++){
            leftProduct[i] = nums[i] * leftProduct[i - 1];
            rightProduct[n - i - 1] = nums[n - i - 1] * rightProduct[n - i];
        }
        nums[0] = rightProduct[1];
        nums[n - 1] = leftProduct[n - 2];
        for(int i = 1 ; i < n - 1 ; i++){
            nums[i] = leftProduct[i - 1] * rightProduct[i + 1];
        }
        return nums;
    }
};
