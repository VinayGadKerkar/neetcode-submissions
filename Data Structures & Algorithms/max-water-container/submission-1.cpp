class Solution {
   public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0, maxi = 0;
        while (left < right) {
            int current_area = min(height[left], height[right]) * (right - left);
            ans = max(ans, current_area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};