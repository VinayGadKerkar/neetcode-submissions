class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int rightMax = INT_MIN , leftMax = INT_MIN;
        int left = 0 , right = n - 1;
        int water = 0;
        while(left <= right){
            if(height[left] > height[right]){
                rightMax = max(rightMax , height[right]);
                water += rightMax - height[right--];
            }else{
                leftMax = max(leftMax , height[left]);
                water += leftMax - height[left++];
            }
        }
        return water;
    }
};
