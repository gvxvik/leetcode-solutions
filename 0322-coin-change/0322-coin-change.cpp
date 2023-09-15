class Solution {
public:

    // int top_down(vector<int>& coins, vector<int>& dp, int amount){
    //     if(amount == 0) return 0;
    //     if(amount < 0) return INT_MAX;
    
    //     if(dp[amount] != -1) return dp[amount];

    //     int mini = INT_MAX;
    //     for(int i = 0; i < coins.size(); i++){
    //         int ans = top_down(coins, dp, amount-coins[i]);
    //         if(ans != INT_MAX) mini = min(mini, 1+ans);
    //     }

    //     dp[amount] = mini;

    //     return dp[amount];
    // }

    int bottom_up(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i < dp.size(); ++i){
            for(int j = 0; j < coins.size(); ++j){
                if((i-coins[j]) >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        // int ans = top_down(coins, dp, amount);
        int ans = bottom_up(coins, amount);

        if(ans == INT_MAX) return -1;
        return ans;
    }
};