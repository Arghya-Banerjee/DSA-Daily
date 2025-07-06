class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 0; cap <= 2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max({profit, -prices[ind] + next[false][cap], next[buy][cap]});
                    }
                    else{
                        if(cap > 0){
                            profit = max({profit, prices[ind] + next[true][cap-1], next[buy][cap]});
                        }
                        else profit = max(profit, next[buy][cap]);
                    }
                    curr[buy][cap] = profit;
                }
                next = curr;
            }
        }
        return next[true][2];
    }
};