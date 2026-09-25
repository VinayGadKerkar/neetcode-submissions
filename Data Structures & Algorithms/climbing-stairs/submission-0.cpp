class Solution {
public:
    vector<int> dp;
    int solve(int i){
        if(i == 0) return 1;
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans += solve(i - 1);
        ans += solve(i - 2);
        return dp[i] = ans;
    }
    int climbStairs(int n) {
        dp.assign(n + 1 , -1);
        return solve(n);
    }
};
