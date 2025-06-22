class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        int total = 0;
        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                if(grid[i][j] != 0) total++; // Count fresh + rotten
            }
        }

        int d[5] = {1, 0, -1, 0, 1};
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            cnt++;
            maxi = max(maxi, time);

            for(int i = 0; i < 4; i++) {
                int nrow = row + d[i];
                int ncol = col + d[i+1];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                   grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        return (cnt == total) ? maxi : -1;
    }
};
