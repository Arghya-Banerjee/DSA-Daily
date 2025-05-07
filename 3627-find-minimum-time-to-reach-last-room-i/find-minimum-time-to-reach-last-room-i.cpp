#define ll long long

class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int minTimeToReach(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MAX));
        priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;
        dp[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto [currTime, pos] = pq.top();
            int x = pos.first;
            int y = pos.second;
            pq.pop();
            if (currTime > dp[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    ll temp = max((ll)arr[newX][newY], currTime) + 1;
                    if (temp < dp[newX][newY]) {
                        dp[newX][newY] = temp;
                        pq.push({temp, {newX, newY}});
                    }
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};