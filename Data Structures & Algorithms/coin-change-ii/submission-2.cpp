class Solution {
   public:
    vector<vector<int>> dp;
    int solve(int amount, int index, vector<int>& coins, int target) {
        if (index >= coins.size() || amount > target) return 0;
        if (amount == target) return 1;

        if (dp[amount][index] != -1) return dp[amount][index];

        int take = solve(amount + coins[index], index, coins, target);

        int skip = solve(amount, index + 1, coins, target);

        return dp[amount][index] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        dp.assign(amount + 1, vector<int>(coins.size(), -1));
        return solve(0, 0, coins, amount);
    }
};
