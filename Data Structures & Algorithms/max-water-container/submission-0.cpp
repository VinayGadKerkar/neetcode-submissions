class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0 , end = height.size() -1;
        int ans = 0, maxi; 
        while ( start <= end){
            
            if( ans < maxi){
                ans = maxi;
            }
            if(height[start] > height[end]){
                maxi = height[end] * (end - start);
                end--;
            }
            else{
                maxi = height[start] * (end - start);
                start++;
            }
            
            
        }
        return ans;
    }
};