class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0 , right = 1;
        int maxProfit = 0;
        while(right < n){
            if(prices[left] < prices[right]){
                maxProfit = max(maxProfit , prices[right] - prices[left]);
            }else{
                left = right;
            }
            right++;
        }
        return maxProfit;
    }
};
