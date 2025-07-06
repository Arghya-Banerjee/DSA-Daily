class Solution {
private:
    int f(int ind, vector<int> &prices, bool canBuy, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        int profit = 0;
        if(canBuy){
            profit = max({profit, -prices[ind] + f(ind+1, prices, false, dp), f(ind+1, prices, canBuy, dp)});
        }
        else{
            profit = max({profit, prices[ind] + f(ind+1, prices, true, dp), f(ind+1, prices, canBuy, dp)});
        }
        return dp[ind][canBuy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0), curr(2, 0);
        for(int ind = n-1; ind >= 0; ind--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                int profit = 0;
                if(canBuy){
                    profit = max({profit, -prices[ind] + next[0], next[canBuy]});
                }
                else{
                    profit = max({profit, prices[ind] + next[1], next[canBuy]});
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};