class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(202, vector<int>(202, 0));
        for(int i = 0; i < n; i++){
            int sz = triangle[i].size();
            for(int j = 0; j < sz; j++){
                if(i == 0 && j == 0) dp[i][j] = triangle[i][j];
                else if(j == sz-1) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                else{
                    int up = INT_MAX, diag = INT_MAX;
                    if(i > 0) up = dp[i-1][j];
                    if(i > 0 && j > 0) diag = dp[i-1][j-1];
                    dp[i][j] = triangle[i][j] + min(up, diag);
                }
                // cout <<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < triangle[n-1].size(); i++) mini = min(mini, dp[n-1][i]);
        return mini;
    }
};